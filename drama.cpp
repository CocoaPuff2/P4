#include "drama.h"
#include "movie.h"
#include <fstream>
#include <iostream>

using namespace std;

Drama::Drama(char genre, int stock, string director, string title, int year, char mediaType)
        : Movie(genre, stock, director, title, year, mediaType) {

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
    /*
    ofstream outFile("movies_output.txt", ios::app);  // Open the output file in append mode
    if (outFile.is_open()) {
        outFile << mediaType << " " << genre << " " << stock << " " << director << " " <<
                title << " " << year << endl;
        outFile.close();  // Always close the file when done writing
    } else {
        cout << "Error opening the file for writing! (Drama movie)" << endl;
    }
     */
    cout << genre << " " << mediaType <<  " " << title << " " << director << " " <<
         year << " " << stock << endl;
}
