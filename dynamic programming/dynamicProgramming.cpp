/*
Author Name: Prashanna Raj Pandit
--------------------------------------------------------------------------------------------------------
Program Information: a C++ program that find the min number of perfect squares that add up to a specific given integer. 
To solve the problem of finding the least number of perfect square numbers that sum to n, we can use dynamic programming.
---------------------------------------------------------------------------------------------------------
Submitted on: November 23, 2024
---------------------------------------------------------------------------------------------------------
Deadline: December 2, 2024, 10:10 PM
---------------------------------------------------------------------------------------------------------
Instruction for grader: The program will continue to prompt the user for a positive integer n until a 0 is entered. For each n, it will print
an equation that shows n being equal to the sum of (a minimum number of) perfect squares. 
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Function to find the minimum number of perfect squares that sum up to 'n'
void findMinPerfectSquares(int n) {
    vector<int> dp(n + 1, INT_MAX); // Array to store the minimum number of perfect squares for each number from 0 to n
    vector<vector<int> > squaresUsed(n + 1); // To track the perfect squares used to sum up to each number

    dp[0] = 0; // Base case: 0 can be represented by 0 perfect squares

    
    for (int i = 1; i <= n; i++) {
        // Check all perfect squares less than or equal to 'i'
        for (int j = 1; j * j <= i; j++) {
            int square = j * j; 
            // If using this perfect square results in fewer terms
            if (dp[i] > dp[i - square] + 1) {
                dp[i] = dp[i - square] + 1; // Update the minimum count
                squaresUsed[i] = squaresUsed[i - square]; 
                squaresUsed[i].push_back(square); 
            }
        }
    }

    // Print the result
    cout << n << "="; // Print the number being decomposed
    for (size_t i = 0; i < squaresUsed[n].size(); i++) {
        if (i > 0) cout << "+"; 
        cout << squaresUsed[n][i]; 
    }
    cout << endl;
    cout << "Minimum perfect square number is " << dp[n] << "." << endl; 
}

int main() {
    int n; 
    while (true) {
        // Prompt the user for input
        cout << "Enter an integer to get minimum perfect squares (0 to exit): ";
        cin >> n; 
        if (n == 0) break; // Exit the loop if the user enters 0
        findMinPerfectSquares(n); // Call the function to compute the result for the given number
    }
    return 0; 
}
