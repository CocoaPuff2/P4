#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map> // For hashtable
#include <vector>        // For storing movies and transactions

#include "customer.h"
#include "movie.h"
#include "store.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "transaction.h"
#include "borrowmedia.h"
#include "returnmedia.h"


using namespace std;
// todo: need to print all F, D, then C after putting them in BST

Store::Store() {

}
Store::~Store() {
        /*
        for (Movie* movie : movies) {
            delete movie; // Deletes each dynamically allocated movie
        }
         */
}

// reading methods to read the files
// Reads movie data from a given input file and populates the movie inventory.
void Store::readMovie(ifstream& file){
    string line;
    while (getline(file, line)) {
        Movie* movie = createMovie(line);  // Create movie using the factory method

        if (movie) {
            char genre = movie->getGenre();  // Get genre ('F', 'D', or 'C')

            // If the BST for this genre doesn't exist, create it
            if (movieInventory.find(genre) == movieInventory.end()) {
                movieInventory[genre] = new BST();
            }

            // Insert the movie into the appropriate BST
            movieInventory[genre]->insert(movie);
        }

    }
}

// todo check factory method
Movie* Store::createMovie(const string& line) {
        stringstream ss(line);
        char genre;
        int stock;
        string director;
        string title;
        int year;
        char mediaType;

        ss >> genre;  // Read genre
        ss.ignore();  // Skip comma and space

        ss >> stock;  // Read stock
        ss.ignore();  // Skip comma and space

        getline(ss, director, ',');  // Read director
        ss.ignore();  // Skip space

        getline(ss, title, ',');  // Read title
        ss.ignore();  // Skip space

        mediaType = 'D';

        // Create movie objects based on genre
    switch (genre) {
        case 'F': {  // Comedy
            ss >> year;
            return new Comedy(genre, stock, director, title, year, mediaType);
        }
        case 'D': {  // Drama
            ss >> year;
            return new Drama(genre, stock, director, title, year, mediaType);
        }
        case 'C': {  // Classics
            string majorActorFirstName, majorActorLastName;
            int releaseMonth;

            ss >> majorActorFirstName >> majorActorLastName;
            ss >> releaseMonth >> year;

            return new Classics(genre, stock, director, title, majorActorFirstName, majorActorLastName, releaseMonth, year,  mediaType);
        }
        default:
            cout << "ERROR: " << genre << " Invalid Genre. Skipping line." << endl;
            return nullptr;
    }
}

void Store::displayAllMovies() const {
    if (movieInventory.find('F') != movieInventory.end()) {
        movieInventory.at('F')->inOrderTraversal();  // Inorder traversal for Comedy BST
    }

    // Display Drama movies (D)
    if (movieInventory.find('D') != movieInventory.end()) {
        movieInventory.at('D')->inOrderTraversal();  // Inorder traversal for Drama BST
    }

    // Display Classic movies (C)
    if (movieInventory.find('C') != movieInventory.end()) {
        movieInventory.at('C')->inOrderTraversal();  // Inorder traversal for Classic BST
    }
}


int Store::hashFunction(int customerID) {
    return customerID % MAX_CUSTOMERS;
}

// Reads customer data from a given input file and adds customers to the hash table.
void Store::readCustomers(ifstream& file) {
    string line;
    while (getline(file, line)) {
        stringstream ss(line);  // Use stringstream to parse the line
        int customerID;
        string firstName, lastName;

        // Read customer data (format: customerID firstName lastName)
        ss >> customerID >> firstName >> lastName;
        // Create a Customer object
        Customer *customer = new Customer(customerID, firstName, lastName);

        // Insert the customer into the hash table
        insertCustomer(customer);
    }
}

void Store::insertCustomer(Customer* customer) {
    // hash function: id mod max customer  (gets the key for the buckets)
    // ll for each bucket
    // insert the customer into the LL
    int index = hashFunction(customer->getCustomerID());  // Hash, find bucket
    LinkedListNode* newNode = new LinkedListNode(customer);

    // If no customer exists at that index, initialize  linked list (LL) at that index
    if (customerTable[index] == nullptr) {
        customerTable[index] = newNode;
    } else {
        // Add new customer to the front of LL
        newNode->next = customerTable[index];
        customerTable[index] = newNode;
    }
}



