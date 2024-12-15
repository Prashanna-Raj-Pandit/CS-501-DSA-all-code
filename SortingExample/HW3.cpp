/*
Author Name: Prashanna Raj Pandit
--------------------------------------------------------------------------------------------------------
Program Information: a program that helps to determine the average waiting time at local branch of Chase Bank. 
This simulation will be using two variables: (a) the number of tellers working at the branch, and whether an express
service window is reserved for single transaction customers who only need one minute.  Customers who need more than 1 
transactions will enter one main queue.  If there is an express window, then single transaction customers will enter a 
separate express queue, unless there are already people in express queue AND the main queue is empty at their time of arrival.  
---------------------------------------------------------------------------------------------------------
Submitted on: October 14, 2024
---------------------------------------------------------------------------------------------------------
Deadline: October 14, 2024, 10:10 PM
---------------------------------------------------------------------------------------------------------
Instruction for grader: Error checking->If the user enters a number of express windows other than 0 or 1, it prints an error message.
If the user enters a number of regular windows other than 1 to 3, it prints an error message.
The program stops after 6 simulations, as requested.
*/



#include <iostream>
#include <queue>   // To use STL queue
#include <cstdlib> // To use rand()
#include <ctime>   // Use for seeding the random number generator
#include <limits>
#include <vector>  // To store clerk timers
#include <utility> // To use std::make_pair

using namespace std;

// Function to generate the number of customers arriving based on probabilities
int generateCustomerArrival() {
    float randVal = rand() / (float)RAND_MAX;
    if (randVal <= 0.80) return 0;
    if (randVal <= 0.95) return 1;
    if (randVal <= 0.98) return 2;
    if (randVal <= 0.99) return 3;
    return 4;
}

// Function to generate service time based on customer type percentages
int generateServiceTime() {
    float randVal = rand() / (float)RAND_MAX;
    if (randVal <= 0.30) return 1;
    if (randVal <= 0.60) return 2;
    if (randVal <= 0.80) return 3;
    if (randVal <= 0.90) return 4;
    if (randVal <= 0.95) return 5;
    return 6;
}

// Simulation function
void runSimulation(int simulationNumber, int simulationTime, int regularWindows, int expressWindow) {
    // Queues for main and express lanes
    queue<pair<int, int> > mainQueue;    // Stores service time and arrival time
    queue<pair<int, int> > expressQueue; // Stores service time and arrival time

    // Variables for tracking statistics
    int totalCustomersServed = 0;
    int totalWaitingTime = 0;  // To calculate average waiting time
    int maxWaitingTime = 0;    // To track maximum waiting time
    int timeWithMainLine = 0;  // Time the main queue has customers
    int timeWithExpressLine = 0;  // Time the express queue has customers

    // Array to track tellers' remaining service times
    int totalClerks = regularWindows + expressWindow;
    vector<int> clerkTimers(totalClerks, 0); // All tellers start idle

    // Seed the random number generator
    srand(time(0));

    // Simulation loop for each minute
    for (int minute = 0; minute < simulationTime; minute++) {
        // Generate the number of new arrivals
        int newArrivals = generateCustomerArrival();

        // For each new arrival, determine service time and assign to queue
        for (int i = 0; i < newArrivals; i++) {
            int serviceTime = generateServiceTime();
            if (serviceTime == 1 && expressWindow == 1) {
                expressQueue.push(make_pair(serviceTime, minute)); // Store arrival time and service time
            } else {
                mainQueue.push(make_pair(serviceTime, minute)); // Use make_pair to push pairs
            }
        }

        // Track if there's a line in the main queue or express queue
        if (!mainQueue.empty()) {
            timeWithMainLine++;
        }
        if (!expressQueue.empty()) {
            timeWithExpressLine++;
        }

        // Serve customers with available clerks
        for (int i = 0; i < totalClerks; i++) {
            // If the clerk is idle, assign a customer if available
            if (clerkTimers[i] == 0) {
                if (i < expressWindow && !expressQueue.empty()) {
                    // Serve from express queue if it's an express window
                    int serviceTime = expressQueue.front().first;
                    int arrivalTime = expressQueue.front().second;
                    expressQueue.pop();

                    // Calculate waiting time for express customer
                    int waitTime = minute - arrivalTime;
                    totalWaitingTime += waitTime;
                    if (waitTime > maxWaitingTime) maxWaitingTime = waitTime;

                    clerkTimers[i] = serviceTime;
                } else if (!mainQueue.empty()) {
                    // Serve from the main queue
                    int serviceTime = mainQueue.front().first;
                    int arrivalTime = mainQueue.front().second;
                    mainQueue.pop();

                    // Calculate waiting time for main queue customer
                    int waitTime = minute - arrivalTime;
                    totalWaitingTime += waitTime;
                    if (waitTime > maxWaitingTime) maxWaitingTime = waitTime;

                    clerkTimers[i] = serviceTime;
                }
            }

            // Decrease the clerk's remaining service time if they're serving someone
            if (clerkTimers[i] > 0) {
                clerkTimers[i]--;
                if (clerkTimers[i] == 0) {
                    totalCustomersServed++; // Customer served once their time reaches 0
                }
            }
        }
    }

    // Calculate and print the simulation summary
    float percentTimeWithMainLine = (static_cast<float>(timeWithMainLine) / simulationTime) * 100;
    float percentTimeWithExpressLine = (static_cast<float>(timeWithExpressLine) / simulationTime) * 100;
    float averageWaitingTime = totalCustomersServed == 0 ? 0 : static_cast<float>(totalWaitingTime) / totalCustomersServed;

    // Print results
    cout << "Result Summary: " << endl;
    cout << "Total Number of clerks: " << totalClerks << endl;
    cout << "Total number of customers served: " << totalCustomersServed << endl;
    cout << "Percentage of time there is a main line: " << percentTimeWithMainLine << "%" << endl;
    cout << "Percentage of time there is an express line: " << percentTimeWithExpressLine << "%" << endl;
    cout << "Average waiting time: " << averageWaitingTime << " minutes" << endl;
    cout << "Maximum waiting time: " << maxWaitingTime << " minutes" << endl;
    cout << endl;
}

int main() {
    int simulationNumber = 1;

    // Run exactly 6 simulations
    while (simulationNumber <= 6) {
        int simulationTime, regularWindows, expressWindow;

        cout << ".... Simulation Number " << simulationNumber << " ...." << endl;
        // Get inputs for each simulation
        cout << "Please enter total simulation time in minutes,(Enter 0 to QUIT):";
        cin >> simulationTime;
        if(simulationTime==0){break;}

        cout << "Please enter the number of regular windows (1 - 3): ";
        cin >> regularWindows;
        if (regularWindows < 1 || regularWindows > 3) {
            cout << "Error: Invalid number of regular windows. Please enter a value between 1 and 3." << endl;
            continue;
        }

        cout << "Please enter the number of express windows (0 or 1): ";
        cin >> expressWindow;
        if (expressWindow != 0 && expressWindow != 1) {
            cout << "Error: Invalid number of express windows. Please enter 0 or 1." << endl;
            continue;
        }

        // Add some space between inputs and results
        cout << endl << endl;

        // Run the simulation
        runSimulation(simulationNumber, simulationTime, regularWindows, expressWindow);
        simulationNumber++;
    }

    return 0;
}


