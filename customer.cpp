#include <string>
#include <iostream>
#include <vector>
#include "customer.h"

using namespace std;

// constructor
Customer::Customer() {
    customerID = 0000;
    firstName = " ";
    lastName = " ";

}

// param constructor

Customer::Customer(int id, const string& first, const string& last)
        : customerID(id), firstName(first), lastName(last), transactions() {  // Initialize an empty vector
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
    cout << "History for " << firstName << " " << lastName << ": " << endl;
    // Optional method to display the transactions for a customer
     for (const auto& transaction : transactions) {
        // Assuming Transaction has a method to display its details
         transaction->displayTransaction();  // You may need to implement a display method in Transaction class
 }
}
