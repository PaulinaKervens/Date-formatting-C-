// That a program that ask the user to enter a date follow the format
// (YYYY_MM_DD) and convert it to ex : 03th october, 2025
// Program name : Convert date format
// Programmer : Kerv kervens Paulina
// Last modified date : October 04, 2025




#include "body.cpp"
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector>
#include "header.hpp"
using namespace std;

// -----------------------------
// Main Function
// -----------------------------
int main() {
    getDateFromUser();   // Ask the user for input
    return 0;
}




// -----------------------------
// Function Implementations
// -----------------------------

// Reads and validates the user's input
void getDateFromUser() {
    bool pass = false;
    string dateFromUser;

    while (!pass) {
        cout << "Enter a date in the format YYYYMMDD : ";
        getline(cin, dateFromUser);

        // Extract year, month, day substrings
        string yearStr = dateFromUser.substr(0, 4);   // YYYY
        string monthStr = dateFromUser.substr(4, 2);  // MM
        string dayStr = dateFromUser.substr(6, 2);    // DD

        // Check if input is valid (all digits + correct length)
        if (isAllDigit(dateFromUser) && isValidLength(dateFromUser)) {

            // Validate month
            if (isValidMonth(monthStr)) {

                // Validate day
                if (isValidDay(dayStr)) {
                    pass = true;   // ✅ Input is valid → break loop

                    // Convert month number → month name
                    string monthName = getMonthName(monthStr);

                    // Get suffix for the day
                    string suffix = getSuffix(dayStr);

                    // Display formatted date
                    displayDate(dayStr, suffix, monthName, yearStr);

                }
                else {
                    cout << "Invalid day (must be between 01 to 31 : " << endl;
                }

            }
            else {
                cout << "Invalid month (must be between 1 to 12 : " << endl;
            }

        }
        else {
            cout << "Invalid date" << endl;
        }
    }
}


// Function that will checks if string contains only digits
bool isAllDigit(const string& strInput) {
    for (char c : strInput) {
        if (!isdigit(c)) return false;
    }
    return true;
}


// Function that checks if string length is 8 (YYYYMMDD format)
bool isValidLength(const string& strInput) {
    return strInput.size() == 8;
}

// Function that validates if month is between 1 and 12
bool isValidMonth(const string& month) {
    int m = stoi(month);
    return (m >= 1 && m <= 12);
}

// Function that validates if day is between 1 and 31
bool isValidDay(const string& day) {
    int d = stoi(day);
    return (d >= 1 && d <= 31);
}

// Function that converts month number ("01") into month name ("January")
string getMonthName(const string& month) {
    vector<string> months = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int m = stoi(month);   // Convert "05" → 5
    return months[m - 1];  // Adjust for 0 - index vector
}

// Determines suffix for the day (st, nd, rd, th)
string getSuffix(const string& day) {
    int d = stoi(day);

    // Special case: 11th, 12th, 13th
    if (d >= 11 && d <= 13) return "th";

    // Check last digit
    switch (d % 10) {
    case 1: return "st";
    case 2: return "nd";
    case 3: return "rd";
    default: return "th";
    }
}

// Displays the final formatted date
void displayDate(string day, string suffix, string monthName, string year) {
    cout << "The date you puts is : " << day << suffix << " of " << monthName << ", " << year << endl;
}

