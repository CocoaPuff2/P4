#include <iostream>
#include "transaction.h"

// default constructor
Transaction::Transaction() {
    type = " ";
    mediaType = " ";
}
// destructor
Transaction::~Transaction() {
    // todo
}

// getters
string Transaction::getType() { return type; } // Can be B or R
string Transaction::getMediaType() {return mediaType; }

// setters

using namespace std;
