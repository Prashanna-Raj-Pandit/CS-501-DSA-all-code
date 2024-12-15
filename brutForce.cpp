#include <iostream>
#include <cmath>      // for sqrt()
#include <float.h>    // for FLT_MAX
#include <vector>     // for std::vector

// Struct to represent a 2D point
struct pointType {
    float x, y;
};

int main() {
    int N;  // number of points
    std::cout << "Enter the number of points: ";
    std::cin >> N;

    if (N < 2) {
        std::cerr << "At least two points are required.\n";
        return -1;
    }

    std::vector<pointType> points(N);

    // Reading data into the array
    std::cout << "Enter the coordinates of the points (x y):\n";
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    // Variables to store the minimum distance and indices of closest points
    float shortest = FLT_MAX;  // initialize with a large value
    int p1 = -1, p2 = -1;      // indices of the closest points

    // Brute-force search for the closest pair
    for (int k = 0; k < N - 1; k++) {     // Loop over the first point
        for (int l = k + 1; l < N; l++) { // Loop over the second point
            // Calculate squared distance between points[k] and points[l]
            float curDistanceSquared =
                (points[k].x - points[l].x) * (points[k].x - points[l].x) +
                (points[k].y - points[l].y) * (points[k].y - points[l].y);

            // Update shortest distance and point indices if necessary
            if (curDistanceSquared < shortest) {
                shortest = curDistanceSquared;
                p1 = k;
                p2 = l;
            }
        }
    }

    // Output the result (square root to display the actual distance)
    std::cout << "The closest points are (" << points[p1].x << ", " << points[p1].y << ") and ("
              << points[p2].x << ", " << points[p2].y << ").\n";
    std::cout << "The minimum distance is: " << sqrt(shortest) << std::endl;

    return 0;
}
