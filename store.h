#ifndef MY_EXECUTABLE_STORE_H
#define MY_EXECUTABLE_STORE_H
/*
 * Reads files, manages transactions, and stores movies and customers.
 * Manages the details so main() doesn't need to know subclasses
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map> // For hashtable
#include <vector>        // For storing movies and transactions
#include "customer.h"
#include "movie.h"
#include "transaction.h"
#include "borrowmedia.h"
#include "returnmedia.h"

using namespace std;
class Store {
protected:
    unordered_map<int, Customer*> customers;   // Hashtable for storing customers
    // hashtable for movies, each bucket points to a BST

public:
    Store();
    ~Store();


    // reading methods to read the files
    // Reads movie data from a given input file and populates the movie inventory.
    void readMovie(ifstream& file);
    // Reads customer data from a given input file and adds customers to the hash table.
    void readCustomers(ifstream& file);
    // Reads commands from an input file and processes them (borrow, return, history)
    void readCommands(ifstream& file);

    // storing methods

    // manage transactions
    void borrowMovie(int customerID, int movieID);
    void returnMovie(int customerID, int movieID);

    // Display transaction history for a customer
    void displayHistory(int customerID);

    // Add a new transaction to the transaction history
    void addTransaction(Transaction* transaction);

    // Utility methods
    //  Help the Store class interact with the movie and customer data structures
    //  BST for movies, Hashtable for customers
    Movie* findMovieByID(int movieID); // Find a movie by its ID
    Customer* findCustomerByID(int customerID); // Find a customer by their ID
};





#endif //MY_EXECUTABLE_STORE_H
