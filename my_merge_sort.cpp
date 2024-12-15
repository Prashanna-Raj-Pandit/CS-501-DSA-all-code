#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define studentType
struct studentType {
    string name;
    double gpa;
    
    // Comparison operator
    bool operator<(const studentType& other) const {
        return gpa < other.gpa;
    }

    // Constructor for studentType
    studentType(string n, double g) : name(n), gpa(g) {}
};

void merge(vector<studentType>& left, vector<studentType>& right, vector<studentType>& array) {
    int i = 0, j = 0, k = 0;
    int nl = left.size();
    int nr = right.size();
    
    while (i < nl && j < nr) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < nl) {
        array[k] = left[i];
        i++;
        k++;
    }
    
    while (j < nr) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<studentType>& array) {
    int len = array.size();
    if (len < 2) return;
    
    int mid = len / 2;
    vector<studentType> left(mid);
    vector<studentType> right(len - mid);

    // Copy to left and right
    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (int i = mid; i < len; i++) {
        right[i - mid] = array[i];
    }

    mergeSort(left);
    mergeSort(right);
    merge(left, right, array);
}

int main() {
    vector<studentType> students;
    int numStudents;
    string name;
    double gpa;
    
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter GPA of student " << i + 1 << ": ";
        cin >> gpa;
        students.push_back(studentType(name, gpa));
    }
    
    mergeSort(students);

    cout << "\nStudents sorted by GPA:\n";
    for (const studentType& student : students) {
        cout << student.name << " " << student.gpa << endl;
    }

    return 0;
}
