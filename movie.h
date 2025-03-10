
#ifndef MY_EXECUTABLE_MOVIE_H
#define MY_EXECUTABLE_MOVIE_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
 * NOTE:
 * For comedy movies: F, Stock, Director, Title, Year it released
 * For drama movies: D, Stock, Director, Title, Year it released
 * For classics movies: C, Stock, Director, Title, Major actor Release date
 *
 *  Data Structure: BST
 */

// Movie is an abstract class
class Movie {
protected:
    char genre; // C (classics), F(comedy), or D(drama)
    int stock; // # of available copies of the movie
    string director; // director of movie
    string title; // title of the movie
    int year;  // release year of the movie
    char mediaType; // currently only supports 'D' for DVD
    //vector<Transaction*> transactions;

public:
    // default constructor
    Movie();
    // param constructor
    // ex:
    // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    // D, 10, Barry Levinson, Good Morning Vietnam, 1988
    Movie(char genre, int stock, const string& director, const string& title, int year, char mediaType);
    /*
    Movie(char genre, int stock, const string& director, const string& title, int year,
          char mediaType, vector<Transaction*> transactions);
          */
    // destructor
    virtual ~Movie();

    // getters
    char getGenre() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getYear() const;
    char getMediaType() const;


    // setters
    void setStock(int stock);  // Set the stock of available copies

    // increase and decrease stock;
    void increaseStock();
    void decreaseStock();

    // compare method for sorting purposes
    virtual int compare(const Movie& other) const = 0; // Pure virtual function

    // display the movie details, overridden by subclasses
    virtual void display() const = 0;

};

#endif //MY_EXECUTABLE_MOVIE_H
