// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter " << n << " integers:" << endl;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // Sort the array using std::sort (Quick Sort)
//     sort(arr.begin(), arr.end());
    

//     cout << "Sorted array:" << endl;
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }






#include <iostream>
#include <vector>
using namespace std;

// QuickSort function
void quickSort(vector<int>& A, int F, int L) {
    if (F >= L) return; // Base case for recursion

    int pivot = A[F]; // Choose the first element as pivot
    int left = F + 1, right = L;

    // Partitioning
    while (left <= right) {
        while (left <= right && A[left] < pivot) left++;
        while (left <= right && A[right] > pivot) right--;

        if (left <= right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }

    // Place the pivot element in its correct position
    swap(A[F], A[right]);

    // Recursively sort the two partitions
    quickSort(A, F, right - 1); // Left partition
    quickSort(A, left, L);      // Right partition
}

int main() {
    vector<int> v;
    cout << "Enter 11 numbers: ";
    int val;
    for (int i = 0; i < 11; i++) {
        cin >> val;
        v.push_back(val);
    }

    // Call quickSort on the vector
    quickSort(v, 0, v.size() - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
