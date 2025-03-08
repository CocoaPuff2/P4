
#include <string>
#include <iostream>
#include "movie.h"

using namespace std;

// default constructor
Movie::Movie() {
    genre = ' ';
    stock = 0;
    director = " ";
    title = " ";
    year = 0;
}

// parametized constructor
Movie::Movie(char genre, int stock, const string& director, const string& title, int year)
        : genre(genre), stock(stock), director(director), title(title), year(year) {}

// destructor
Movie::~Movie() {}

// getters
char Movie::getGenre() const { return genre; }
int Movie::getStock() const { return stock; }
string Movie::getDirector() const { return director; }
string Movie::getTitle() const { return title; }
int Movie::getYear() const { return year; }

// setters
void Movie::setStock(int newStock) { stock = newStock;}




