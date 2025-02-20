#include <iostream>
#include <string>
using namespace std;




short readNumber(string message) {
    short number;
    cout << message;
    cin >> number;
    return number;
}

bool isLeapYear(short year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInAMonth(short year, short month) {
    if (month < 1 || month > 12) {
        return 0;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? (isLeapYear(year) ? 29 : 28) : 31;
}

int main()
{

    short year = readNumber("Please enter a year : ");
    short month = readNumber("\nPlease enter a month : ");
    short day = readNumber("\nPlease enter a day : ");
    short result = 0;

    for (short i = 1; i < month; i++) {
        result += NumberOfDaysInAMonth(year, i);
    }
    result += day;
    cout << result;

}

