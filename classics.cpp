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

/*
Classics::Classics(char newGenre, int newStock, const string& newDirector, const string& newTitle,
                   string newMajorActorFirstName, string newMajorActorLastName, int newReleaseMonth,
                   int newYear, char newMediaType)
        : Movie(newGenre, newStock, newDirector, newTitle, newYear, newMediaType),
          majorActorFirstName(newMajorActorFirstName), majorActorLastName(newMajorActorLastName),
          releaseMonth(newReleaseMonth) {
    // Initialize actor stock for each major actor with equal stock
    string actorFullName = majorActorFirstName + " " + majorActorLastName;
    actorStock[actorFullName] = newStock;
}
 */


Classics::~Classics() {
}


string Classics::getMajorActorFirstName() const { return majorActorFirstName; }
string Classics::getMajorActorLastName() const { return majorActorLastName; }
int Classics::getReleaseMonth() const { return releaseMonth; }

/*


// Add or update stock for a specific actor
void Classics::addActorStock(const string& firstName, const string& lastName, int stockAmount) {
    string actorFullName = firstName + " " + lastName;
    actorStock[actorFullName] = stockAmount;
}

// Retrieve stock for a specific actor
int Classics::getActorStock(const string& firstName, const string& lastName) const {
    string actorFullName = firstName + " " + lastName;
    auto it = actorStock.find(actorFullName);
    if (it != actorStock.end()) {
        return it->second;
    }
    return 0;  // Return 0 if actor doesn't exist
}

// Increase stock for a specific actor
void Classics::increaseActorStock(const string& firstName, const string& lastName, int stockAmount) {
    string actorFullName = firstName + " " + lastName;
    actorStock[actorFullName] += stockAmount;

    // Increase total stock by calling the base class method
    increaseStock();  // This will increase the total stock
}

// Decrease stock for a specific actor
void Classics::decreaseActorStock(const string& firstName, const string& lastName, int stockAmount) {
    string actorFullName = firstName + " " + lastName;
    auto it = actorStock.find(actorFullName);
    if (it != actorStock.end() && it->second >= stockAmount) {
        it->second -= stockAmount;

        // Decrease total stock by calling the base class method
        decreaseStock();  // This will decrease the total stock
    } else {
        cout << "Not enough stock for actor " << actorFullName << endl;
    }
}



*/



// classics (‘C’) are sorted by Release date, then Major actor
int Classics::compare(const Movie& other) const {
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
    cout << genre << " " << mediaType <<  " " << title << " " << director << " " << majorActorFirstName << " " <<
    majorActorLastName << " " << releaseMonth << " " << year << " " << stock << endl;
}