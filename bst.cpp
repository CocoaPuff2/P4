#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {} // Constructor
};

// BST class
class BST {
private:
    Node* root;

    // Helper function for insertion (recursive)
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for searching (recursive)
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper function for inorder traversal (recursive)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    // Constructor, initializes empty BST
    BST() : root(nullptr) {}

    // insert
    void insert(int value) {
        root = insert(root, value);
    }

    // search
    bool search(int value) {
        return search(root, value);
    }

    //  print inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

