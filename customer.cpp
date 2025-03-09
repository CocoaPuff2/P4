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
Customer::Customer(int customerID, const string& firstName, const string& lastName)
        : customerID(customerID), firstName(firstName), lastName(lastName) {
    // nextCustomer = nullptr;
    startTransaction = nullptr;
}

// destructor
// todo

// getters
int Customer::getCustomerID() const { return customerID; }
string Customer::getFullName() { return firstName + " " + lastName; }
string Customer::getFirst() { return firstName; }
string Customer::getLast() { return lastName; }

// setters

// Displays the full transaction history for customer.
void Customer::displayHistory() const {
    cout << "History for " << firstName << " " << lastName << ": " << endl;
    // todo: will go thru the LL of the customer and print transactions
    // Borrowed Harold and Maude by Hal Ashby
    // Returned Harold and Maude by Hal Ashby
}
