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


Store::Store() {

}
Store::~Store() {
        /*
        for (Movie* movie : movies) {
            delete movie; // Deletes each dynamically allocated movie
        }
         */
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
            return new Comedy(genre, stock, director, title, year,  mediaType);
        }
        case 'D': {  // Drama
            ss >> year;
            return new Drama(genre, stock, director, title, year,  mediaType);
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


// Reads customer data from a given input file and adds customers to the hash table.
void Store::readCustomers(ifstream& file) {}

// Reads commands from an input file and processes them (borrow, return, history)
void Store::readCommands(ifstream& file) {
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char command;
        int customerID;
        ss >> command;  // Read the command type

        if (command == 'B' || command == 'R') {
            char genre;
            int movieType;

            ss >> genre; // Get movie genre
            ss >> customerID;  // Get the specific movie ID

            // Borrowing or Returning the movie (Use movie ID to look up the movie)
            if (command == 'B') {
                borrowMovie(customerID, movieType);
            } else if (command == 'R') {
                // returnMovie(customerID, movieID);
            }

        } else if (command == 'H') {
            ss >> customerID;
            displayHistory(customerID);
        } else if (command == 'I') {

            // TODO: Implement printing history for ALL customers, go thru HT

        } else {
            cout << "ERROR: " << command << " Invalid Genre. Try Again.\n" << endl;
        }
    }
}


// manage transactions
void Store::borrowMovie(int customerID, char mediaType, char genre, string movieDetails) {
    Movie* movie = nullptr;

}
void Store::returnMovie(int customerID, int movieID) {}

// Display transaction history for a customer
void Store::displayHistory(int customerID) {
    //todo Implementation
}


// Add a new transaction to the transaction history
void Store::addTransaction(Transaction* transaction) {}

// Utility methods
// Help the Store class interact with the movie and customer data structures
//  BST for movies, Hashtable for customers
Movie* Store::findMovieByID(int movieID) { // Find a movie by its ID
}

Customer* Store::findCustomerByID(int customerID) { // Find a customer by their ID
}
