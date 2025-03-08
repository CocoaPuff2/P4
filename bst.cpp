#include <iostream>
#include "movie.h"
using namespace std;

// Node structure for BST
struct Node {
    Movie* data;
    Node* left;
    Node* right;

    Node(Movie* movie) : data(movie), left(nullptr), right(nullptr) {} // Constructor
};

// BST class
class BST {
private:
    Node* root;

    // Helper function for insertion (recursive)
    Node* insert(Node* node, Movie* movie) {
        if (node == nullptr) {
            return new Node(movie);
        }

        int comparisonResult = movie->compare(*node->data);
        // If comparison result is less than 0 (-1), insert in the left subtree
        if (comparisonResult < 0) {
            node->left = insert(node->left, movie);
        }
        // If comparison result is greater than 0, insert in the right subtree
        else if (comparisonResult > 0) {
            node->right = insert(node->right, movie);
        }

        return node;
    }

    // Helper function for searching (recursive)
    Movie* search(Node* node, const Movie* movie) {
        if (node == nullptr) {
            return nullptr;
        }

        // Use the compare method of Movie to compare the movie being searched
        int comparisonResult = movie->compare(*node->data);

        // If comparison result is 0, we found the movie, return the pointer to it
        if (comparisonResult == 0) {
            return node->data;
        }

        // If the comparison result is less than 0, search the left subtree
        if (comparisonResult < 0) {
            return search(node->left, movie);
        }

        // If the comparison result is greater than 0, search the right subtree
        return search(node->right, movie);
    }

    // Helper function for inorder traversal (recursive)
    void inorder(Node* node) {
        if (node != nullptr) {
            // Traverse the left subtree
            inorder(node->left);

            // Call the display method (polymorphism, calls overridden display
            // method in corresponding subclass
            node->data->display();

            // Traverse the right subtree
            inorder(node->right);
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Insert movie into the BST
    void insert(Movie* movie) {
        Node* newNode;
        newNode = insert(root, movie);
        if (root ==  nullptr) {
            root = newNode;
        }
    }

    // Search for a movie in the BST
    Movie* search(const Movie* movie) {
        return search(root, movie);
    }

    // Perform in-order traversal, display the movie details
    void inOrderTraversal() {
        inorder(root);
        cout << endl;
    }
};

