#include "returnmedia.h"

ReturnMedia::ReturnMedia(Movie* movie, int customerID)
        : Transaction(movie, customerID) {  // Passes movie and customerID to the base class
}

// Implementation of the displayTransaction function
void ReturnMedia::displayTransaction() const {
    std::cout << "Returned " << movie->getTitle()  // Fetch movie title
              << " by" << movie->getDirector()  // Fetch movie director
              << std::endl;
}
