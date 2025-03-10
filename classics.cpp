#include <string>
#include <iostream>
#include <fstream>
#include "classics.h"
#include "movie.h"

using namespace std;

// todo & or not?
Classics::Classics(char newGenre, int newStock, const string newDirector, const string newTitle,
                   string newMajorActorFirstName, string newMajorActorLastName, int newReleaseMonth,
                   int newYear, char newMediaType) {
    genre = newGenre;
    stock = newStock;
    director = newDirector;
    title = newTitle;

    // *** just for classics
    majorActorFirstName = newMajorActorFirstName;
    majorActorLastName = newMajorActorLastName;
    releaseMonth = newReleaseMonth;
    // ***

    year = newYear;
    mediaType = newMediaType;
}

Classics::~Classics() {
    // todo
}


string Classics::getMajorActorFirstName() const { return majorActorFirstName; }
string Classics::getMajorActorLastName() const { return majorActorLastName; }
int Classics::getReleaseMonth() const { return releaseMonth; }

// classics (‘C’) are sorted by Release date, then Major actor
// todo see how to sort
int Classics::compare(const Movie& other) const {
    // todo to be safe
    // attempt to cast 'other' to a 'Classics' object
    const Classics* otherClassics = dynamic_cast<const Classics*>(&other);
    if (!otherClassics) {
        // If  dynamic cast fails, it means 'other' is not of type 'Classics'
        return 0;
    }

    // Compare by year first
    if (year != otherClassics->getYear()) {
        return (year < otherClassics->getYear()) ? -1 : 1;
    }

    // Compare by release month
    if (releaseMonth != otherClassics->getReleaseMonth()) {
        return (releaseMonth < otherClassics->getReleaseMonth()) ? -1 : 1;
    }

    // Compare by actor first name
    if (majorActorFirstName != otherClassics->getMajorActorFirstName()) {
        return (majorActorFirstName < otherClassics->getMajorActorFirstName()) ? -1 : 1;
    }

    // Compare by actor last name
    if (majorActorLastName != otherClassics->getMajorActorLastName()) {
        return (majorActorLastName < otherClassics->getMajorActorLastName()) ? -1 : 1;
    }

    // If all attributes are the same, return 0 (equal)
    return 0;
}


void Classics::display() const {
    /*
    ofstream outFile("movies_output.txt", ios::app);  // Open the output file in append mode
    if (outFile.is_open()) {
        outFile << mediaType << " " << genre << " " << stock << " " << director << " " <<
                title << " " << majorActorFirstName << " " << majorActorLastName << " " <<
                releaseMonth << " " << year << endl;
        outFile.close();  // Always close the file when done writing
    } else {
        cout << "Error opening the file for writing! (Classic movie)" << endl;
    }
    */
    cout << genre << " " << mediaType <<  " " << title << " " << director << " " << majorActorFirstName << " " <<
    majorActorLastName << " " << releaseMonth << " " << year << " " << stock << endl;
}