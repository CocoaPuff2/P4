#include "returnmedia.h"

// Constructor: initializes the ReturnMedia transaction with a movie
/*
ReturnMedia::ReturnMedia(Movie* movie)
        : Transaction(movie) {
}
 */

ReturnMedia::ReturnMedia(Movie* movie, int customerID)
        : Transaction(movie, customerID) {  // Passes movie and customerID to the base class
}

// Implementation of the displayTransaction function
void ReturnMedia::displayTransaction() const {
    std::cout << "Returned " << movie->getTitle()  // Fetch movie title
              << " by" << movie->getDirector()  // Fetch movie director
              << std::endl;
}
