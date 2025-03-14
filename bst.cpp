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

    /*
    Node* inOrderDelete(Node* node, const Movie* movie) {
        if (node == nullptr) {
            return nullptr;  // Movie not found, return nullptr
        }

        int comparisonResult = movie->compare(*node->data);

        // If the movie to delete is smaller, it lies in the left subtree
        if (comparisonResult < 0) {
            node->left = inOrderDelete(node->left, movie);
        }
            // If the movie to delete is greater, it lies in the right subtree
        else if (comparisonResult > 0) {
            node->right = inOrderDelete(node->right, movie);
        }
            // If the movie to delete is found
        else {
            // Case 1: Node has no children (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node->data;  // Delete the Movie object
                delete node;  // Delete the node
                return nullptr;
            }
                // Case 2: Node has one child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node->data;  // Delete the Movie object
                delete node;  // Delete the node
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node->data;  // Delete the Movie object
                delete node;  // Delete the node
                return temp;
            }
                // Case 3: Node has two children
            else {
                // Find the in-order successor (smallest node in the right subtree)
                Node* temp = findMin(node->right);
                node->data = temp->data;  // Replace node's data with in-order successor's data
                node->right = inOrderDelete(node->right, temp->data);  // Delete the in-order successor
            }
        }
        return node;  // Return modified node
    }

    // Helper function to find the minimum value node (in-order successor)
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
     */

    void clearHelper(Node* node) {
        if (node == nullptr) return;

        // Recursively delete left and right subtrees first
        clearHelper(node->left);
        clearHelper(node->right);

        // Delete the Movie object
        delete node->data;
        // Delete the node itself
        delete node;
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

    void collectMovies(Node* node, vector<Movie*>& movies) {
        if (node != nullptr) {
            collectMovies(node->left, movies);
            movies.push_back(node->data);  // Store movie in the vector
            collectMovies(node->right, movies);
        }
    }

    void inOrderTraversal(vector<Movie*>& movies) {
        collectMovies(root, movies);
    }

    // Perform in-order traversal, display the movie details
    void inOrderTraversal() {
        inorder(root);
        cout << endl;
    }

    /*
    void deleteMovie(const Movie* movie) {
        root = inOrderDelete(root, movie);
    }
     */

    void clear() {
        clearHelper(root);  // Start recursive deletion from the root
        root = nullptr;  // Set root to nullptr after deletion
    }
};

