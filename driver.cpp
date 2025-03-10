#include <iostream>
#include <fstream>
#include "store.h"
using namespace std;

int main() {
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
    // store.displayAllMovies();  // This will call display() for each movie
    outputFile.close(); // Close the output file after writing

    // Open the customers' file
    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cout << "Error opening the customers file!" << endl;
        return 1;
    }

    // Read customer data and store it in the hash table
    store.readCustomers(customerFile);
    customerFile.close();  // Close the customer file after reading

    // Open the commands file
    ifstream commandsFile("data4commands.txt");
    if (!commandsFile) {
        cout << "Error opening the commands file!" << endl;
        return 1;
    }

    // Read command data and process it
    store.readCommands(commandsFile);
    commandsFile.close();  // Close the commands file after reading

    return 0;

}