// Reads commands from an input file and processes them (borrow, return, history)
void Store::readCommands(ifstream& file) {
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char command;
        int customerID;
        ss >> command;  // Read the command type

        if (command == 'B' || command == 'R') {
            char mediaType;
            char genre;
            ss >> customerID >> mediaType >> genre;  // Get customerID, media type (e.g., 'D'), and movie genre

            // Now, read the remaining line as the movie details (title, director, etc.)
            string movieDetails;
            getline(ss, movieDetails); // Get the movie details as a string

            // Borrowing or Returning the movie (Use movie ID to look up the movie)
            if (command == 'B') {
                borrowMovie(customerID, genre, movieDetails);
            } else if (command == 'R') {
                // returnMovie(customerID, movieID);
            }

        } else if (command == 'H') {
            ss >> customerID;
            // TODO
        } else if (command == 'I') {
            displayAllMovies();

        } else {
            cout << "ERROR: " << command << " Invalid Genre. Try Again.\n" << endl;
        }
    }
}


// manage transactions

void Store::borrowMovie(int customerID, char genre, string movieDetails) {
    // 1. Look up movie by genre
    if (movieInventory.find(genre) == movieInventory.end()) {
        cout << "Genre not found!" << endl;
        return;
    }

    // 2. First see if customer exists, find index of bucket and then check LL
    Customer* customer = nullptr;
    int hashKey = hashFunction(customerID);  // Get  bucket index
    LinkedListNode* node = customerTable[hashKey];

    // Traverse linked list to find the customer
    while (node) {
        if (node->customer->getCustomerID() == customerID) {
            customer = node->customer;
            break;
        }
        node = node->next;
    }

    if (!customer) {
        cout << "Borrow Transaction Failed -- Customer " << customerID << " does not exist." << endl;
        return;
    }

    // Step 3: Find the movie in the BST based on movieDetails
    BST* genreBST = movieInventory[genre];
    Movie* movie = nullptr;

    // Use search method to find the movie based on the movieDetails
    if (genre == 'F') {  // Comedy
        string title = movieDetails.substr(0, movieDetails.find(' '));
        int year = stoi(movieDetails.substr(movieDetails.find(' ') + 1));
        Movie* tempMovie = new Comedy('F', 0, "", title, year, 'D');  // Creating a temp Movie object for Comedy
        movie = genreBST->search(tempMovie);
        delete tempMovie;  // Clean up temporary Movie object
        // movie = genreBST->search(movieDetails);  // movieDetails is a {title, year} pair
    } else if (genre == 'D') {  // Drama
        string director = movieDetails.substr(0, movieDetails.find(' '));
        string title = movieDetails.substr(movieDetails.find(' ') + 1);
        Movie* tempMovie = new Drama('D', 0, director, title, 0, 'D');  // Creating a temp Movie object for Drama
        movie = genreBST->search(tempMovie);
        delete tempMovie;
        // movie = genreBST->search(movieDetails);  // movieDetails is a {director, title} pair
    } else if (genre == 'C') {  // Classic
        string month = movieDetails.substr(0, movieDetails.find(' '));
        string remaining = movieDetails.substr(movieDetails.find(' ') + 1);
        int year = stoi(remaining.substr(0, remaining.find(' ')));
        string actor = remaining.substr(remaining.find(' ') + 1);
        string firstName = actor.substr(0, actor.find(' '));
        string lastName = actor.substr(actor.find(' ') + 1);

        Movie* tempMovie = new Classics('C', 0, "", "", firstName, lastName, stoi(month), year, 'D');  // Creating a temp Movie object for Classic
        movie = genreBST->search(tempMovie);
        delete tempMovie;
        // movie = genreBST->search(movieDetails);  // movieDetails is a {month, year, actor} triplet
    }

    if (!movie) {
        cout << "Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
        return;
    }

    // Step 4: Check if the movie is in stock (stock > 0)
    if (movie->getStock() <= 0) {
        cout << "Borrow Transaction Failed -- Not enough in the Stock." << endl;
        return;
    }

    // Step 5: Decrease stock and create a transaction
    movie->decreaseStock();  // Decrease stock by 1
    // TODO: INSTEAD OF THE STRING, ADD THE SUBCLASS BORROW OR RETURN
    Transaction* transaction = new BorrowMedia(movie);

    // Step 6: Add transaction to the customer's history
    customer->addTransaction(transaction);
}

