#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a month
    int daysInMonth(int month, int year) const {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0; // Invalid month
        }
    }

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Operator overloading for adding days
    Date operator+(int days) const {
        Date newDate = *this;
        newDate.day += days;

        while (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
            newDate.day -= newDate.daysInMonth(newDate.month, newDate.year);
            newDate.month++;

            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
        return newDate;
    }

    // Function to print the date
    void printDate() const {
        cout << (day < 10 ? "0" : "") << day << "-"
             << (month < 10 ? "0" : "") << month << "-"
             << year << endl;
    }
};

int main() {
    Date today(27, 8, 2024); // 27th August 2024
    int daysToAdd = 200;

    Date futureDate = today + daysToAdd; // Adding 200 days
    futureDate.printDate(); // Print the result

    return 0;
}
