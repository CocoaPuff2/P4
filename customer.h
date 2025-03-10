
#ifndef MY_EXECUTABLE_CUSTOMER_H
#define MY_EXECUTABLE_CUSTOMER_H

#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"

using namespace std;


class Customer{
private:
    int customerID;  // store unique customer ID
    string firstName;  // first name of customer
    string lastName;  // last name of customer
    // Transaction* startTransaction;
     vector<Transaction*> transactions;

public:
    // constructor
    Customer();
    // param constructor
    Customer(int customerID, const string& lastName, const string& firstName);
    // destructor
    ~Customer();

    // getters
    int getCustomerID() const; // Returns unique customer ID.
    string getFullName(); // Returns full name of customer (combine first and last names).
    string getFirst(); // Returns first name of customer.
    string getLast();  // Returns last name of customer.

    void addTransaction(Transaction* transaction);

    // Displays the full transaction history for customer.
    void displayHistory() const;

};


#endif //MY_EXECUTABLE_CUSTOMER_H
