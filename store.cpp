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
#include "bst.cpp"
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
Movie* createMovie(const string& line) {
        stringstream ss(line);
        char genre;
        int stock;
        string director;
        string title;
        int year;
        char mediaType;

        ss >> genre;  // input genre
        ss.ignore();  // Skip comma after genre

        // Create movie objects based on genre
        switch (genre) {
            case 'F': {  // Comedy
                if (getline(ss, director, ',') &&
                    getline(ss, title, ',') &&
                    ss >> year &&
                    ss.ignore() &&
                    ss >> stock &&
                    ss.ignore() &&
                    ss >> mediaType) {
                    return new Comedy(genre, stock, director, title, year, mediaType);
                }
                break;
            }
            case 'D': {  // Drama
                if (getline(ss, director, ',') &&
                    getline(ss, title, ',') &&
                    ss >> year &&
                    ss.ignore() &&
                    ss >> stock &&
                    ss.ignore() &&
                    ss >> mediaType) {
                    return new Drama(genre, stock, director, title, year, mediaType);
                }
                break;
            }
            case 'C': {  // Classics
                string majorActorFirstName, majorActorLastName;
                int releaseMonth;
                if (getline(ss, director, ',') &&
                    getline(ss, title, ',') &&
                    ss >> majorActorFirstName &&
                    ss >> majorActorLastName &&
                    ss >> releaseMonth &&
                    ss >> year &&
                    ss.ignore() &&
                    ss >> stock &&
                    ss.ignore() &&
                    ss >> mediaType) {
                    return new Classics(genre, stock, director, title, majorActorFirstName, majorActorLastName, releaseMonth, year, mediaType);
                }
                break;
            }
            default:
                cout << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
                return nullptr;
        }

        return nullptr;  //  nullptr if invalid format
}
// reading methods to read the files
// Reads movie data from a given input file and populates the movie inventory.
void Store::readMovie(ifstream& file){
    string line;
    while (getline(file, line)) {
        // Parse  line to extract movie data
        stringstream ss(line);
        string title, director, genre;
        int year, stock;
        char mediaType;  // New member for media type (e.g., 'C' for Classics, 'D' for DVD)

    }
}


// Reads customer data from a given input file and adds customers to the hash table.
void Store::readCustomers(ifstream& file) {}
// Reads commands from an input file and processes them (borrow, return, history)
void readCommands(ifstream& file) {}

// storing methods

// manage transactions
void borrowMovie(int customerID, int movieID) {}
void returnMovie(int customerID, int movieID) {}

// Display transaction history for a customer
void displayHistory(int customerID) {
    // todo calls the customer display history
}

// Add a new transaction to the transaction history
void addTransaction(Transaction* transaction) {}

// Utility methods
// Help the Store class interact with the movie and customer data structures
//  BST for movies, Hashtable for customers
Movie* findMovieByID(int movieID) { // Find a movie by its ID
}

Customer* findCustomerByID(int customerID) { // Find a customer by their ID
}
