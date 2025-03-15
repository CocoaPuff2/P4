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
#include "bst.cpp"
#include "transaction.h"
#include "borrowmedia.h"
#include "returnmedia.h"

using namespace std;
const int MAX_CUSTOMERS = 100;

struct LinkedListNode {
    LinkedListNode* next;
    Customer* customer;
    LinkedListNode(Customer* customer) : customer(customer), next(nullptr) {}
};


class Store {
protected:
    LinkedListNode* customerTable[MAX_CUSTOMERS]; // Hashtable for storing customers
    unordered_map<char, BST*> movieInventory; // Hash table storing BSTs for each genre


public:
    Store();
    ~Store();

    // reading methods to read the files
    // Reads movie data from a given input file and populates the movie inventory.
    void readMovie(ifstream& file);

    // FACTORY METHOD to easily create and add new movies
    Movie* createMovie(const string& line);

    // for the output file
    void displayAllMovies() const;


    // Reads customer data from a given input file and adds customers to the hash table.
    void readCustomers(ifstream& file);
    int hashFunction(int customerID);
    void insertCustomer(Customer* customer);

    // Reads commands from an input file and processes them (borrow, return, history)
    void readCommands(ifstream& file);
    bool checkMedia(char mediaType);

    // manage transactions
    void borrowMovie(int customerID, char genre, string movieDetails);

    void returnMovie(int customerID, char genre, string movieDetails);
};


#endif //MY_EXECUTABLE_STORE_H
