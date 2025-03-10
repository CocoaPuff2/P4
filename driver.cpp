#include <iostream>
#include <fstream>
#include "store.h"
using namespace std;

int main() {
    // Print initial message
    cout << "\nTesting Movies" << endl;

    // Create a Store object to manage the movies
    Store store;

    // Open the input file for reading movie data
    ifstream inputFile("data4movies.txt");
    if (!inputFile) {
        cout << "Error opening the input file!" << endl;
        return 1;  // Exit if file can't be opened
    }

    // Create an output file in the project folder
    ofstream outputFile("./output.txt");
    if (!outputFile) {
        cout << "Output file could not be opened." << endl;
        return 1;
    }

    // Read movies from the file
    store.readMovie(inputFile);  // Read all movies and store them in BSTs
    inputFile.close();  // Close the input file after reading

    // Display all movies (store's displayAllMovies method)
    store.displayAllMovies();  // This will call display() for each movie

    return 0;

    /*
    // Open data4customers.txt and check for errors
    ifstream customersFile("./data4customers.txt");
    if (!customersFile) {
        cout << "File data4customers.txt could not be opened." << endl;
        return 1;
    }

    // Open data4commands.txt and check for errors
    ifstream commandsFile("./data4commands.txt");
    if (!commandsFile) {
        cout << "File data4commands.txt could not be opened." << endl;
        return 1;
    }

    // Open data4movies.txt and check for errors
    ifstream moviesFile("./data4movies.txt");
    if (!moviesFile) {
        cout << "File data4movies.txt could not be opened." << endl;
        return 1;
    }

    // Create an output file in the project folder
    ofstream outputFile("./output.txt");
    if (!outputFile) {
        cout << "Output file could not be opened." << endl;
        return 1;
    }

    string line;

    // Read and write the contents of data4customers.txt
    outputFile << "Contents of data4customers.txt:" << endl;
    while (getline(customersFile, line)) {
        outputFile << line << endl;
    }
    outputFile << endl; // Blank line to separate files

    // Read and write the contents of data4commands.txt
    outputFile << "Contents of data4commands.txt:" << endl;
    while (getline(commandsFile, line)) {
        outputFile << line << endl;
    }
    outputFile << endl; // Blank line to separate files

    // Read and write the contents of data4movies.txt
    outputFile << "Contents of data4movies.txt:" << endl;
    while (getline(moviesFile, line)) {
        outputFile << line << endl;
    }

    // Close all files
    customersFile.close();
    commandsFile.close();
    moviesFile.close();
    outputFile.close();

    // Print success message
    cout << "Success! output.txt is in the project folder." << endl;
    return 0;
     */
}
