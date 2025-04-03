#include <iostream>
using namespace std;


struct stDate {
    short day, month, year;
};


stDate readDate(string message) {
    stDate date;
    cout << message;
    cout << "\nPlease enter a day : ";
    cin >> date.day;
    cout << "Please enter a month : ";
    cin >> date.month;
    cout << "Please enter a year : ";
    cin >> date.year;
    return date;
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

bool isDateValid(stDate date) {
    if (date.day > NumberOfDaysInAMonth(date.year, date.month) || (date.month > 12 || date.month < 1)) {
        return false;
    }
    return true;
}


int main()
{
    stDate date = readDate("Enter Date : \n");
    if (isDateValid(date) == true) {
        cout << "\nYes, date is valid.";
    }
    else {
        cout << "\nNo, date is not valid.";
    }
}
