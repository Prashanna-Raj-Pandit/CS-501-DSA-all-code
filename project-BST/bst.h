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


#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bt.h"

// Provider structure to hold the details
struct Provider {
    int id;            // Unique ID for the provider
    std::string name;  // Name of the provider
    double amountPaid; // Amount paid by the provider
    double amountDue;  // Amount due from the provider
};

// Node structure for the BST
struct Node {
    Provider data; // Provider data
    Node* left;   // Left child
    Node* right;  // Right child

    Node(Provider provider) : data(provider), left(nullptr), right(nullptr) {} // Node constructor
};

class BST : public BT<Provider> {
public:
    // Function to insert a provider record
    void insert(int id, const std::string& name) {
        Provider provider = {id, name, 0.0, 0.0}; // Initialize the provider
        BT<Provider>::insert(provider); // Call base class insert method
    }

    // Function to search for a provider by ID
    Node* search(int id) {
        return search(root, id); // Call private search method
    }

    // Print summary report of providers
    void printSummaryReport() {
        std::cout << std::setw(10) << "ID" 
                  << std::setw(25) << "Provider Name" 
                  << std::setw(25) << "Amount Paid" 
                  << std::setw(20) << "Amount Due" << std::endl;
        std::cout << std::string(80, '~') << std::endl;  // Print a line separator

        printInOrder(root); // Traverse and print the records

        std::cout << std::endl;  // Print a blank line at the end
    }

    // Print records to an output file in the required format
    void printToFile(std::ofstream& file) {
        printInOrderToFile(root, file); // Traverse and print records to file
    }

private:
    // Helper function to search a node by ID
    Node* search(Node* node, int id) {
        if (node == nullptr || node->data.id == id) {
            return node; // Return the node if found or null if not found
        }
        return (id < node->data.id) ? search(node->left, id) : search(node->right, id);
    }

    // Helper function to traverse the tree and print each record
    void printInOrder(Node* node) {
        if (node != nullptr) {
            printInOrder(node->left); // Traverse left subtree
            // Print the node's data in a formatted way
            std::cout << std::setw(10) << node->data.id 
                      << std::setw(25) << node->data.name 
                      << std::setw(25) << std::fixed << std::setprecision(2) << node->data.amountPaid 
                      << std::setw(20) << std::fixed << std::setprecision(2) << node->data.amountDue 
                      << std::endl;
            printInOrder(node->right); // Traverse right subtree
        }
    }

    // Helper function to print each record to a file
    void printInOrderToFile(Node* node, std::ofstream& file) {
        if (node != nullptr) {
            printInOrderToFile(node->left, file); // Traverse left subtree
            // Print the node's data to the file in the required format
            file << node->data.id << "\n"
                 << node->data.name << "\n"
                 << node->data.amountPaid << "\n"
                 << node->data.amountDue << "\n\n"; // Adding an extra newline for formatting
            printInOrderToFile(node->right, file); // Traverse right subtree
        }
    }
};

#endif // BST_H


