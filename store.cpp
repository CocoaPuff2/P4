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
    cout << "YAY" << endl;
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
                 returnMovie(customerID, genre, movieDetails);
            }

        } else if (command == 'H') {
            ss >> customerID;
            // TODO go thru the hashtable of customers, find the customer id that matches with the
            //  input for customerID and print that customer's transactions vector using displayTransactions
            // Step 1: Use the hash function to find the index in the customerTable array
            int index = hashFunction(customerID);

            // Step 2: Traverse the linked list at the corresponding index
            LinkedListNode* current = customerTable[index];

            // Step 3: Search for the customer with the matching customerID
            while (current != nullptr) {
                if (current->customer->getCustomerID() == customerID) {  // Found the customer
                    current->customer->displayHistory();  // Call displayHistory() on the customer to print their transactions
                    break;
                }
                current = current->next;  // Move to the next customer in the linked list
            }

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
        cout << "ERROR: " << genre << " Invalid Genre. Try Again" << endl;
        return;
    }

    // 2. First see if customer exists, find index of bucket and then check LL
    Customer* customer = nullptr;
    int hashKey = hashFunction(customerID);  // Get  bucket index
    LinkedListNode* node = customerTable[hashKey];

    if (!node) {
       return;
    }

    // Traverse linked list to find the customer
    while (node) {
        if (node->customer && node->customer->getCustomerID() == customerID) {
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
        size_t startPos = movieDetails.find_first_not_of(" ");  // Find the first non-space character
        movieDetails = movieDetails.substr(startPos);  // Remove leading spaces

        // Find the position of the comma
        size_t commaPos = movieDetails.find(',');

        // Extract the title (everything before the comma)
        string title = movieDetails.substr(0, commaPos);

        // Extract the year (everything after the comma)
        int year = stoi(movieDetails.substr(commaPos + 2));  // Skip the comma and the space after it

        // Create a temp Movie object for Comedy
        Movie* tempMovie = new Comedy('F', 0, "", title, year, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;  // Clean up temporary Movie object
    } else if (genre == 'D') {  // Drama
        size_t commaPos = movieDetails.find(", ");  // Find the comma-space separator

        // Extract director (everything before the comma)
        string director = movieDetails.substr(0, commaPos);

        // Extract title (everything after the comma + space)
        string title = movieDetails.substr(commaPos + 2);

        // Remove any trailing '\r' or comma from the title
        while (!title.empty() && (title.back() == '\r' || title.back() == ',')) {
            title.pop_back();  // Remove last character if it's '\r' or ','
        }

        // Create a temp Movie object for Drama
        Movie* tempMovie = new Drama('D', 0, director, title, 0, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;
    } else if (genre == 'C') {  // Classic
        // Trim any leading spaces before the month
        size_t startPos = movieDetails.find_first_not_of(" ");
        movieDetails = movieDetails.substr(startPos);

        // Extract the month (first space-separated value)
        size_t firstSpace = movieDetails.find(' ');
        string month = movieDetails.substr(0, firstSpace);

        // Extract the remaining part after the month
        string remaining = movieDetails.substr(firstSpace + 1);

        // Extract the year (next space-separated value)
        size_t secondSpace = remaining.find(' ');
        int year = stoi(remaining.substr(0, secondSpace));

        // Extract the actor's full name (firstName + lastName)
        string actor = remaining.substr(secondSpace + 1);

        // Find the space between first and last name
        size_t nameSpace = actor.find(' ');
        string firstName = actor.substr(0, nameSpace);
        string lastName = actor.substr(nameSpace + 1);

        // Remove any trailing '\r' from the last name
        if (!lastName.empty() && lastName.back() == '\r') {
            lastName.pop_back();
        }

        // Create a temp Movie object for Classics
        Movie* tempMovie = new Classics('C', 0, "", "", firstName, lastName, stoi(month), year, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;
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
    Transaction* transaction = new BorrowMedia(movie, customerID);

    // Step 6: Add transaction to the customer's history
    cout << "borrow add " << movie->getTitle() << endl;
    customer->addTransaction(transaction);
}

void Store::returnMovie(int customerID, char genre, string movieDetails) {
    // 1. Look up movie by genre
    if (movieInventory.find(genre) == movieInventory.end()) {
        cout << "ERROR: " << genre << " Invalid Genre. Try Again" << endl;
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
        size_t startPos = movieDetails.find_first_not_of(" ");  // Find the first non-space character
        movieDetails = movieDetails.substr(startPos);  // Remove leading spaces

        // Find the position of the comma
        size_t commaPos = movieDetails.find(',');

        // Extract the title (everything before the comma)
        string title = movieDetails.substr(0, commaPos);

        // Extract the year (everything after the comma)
        int year = stoi(movieDetails.substr(commaPos + 2));  // Skip the comma and the space after it

        // Create a temp Movie object for Comedy
        Movie* tempMovie = new Comedy('F', 0, "", title, year, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;  // Clean up temporary Movie object
    } else if (genre == 'D') {  // Drama
        size_t commaPos = movieDetails.find(", ");  // Find the comma-space separator

        // Extract director (everything before the comma)
        string director = movieDetails.substr(0, commaPos);

        // Extract title (everything after the comma + space)
        string title = movieDetails.substr(commaPos + 2);

        // Remove any trailing '\r' or comma from the title
        while (!title.empty() && (title.back() == '\r' || title.back() == ',')) {
            title.pop_back();  // Remove last character if it's '\r' or ','
        }

        // Create a temp Movie object for Drama
        Movie* tempMovie = new Drama('D', 0, director, title, 0, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;
    } else if (genre == 'C') {  // Classic
        // Trim any leading spaces before the month
        size_t startPos = movieDetails.find_first_not_of(" ");
        movieDetails = movieDetails.substr(startPos);

        // Extract the month (first space-separated value)
        size_t firstSpace = movieDetails.find(' ');
        string month = movieDetails.substr(0, firstSpace);

        // Extract the remaining part after the month
        string remaining = movieDetails.substr(firstSpace + 1);

        // Extract the year (next space-separated value)
        size_t secondSpace = remaining.find(' ');
        int year = stoi(remaining.substr(0, secondSpace));

        // Extract the actor's full name (firstName + lastName)
        string actor = remaining.substr(secondSpace + 1);

        // Find the space between first and last name
        size_t nameSpace = actor.find(' ');
        string firstName = actor.substr(0, nameSpace);
        string lastName = actor.substr(nameSpace + 1);

        // Remove any trailing '\r' from the last name
        if (!lastName.empty() && lastName.back() == '\r') {
            lastName.pop_back();
        }

        // Create a temp Movie object for Classics
        Movie* tempMovie = new Classics('C', 0, "", "", firstName, lastName, stoi(month), year, 'D');
        movie = genreBST->search(tempMovie);
        delete tempMovie;
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
    Transaction* transaction = new ReturnMedia(movie, customerID);

    // Step 6: Add transaction to the customer's history
    cout << "return add " << movie->getTitle() << endl;
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
    // Step 1: Get the customer ID from the transaction
    int customerID = transaction->getCustomerID();
    cout << "Hooooo" << endl;

    // Step 2: Find the customer using the customer ID
    Customer* customer = findCustomerByID(customerID);

    // Step 3: If customer is found, add the transaction to the customer's history
    if (customer) {
        customer->addTransaction(transaction);  // Calls the Customer's addTransaction method
    } else {
        cout << "Customer with ID " << customerID << " not found." << endl;
    }
}

// Utility methods
// Help the Store class interact with the movie and customer data structures
//  BST for movies, Hashtable for customers
Movie* Store::findMovieByID(int movieID) { // Find a movie by its ID
}

Customer* Store::findCustomerByID(int customerID) { // Find a customer by their ID
}
