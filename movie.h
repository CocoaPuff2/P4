
#ifndef MY_EXECUTABLE_MOVIE_H
#define MY_EXECUTABLE_MOVIE_H

#include <string>
#include <iostream>
using namespace std;

/*
 * NOTE:
 * For comedy movies: F, Stock, Director, Title, Year it released
 * For drama movies: D, Stock, Director, Title, Year it released
 * For classics movies: C, Stock, Director, Title, Major actor Release date
 */

// Movie is an abstract class
class Movie {
protected:
    char genre; // C (classics), F(comedy), or D(drama)
    int stock; // # of available copies of the movie
    string director; // director of movie
    string title; // title of the movie
    int year;  // release year of the movie

public:
    // default constructor
    // param constructor
    // destructor

    // setters
    // getters

    // functions for classics

    // display the movie details, overriden by subclasses
    virtual void display() const = 0;

};

#endif //MY_EXECUTABLE_MOVIE_H
