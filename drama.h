#include <string>
#include <iostream>
#include "movie.h"

using namespace std;

#ifndef MY_EXECUTABLE_DRAMA_H
#define MY_EXECUTABLE_DRAMA_H

class Drama : public Movie {
public:
    Drama(char genre, int stock, string director, string title, int year, char mediaType);
    ~Drama();
    // specifically for dramas, overrides the media version
    // const so that it doesn't modify the data, only reads it
    int compare(const Movie& other) const override;
    void display() const;
};

#endif //MY_EXECUTABLE_DRAMA_H
