#include "drama.h"
#include "movie.h"
#include <iostream>

using namespace std;

Drama::Drama(char genre, int stock, string director, string title, int year)
        : Movie(genre, stock, director, title, year) {

}

Drama::~Drama() {
    // todo:
}

// dramas (‘D’) are sorted by Director, then Title
int Drama::compare(const Movie& other) const {
    if (director != other.getDirector()) {
        // if director is lexicographically less than the other title
        if (director < other.getDirector()) {
            return -1;
        } else {
            return 1;
        }
    }

    if (title < other.getTitle()) {
        return -1;
    } else if (title < other.getTitle()) {
        return 1;
    } else {
        return 1;
    }
}

void Drama::display() const {
    cout << "D " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}
