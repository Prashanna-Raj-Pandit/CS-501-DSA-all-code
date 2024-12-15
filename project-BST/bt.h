/*
Author Name: Prashanna Raj Pandit
--------------------------------------------------------------------------------------------------------
Program Information: A C++ menu-driven program that uses BST that helps a recycling company keeps records on providers 
of waste paper products
---------------------------------------------------------------------------------------------------------
Submitted on: October 30, 2024
---------------------------------------------------------------------------------------------------------
Deadline: October 30, 2024, 10:00 PM
---------------------------------------------------------------------------------------------------------
Instruction for grader: meet all the requirements demanded by the question.
*/


#ifndef BT_H
#define BT_H

#include <iostream>
#include <string>

// Base class for a Binary Tree
template <typename T>
class BT {
protected:
    struct Node {
        T data;      // Data of the node
        Node* left;  // Pointer to left child
        Node* right; // Pointer to right child

        Node(T value) : data(value), left(nullptr), right(nullptr) {} // Node constructor
    };

    Node* root; // Root of the tree

public:
    BT() : root(nullptr) {} // Constructor initializing root to nullptr

    // Function to insert data into the BST
    void insert(T value) {
        root = insert(root, value); // Call the private insert helper
    }

    // Function to get the root node
    Node* getRoot() {
        return root;
    }

private:
    // Helper function to insert a new node
    Node* insert(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value); // Create new node if position is empty
        }

        // Compare and insert in the correct subtree
        if (value.id < node->data.id) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
};

#endif // BT_H
