#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> Q1, Q2; int num,digit=10;
    cout<<"\nenter the numbers:"<<endl;
    // Loop to read 100 integers, for now i am taking just 5 numbers
    for (int k = 0; k < 5; k++) {
        cin >> num;

        // Check the 10's digit and decide which queue to push the number into
        if ((num / digit) % 2 == 0) {
            Q2.push(num);  // Even 10's digit goes to Q2
        } else {
            Q1.push(num);  // Odd 10's digit goes to Q1
        }
    }

    // Optional: Print contents of Q1 and Q2 for verification
    cout << "Queue Q1 (Odd 10s digit): ";
    while (!Q1.empty()) {
        cout << Q1.front() << " ";
        Q1.pop();
    }
    cout << endl;

    cout << "Queue Q2 (Even 10s digit): ";
    while (!Q2.empty()) {
        cout << Q2.front() << " ";
        Q2.pop();
    }
    cout << endl;

    return 0;
}
