#ifndef BORROWMEDIA_H
#define BORROWMEDIA_H

#include "transaction.h"
#include "movie.h"
#include <iostream>

class BorrowMedia : public Transaction {
public:
    // Constructor: initializes the BorrowMedia transaction with a movie
    BorrowMedia(Movie* movie);

    // Override the displayTransaction function to display the borrowing transaction details
    void displayTransaction() const override;
};

#endif // BORROWMEDIA_H
