#include "returnmedia.h"

// Constructor: initializes the ReturnMedia transaction with a movie
ReturnMedia::ReturnMedia(Movie* movie)
        : Transaction(movie) {  // Passes the movie and the type (this for "returned")
}

// Implementation of the displayTransaction function
void ReturnMedia::displayTransaction() const {
    std::cout << "Returned " << movie->getTitle()  // Fetch movie title
              << " by " << movie->getDirector()  // Fetch movie director
              << std::endl;
}
