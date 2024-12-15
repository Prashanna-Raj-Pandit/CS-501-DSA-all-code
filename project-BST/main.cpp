

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
Instruction for grader: The updated data is written to the output file after you exit from the main program.
If u chek the output file to see the updated data when the main.cpp is running, there is no change. so make sure to exit from program. 
If there is no update than you will find the same data for input and output file.
*/

#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip> 
#include "bst.h" // Include binary search tree header

// Function to load data from a file into the BST
void loadDataFromFile(BST& bst, const std::string& filename) {
    std::ifstream file(filename); // Open file in read mode
    if (!file) { // Check if file failed to open
        std::cerr << "Error opening file: " << filename << std::endl; // Display error message
        return; // Exit function
    }

    int id; // Variable to store provider ID
    std::string name; // Variable to store provider name
    double amountPaid, amountDue; // Variables to store amounts paid and due

    // Read data from the file line by line
    while (file >> id) { // Read ID from file
        file.ignore(); // Ignore newline character
        std::getline(file, name); // Read provider name
        file >> amountPaid >> amountDue; // Read amounts paid and due

        // Insert provider into the BST
        bst.insert(id, name); // Insert provider into the BST
        auto node = bst.search(id); // Find the inserted node by ID
        if (node) { // Check if node exists
            node->data.amountPaid = amountPaid; // Set amountPaid in node
            node->data.amountDue = amountDue; // Set amountDue in node
        }
    }

    file.close(); // Close the file
}

// Function to save data from BST to an output file
void saveDataToFile(BST& bst, const std::string& filename) {
    std::ofstream file(filename); // Open file in write mode
    if (!file) { // Check if file failed to open
        std::cerr << "Error opening file: " << filename << std::endl; // Display error message
        return; // Exit function
    }
    bst.printToFile(file); // Write BST data to file
    file.close(); // Close the file
}

int main() {
    BST bst; // Instantiate a binary search tree object
    loadDataFromFile(bst, "paper.dat"); // Load data from file into BST

    int choice; // Variable to store user menu choice
    do {
        // Display menu options to the user
        std::cout << "Menu:\n"
                  << "1. Add a record\n"
                  << "2. Issue a payment\n"
                  << "3. Accept a delivery\n"
                  << "4. Print Summary Report\n"
                  << "0. Exit\n"
                  << "\nEnter your choice: ";
        std::cin >> choice; // Read user choice

        switch (choice) { // Execute based on user choice
            case 1: { // Add a new record
                int id; // Provider ID
                std::string name; // Provider name
                std::cout << "Enter ID: ";
                std::cin >> id; // Read ID
                std::cout << "Enter Provider Name: ";
                std::cin.ignore(); // Ignore newline in buffer
                std::getline(std::cin, name); // Read name
                bst.insert(id, name); // Insert into BST
                break; // Exit case 1
            }
            case 2: { // Issue a payment
                int id; // Provider ID
                std::cout << "Enter Provider ID for payment: ";
                std::cin >> id; // Read ID

                auto node = bst.search(id); // Search for node by ID
                if (node) { // If node exists
                    std::cout << "Amount Due for Provider ID " << id << ": " << node->data.amountDue << std::endl;
                    double payment; // Payment amount
                    std::cout << "Enter payment amount (must be <= " << node->data.amountDue << "): ";
                    std::cin >> payment; // Read payment amount

                    if (payment <= node->data.amountDue) { // Check if payment is valid
                        node->data.amountPaid += payment; // Update amount paid
                        node->data.amountDue -= payment; // Update amount due
                        std::cout << "Payment processed. Updated Amount Due: " << node->data.amountDue << std::endl;
                    } else { // If payment exceeds amount due
                        std::cout << "Error: Payment exceeds Amount Due!" << std::endl;
                    }
                } else { // If provider not found
                    std::cout << "Error: Provider ID not found!" << std::endl;
                }
                break; // Exit case 2
            }
            case 3: { // Accept a delivery
                int id; // Provider ID
                double deliveryAmount; // Delivery amount
                std::cout << "Enter Provider ID for delivery: ";
                std::cin >> id; // Read ID
                std::cout << "Enter delivery amount to add to Amount Due: ";
                std::cin >> deliveryAmount; // Read delivery amount

                auto node = bst.search(id); // Search for node by ID
                if (node) { // If node exists
                    node->data.amountDue += deliveryAmount; // Increase amount due
                    std::cout << "Delivery accepted. Updated Amount Due for Provider ID " << id << ": " << node->data.amountDue << std::endl;
                } else { // If provider not found
                    std::cout << "Error: Provider ID not found!" << std::endl;
                }
                break; // Exit case 3
            }
            case 4: // Print summary report
                bst.printSummaryReport(); // Print all records
                break; // Exit case 4
            case 0: // Exit and save data to output file
                saveDataToFile(bst, "paper.out"); // Save BST data to file
                std::cout << "Records saved to paper.out. Exiting program." << std::endl;
                break; // Exit case 0
            default: // Invalid choice
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0); // Repeat until user chooses to exit

    return 0; // End program
}
