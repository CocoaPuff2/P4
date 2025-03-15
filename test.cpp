#include <iostream>
#include "drama.h"
#include "comedy.h"
#include "classics.h"

using namespace std;
/*
void testDrama() {
    cout << "\n=== Testing Drama Movies ===\n";

    Drama d1('D', 5, "Christopher Nolan", "Interstellar", 2014, 'D');
    Drama d2('D', 7, "Steven Spielberg", "Jurassic Park", 1993, 'D');

    // Test sorting (director -> title)
    cout << "Drama Sorting Test: " << ((d1.compare(d2) < 0) ? "Passed\n" : "Failed\n");

    // Test stock manipulation
    d1.increaseStock();
    cout << "Increase Stock Test: " << ((d1.getStock() == 6) ? "Passed\n" : "Failed\n");

    d1.decreaseStock();
    cout << "Decrease Stock Test: " << ((d1.getStock() == 5) ? "Passed\n" : "Failed\n");

    // Display test
    cout << "Display Test (Should print movie details): \n";
    d1.display();
}

void testComedy() {
    cout << "\n=== Testing Comedy Movies ===\n";

    Comedy c1('F', 10, "Todd Phillips", "The Hangover", 2009, 'D');
    Comedy c2('F', 12, "Judd Apatow", "Superbad", 2007, 'D');

    // Test sorting (title -> year)
    cout << "Comedy Sorting Test: " << ((c1.compare(c2) > 0) ? "Passed\n" : "Failed\n");

    // Test stock manipulation
    c1.increaseStock();
    cout << "Increase Stock Test: " << ((c1.getStock() == 11) ? "Passed\n" : "Failed\n");

    c1.decreaseStock();
    cout << "Decrease Stock Test: " << ((c1.getStock() == 10) ? "Passed\n" : "Failed\n");

    // Display test
    cout << "Display Test (Should print movie details): \n";
    c1.display();
}

void testClassics() {
    cout << "\n=== Testing Classic Movies ===\n";

    Classics cl1('C', 3, "Victor Fleming", "Gone with the Wind", "Clark", "Gable", 12, 1939, 'D');
    Classics cl2('C', 4, "Michael Curtiz", "Casablanca", "Humphrey", "Bogart", 11, 1942, 'D');

    // Test sorting (release year -> month -> actor)
    cout << "Classics Sorting Test: " << ((cl1.compare(cl2) < 0) ? "Passed\n" : "Failed\n");

    // Test stock manipulation
    cl1.increaseStock();
    cout << "Increase Stock Test: " << ((cl1.getStock() == 4) ? "Passed\n" : "Failed\n");

    cl1.decreaseStock();
    cout << "Decrease Stock Test: " << ((cl1.getStock() == 3) ? "Passed\n" : "Failed\n");

    // Display test
    cout << "Display Test (Should print movie details): \n";
    cl1.display();
}

int main() {
    testDrama();
    testComedy();
    testClassics();
    return 0;
}
*/