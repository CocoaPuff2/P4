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
    // Check if  transaction is a "Borrowed" or "Returned" action
    if (type == "Borrowed") {
        std::cout << "Borrowed " << movie->getTitle()   // Fetch the movie title
                  << " by " << movie->getDirector()   // Fetch the movie director
                  << std::endl;
    } else if (type == "Returned") {
        std::cout << "Returned " << movie->getTitle()   // Fetch the movie title
                  << " by " << movie->getDirector()   // Fetch the movie director
                  << std::endl;
    } else {
        std::cout << "Unknown transaction type." << std::endl;
    }
}




