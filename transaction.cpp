#include <iostream>
#include "transaction.h"
using namespace std;

// default constructor

Transaction::Transaction(Movie* m, int newCustomerID)
        : movie(m), customerID(newCustomerID) {}


// destructor
Transaction::~Transaction() {
}

// getters
Movie* Transaction::getMovie() const { return movie;}
int Transaction::getCustomerID() const { return customerID; }





