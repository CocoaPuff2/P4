#ifndef MY_EXECUTABLE_BORROWMEDIA_H
#define MY_EXECUTABLE_BORROWMEDIA_H

#include "transaction.h"
#include "customer.h"
#include "movie.h"
#include <iostream>

using namespace std;

class BorrowMedia : public Transaction {
private:
    Customer* customer;   // Pointer to the customer performing the transaction
    Movie* movie;         // Pointer to the movie being borrowed

public:


};


#endif //MY_EXECUTABLE_BORROWMEDIA_H