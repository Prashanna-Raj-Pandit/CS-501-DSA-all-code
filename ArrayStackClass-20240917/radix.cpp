#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
void radix_sort(vector<T>& A, int (*sortkey)(T)) {
    int N = A.size();
    int digit = 1;
    bool done = false;

    while (!done) {
        done = true;
        queue<T> Q[10];  // 10 queues for digits 0-9

        // Distribute elements based on the current digit
        for (int j = 0; j < N; j++) {
            int cur_digit = (sortkey(A[j]) / digit) % 10;
            if (sortkey(A[j]) / digit>0)
                done = false;
            Q[cur_digit].push(A[j]);
        }

        // Collect elements back into the array
        int index = 0;
        for (int k = 0; k < 10; k++) {
            while (!Q[k].empty()) {
                A[index++] = Q[k].front();
                Q[k].pop();
            }
        }

        digit *= 10;  // Move to the next significant digit
    }
}

// Example of how to use sortkey for an int array
int get_key(int x) {
    return x;
}

int main() {
    vector<int> A;
    cout << "Enter 10 numbers: ";
    int val;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        A.push_back(val);
    }
    radix_sort(A, get_key);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    return 0;
}