void Store::returnMovie(int customerID, char genre, string movieDetails) {
    // 1. Look up movie by genre
    if (movieInventory.find(genre) == movieInventory.end()) {
        cout << "Genre not found!" << endl;
        return;
    }

    // 2. First see if customer exists, find index of bucket and then check LL
    Customer* customer = nullptr;
    int hashKey = hashFunction(customerID);  // Get  bucket index
    LinkedListNode* node = customerTable[hashKey];

    // Traverse linked list to find the customer
    while (node) {
        if (node->customer->getCustomerID() == customerID) {
            customer = node->customer;
            break;
        }
        node = node->next;
    }

    if (!customer) {
        cout << "Return Transaction Failed -- Customer " << customerID << " does not exist." << endl;
        return;
    }

    // Step 3: Find the movie in the BST based on movieDetails
    BST* genreBST = movieInventory[genre];
    Movie* movie = nullptr;

    // Use search method to find the movie based on the movieDetails
    if (genre == 'F') {  // Comedy
        string title = movieDetails.substr(0, movieDetails.find(' '));
        int year = stoi(movieDetails.substr(movieDetails.find(' ') + 1));
        Movie* tempMovie = new Comedy('F', 0, "", title, year, 'D');  // Creating a temp Movie object for Comedy
        movie = genreBST->search(tempMovie);
        delete tempMovie;  // Clean up temporary Movie object
        // movie = genreBST->search(movieDetails);  // movieDetails is a {title, year} pair
    } else if (genre == 'D') {  // Drama
        string director = movieDetails.substr(0, movieDetails.find(' '));
        string title = movieDetails.substr(movieDetails.find(' ') + 1);
        Movie* tempMovie = new Drama('D', 0, director, title, 0, 'D');  // Creating a temp Movie object for Drama
        movie = genreBST->search(tempMovie);
        delete tempMovie;
        // movie = genreBST->search(movieDetails);  // movieDetails is a {director, title} pair
    } else if (genre == 'C') {  // Classic
        string month = movieDetails.substr(0, movieDetails.find(' '));
        string remaining = movieDetails.substr(movieDetails.find(' ') + 1);
        int year = stoi(remaining.substr(0, remaining.find(' ')));
        string actor = remaining.substr(remaining.find(' ') + 1);
        string firstName = actor.substr(0, actor.find(' '));
        string lastName = actor.substr(actor.find(' ') + 1);

        Movie* tempMovie = new Classics('C', 0, "", "", firstName, lastName, stoi(month), year, 'D');  // Creating a temp Movie object for Classic
        movie = genreBST->search(tempMovie);
        delete tempMovie;
        // movie = genreBST->search(movieDetails);  // movieDetails is a {month, year, actor} triplet
    }

    if (!movie) {
        cout << "Return Transaction Failed -- Movie does not Exist in the Inventory" << endl;
        return;
    }

    // Step 4: Check if the movie is in stock (stock > 0)
    if (movie->getStock() <= 0) {
        cout << "Return Transaction Failed -- Not enough in the Stock." << endl;
        return;
    }

    // Step 5: Increase stock and create a transaction
    movie->increaseStock();  // Increase stock by 1
    Transaction* transaction = new ReturnMedia(movie);

    // Step 6: Add transaction to the customer's history
    customer->addTransaction(transaction);
}

// Display transaction history for a customer
void Store::displayHistory(int customerID) {
    // Search for the customer in the hash table or database
    Customer* customer = findCustomerByID(customerID);  // Assuming findCustomerByID is implemented

    // If customer exists, display their transaction history
    if (customer != nullptr) {
        cout << "Transaction history for " << customer->getFullName() << " (ID: " << customer->getCustomerID() << "):\n";
        customer->displayHistory();  // Call the displayHistory method of the Customer class
    } else {
        // If customer is not found, print an error message
        cout << "Customer  " << customerID << " not found." << endl;
    }
}


// Add a new transaction to the transaction history
void Store::addTransaction(Transaction* transaction) {

}

// Utility methods
// Help the Store class interact with the movie and customer data structures
//  BST for movies, Hashtable for customers
Movie* Store::findMovieByID(int movieID) { // Find a movie by its ID
}

Customer* Store::findCustomerByID(int customerID) { // Find a customer by their ID
}
