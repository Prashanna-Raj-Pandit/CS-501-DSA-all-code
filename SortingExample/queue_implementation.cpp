



// readf 10 studentType data form user (name, id,faculty and marks) and store them in a 
// ArrayQueue. sort them on the basis of their marks using bubble sort and store them in another queue and print them.

// #include <iostream>
// #include <string>
// #include <queue>
// #include <vector>
// using namespace std;

// // Structure to represent a student
// struct studentType {
//     string name;
//     int id;
//     string faculty;
//     float marks;
// };

// // Function to input student data
// void readStudentData(queue<studentType>& studentQueue) {
//     for (int i = 0; i < 10; ++i) {
//         studentType student;
//         cout << "Enter student name: ";
//         cin >> student.name;
//         cout << "Enter student ID: ";
//         cin >> student.id;
//         cout << "Enter faculty: ";
//         cin >> student.faculty;
//         cout << "Enter marks: ";
//         cin >> student.marks;
//         studentQueue.push(student);
//     }
// }

// // Bubble Sort function to sort based on marks
// void bubbleSort(vector<studentType>& students) {
//     int n = students.size();
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (students[j].marks > students[j + 1].marks) {
//                 // Swap the students
//                 swap(students[j], students[j + 1]);
//             }
//         }
//     }
// }

// // Function to print the students in the queue
// void printQueue(queue<studentType> studentQueue) {
//     while (!studentQueue.empty()) {
//         studentType student = studentQueue.front();
//         studentQueue.pop();
//         cout << "Name: " << student.name << ", ID: " << student.id
//              << ", Faculty: " << student.faculty << ", Marks: " << student.marks << endl;
//     }
// }

// int main() {
//     queue<studentType> studentQueue;
//     queue<studentType> sortedQueue;
//     vector<studentType> studentVector;

//     // Read student data and store in the queue
//     readStudentData(studentQueue);

//     // Transfer data from queue to vector for sorting
//     while (!studentQueue.empty()) {
//         studentVector.push_back(studentQueue.front());
//         studentQueue.pop();
//     }

//     // Sort the vector based on marks
//     bubbleSort(studentVector);

//     // Transfer sorted data back to another queue
//     for (auto student : studentVector) {
//         sortedQueue.push(student);
//     }

//     // Print sorted queue
//     cout << "Sorted students by marks:" << endl;
//     printQueue(sortedQueue);

//     return 0;
// }
