
#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

#include <string>
#include "movie.h"

using namespace std;

// Transaction is an abstract class
class Transaction {
protected:
    Transaction* type; // 'Borrowed' --> Borrow transaction, 'Return' --> Return transaction
    Movie* movie;

public:
    // param constructor
    Transaction(Movie* movie);
    // destructor
    virtual ~Transaction();
    //  virtual ~Transaction() = default;
    // printing transaction details, must be implemented by derived classes to

    // getters
    Movie* getMovie() const;

    // define how the transaction is printed.
    virtual void displayTransaction() const = 0;

};

#endif //MY_EXECUTABLE_TRANSACTION_H

