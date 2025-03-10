#ifndef RETURNMEDIA_H
#define RETURNMEDIA_H

#include "transaction.h"
#include "movie.h"
#include <iostream>

class ReturnMedia : public Transaction {
public:
    // Constructor: initializes the ReturnMedia transaction with a movie
    ReturnMedia(Movie* movie);

    // Override the displayTransaction function to display the returning transaction details
    void displayTransaction() const override;
};

#endif // RETURNMEDIA_H
