#include <string>
#include <iostream>
#include "movie.h"

using namespace std;

#ifndef MY_EXECUTABLE_COMEDY_H
#define MY_EXECUTABLE_COMEDY_H

class Comedy : public Movie {
public:
     Comedy(char genre, int stock, string director, string title, int year, char mediaType);
    // Comedy(char genre, int stock, string director, string title, int year, char mediaType,
          //  vector<Transaction*> transactions);

    ~Comedy();
    // specifically for comedies, overrides the media version
    // const so that it doesn't modify the data, only reads it
    int compare(const Movie& other) const override;
    void display() const;
};

#endif //MY_EXECUTABLE_COMEDY_H
