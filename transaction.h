
#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

#include <string>
#include "movie.h"

using namespace std;

// Transaction is an abstract class
class Transaction {
protected:
    string type; // 'Borrowed' --> Borrow transaction, 'Return' --> Return transaction
    Movie* movie;

public:
    // param constructor
    Transaction(Movie* movie, const string& type);
    // destructor
    ~Transaction();
    // printing transaction details, must be implemented by derived classes to

    // getters
    string getType() const;
    Movie* getMovie() const;

    // define how the transaction is printed.
      void displayTransaction() const;

};

#endif //MY_EXECUTABLE_TRANSACTION_H

