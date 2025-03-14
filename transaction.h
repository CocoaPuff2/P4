
#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

#include <string>
#include "movie.h"

using namespace std;

// Transaction is an abstract class
class Transaction {
protected:
    int customerID;
    Movie* movie;

public:
    // param constructor
    Transaction(Movie* movie, int customerID);
    // destructor
    virtual ~Transaction();

    // getters
    Movie* getMovie() const;
    int getCustomerID() const;

    // define how the transaction is printed, must be implemented by derived classes
    virtual void displayTransaction() const = 0;

};

#endif //MY_EXECUTABLE_TRANSACTION_H

