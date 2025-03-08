#include <string>
#include <iostream>
#include "movie.h"
#include "comedy.h"

using namespace std;


Comedy::Comedy(char genre, int stock, string director, string title, int year, char mediaType)
        : Movie(genre, stock, director, title, year, mediaType) {

}

Comedy::~Comedy(){
    // todo
}

// comedy movies (‘F’) sorted by Title, then Year it released
int Comedy::compare(const Movie& other) const {
    if (title != other.getTitle()) {
        // if title is lexicographically less than the other title
        if (title < other.getTitle()) {
            return -1;
        } else {
            return 1;
        }
    }
    if (year < other.getYear()) {
        return -1;
    } else if (year < other.getYear()) {
        return 1;
    } else {
        return 1;
    }
}

void Comedy::display() const {
    cout << mediaType << " " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}


