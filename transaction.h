
#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

#include <string>

using namespace std;

// Transaction is an abstract class
class Transaction {
protected:
    string type; // 'B' --> Borrow transaction, 'R' --> Return transaction
    string mediaType; // currently only supports 'D' for DVD

public:
    // default constructor
    // destructor
    // printing transaction details, must be implemented by derived classes to

    // getters
    string getType();
    string getMediaType();

    // setters


    // define how the transaction is printed.
    virtual void printTransaction() = 0;

};

#endif //MY_EXECUTABLE_TRANSACTION_H

