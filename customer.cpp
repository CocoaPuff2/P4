#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "customer.h"

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

/*
Customer::Customer(int customerID, const string& firstName, const string& lastName)
        : customerID(customerID), firstName(firstName), lastName(lastName) {
    // nextCustomer = nullptr;
    startTransaction = nullptr;
}
 */


// destructor
// todo
Customer::~Customer() {

}

// getters
int Customer::getCustomerID() const { return customerID; }
string Customer::getFullName() { return firstName + " " + lastName; }
string Customer::getFirst() { return firstName; }
string Customer::getLast() { return lastName; }

void Customer::addTransaction(Transaction* transaction) {
    // Add transaction to the vector
     transactions.push_back(transaction);
}

// Displays the full transaction history for customer.
void Customer::displayHistory() const {
    //cout << "History for " << firstName << " " << lastName << ": " << endl;
    // Sort transactions based on the genre and movie-specific sorting rules

     for (const auto& transaction : transactions) {
         if (transaction) {
             transaction->displayTransaction();
         } else {
             std::cout << "Invalid transaction." << std::endl;
         }
 }

}
