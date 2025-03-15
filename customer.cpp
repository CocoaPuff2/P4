#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "customer.h"
#include "borrowmedia.h"

using namespace std;

// constructor
Customer::Customer() {
    customerID = 0000;
    firstName = " ";
    lastName = " ";

}

// param constructor

Customer::Customer(int id, const string& last, const string& first)
        : customerID(id), lastName(last), firstName(first), transactions() {  // Initialize an empty vector
    // transactions() automatically invoked to initialize the vector as empty.
}


// destructor
Customer::~Customer() {
    for (auto t : transactions) {
        delete t;
    }
}

// getters
int Customer::getCustomerID() const { return customerID;}
string Customer::getFullName() { return firstName + " " + lastName; }
string Customer::getFirst() { return firstName; }
string Customer::getLast() { return lastName; }

bool Customer::hasBorrowed(Movie* movie) {
    for (Transaction* t : transactions) {
        if (dynamic_cast<BorrowMedia*>(t) && t->getMovie() == movie) {
            return true;
        }
    }
    return false;
}

void Customer::removeBorrowed(Movie* movie) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (dynamic_cast<BorrowMedia*>(*it) && (*it)->getMovie() == movie) {
            delete *it;  // Free memory
            transactions.erase(it);  // Remove from history
            return;
        }
    }
}






void Customer::addTransaction(Transaction* transaction) {
    // Add transaction to the vector
     transactions.push_back(transaction);
}

// Displays the full transaction history for customer.
void Customer::displayHistory() const {
    cout << "History for " << firstName << " " << lastName << ": " << endl;
    // Print transactions in chronological order
    for (auto it = transactions.rbegin(); it != transactions.rend(); ++it) {
        if (*it) {
            (*it)->displayTransaction();  // Call displayTransaction on each transaction
        } else {
            std::cout << "Invalid transaction." << std::endl;
        }
    }
     cout << endl;

}
