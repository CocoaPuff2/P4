#include "borrowmedia.h"

// Constructor: initializes the BorrowMedia transaction with a movie
BorrowMedia::BorrowMedia(Movie* movie, int customerID)
        : Transaction(movie, customerID) {  // Passes movie and customerID to the base class
}

// Implementation of the displayTransaction function
void BorrowMedia::displayTransaction() const {
    std::cout << "Borrowed " << movie->getTitle()  // Fetch movie title
              << " by" << movie->getDirector()  // Fetch movie director
              << std::endl;
}
