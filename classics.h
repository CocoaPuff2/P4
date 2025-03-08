#include <string>
#include <iostream>
#include "movie.h"

using namespace std;

#ifndef MY_EXECUTABLE_CLASSICMOVIE_H
#define MY_EXECUTABLE_CLASSICMOVIE_H

class Classics : public Movie {
private:

    string majorActorFirstName; // Major actor first name for the classic movie
    string majorActorLastName; //  Major actor first last for the classic movie
    int releaseMonth;  // Release month of the classic movie

public:
    // adds majorActorFirstName, majorActorLastName, and releaseMonth
    // todo & or not for director and title strings?
    Classics(char genre, int stock, const string director, const string title,
             string  majorActorFirstName, string majorActorLastName, int releaseMonth, int year, char mediaType);

    ~Classics();

    int compare(const Movie& other) const override;

    // specifically for classics, overrides the media version
    // const so that it doesn't modify the data, only reads it
    void display() const;

    // getters
    virtual int getReleaseMonth() const;   // Get the release month (only for classics)
    virtual string getMajorActorFirstName() const ; // Get the first name of the major actor (only for classics)
    virtual string getMajorActorLastName() const;  // Get the last name of the major actor (only for classics)

};



#endif //MY_EXECUTABLE_CLASSICMOVIE_H
