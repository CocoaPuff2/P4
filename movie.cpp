
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
    mediaType = ' ';
}

// parametized constructor
Movie::Movie(char genre, int stock, const string& director, const string& title, int year, char mediaType)
        : genre(genre), stock(stock), director(director), title(title), year(year), mediaType(mediaType) {}


/*
Movie::Movie(char genre, int stock, const string& director, const string& title, int year, char mediaType, vector<Transaction*> transactions)
        : genre(genre), stock(stock), director(director), title(title), year(year), mediaType(mediaType), transactions(transactions) {}
*/

// destructor
Movie::~Movie() {}

// getters
char Movie::getGenre() const { return genre; }
int Movie::getStock() const { return stock; }
string Movie::getDirector() const { return director; }
string Movie::getTitle() const { return title; }
int Movie::getYear() const { return year; }
char Movie::getMediaType() const { return mediaType; }

// setters
void Movie::setStock(int newStock) { stock = newStock;}

void Movie::increaseStock() {
    if (stock > 0) {
        --stock;
    } else {
        std::cout << "Borrow Transaction Failed -- Not enough in the Stock." << std::endl;
    }
}
void Movie::decreaseStock() {
    ++stock;
}




