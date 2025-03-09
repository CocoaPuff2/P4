#include <iostream>
#include "transaction.h"
using namespace std;

// default constructor

Transaction::Transaction(Movie* m, const string& actionType)
        : movie(m), type(actionType) {}


// destructor
Transaction::~Transaction() {
    // todo
}

// getters
string Transaction::getType() const { return type; } // Can be B or R
Movie* Transaction::getMovie() const { return movie;}

void Transaction::displayTransaction() const {
    // Borrowed Holiday by George Cukor
    std::cout << "Movie: " << movie->getTitle()  // Assuming Movie class has getTitle method
              << ", Action: " << type << std::endl;
}




