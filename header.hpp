#include <string>

using namespace std;




// -----------------------------
// Function Prototypes
// -----------------------------
bool isAllDigit(const string& strInput);              // Checks if a string contains only digits
bool isValidLength(const string& strInput);           // Validates the length of the date string (must be 8)
bool isValidMonth(const string& month);               // Validates if month is between "01" and "12"
bool isValidDay(const string& day);                   // Validates if day is between "01" and "31"
string getSuffix(const string& day);                  // Returns the suffix for a given day ("st", "nd", "rd", "th")
string getMonthName(const string& month);             // Converts month number ("01") into month name ("January")
void getDateFromUser();                               // Reads and validates user input
void displayDate(string day, string suffix, string monthName, string year);  // Displays formatted date

