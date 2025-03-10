#include <iostream>
#include "transaction.h"
using namespace std;

// default constructor

Transaction::Transaction(Movie* m)
        : movie(m) {}


// destructor
Transaction::~Transaction() {
    // todo
}

// getters
Movie* Transaction::getMovie() const { return movie;}





