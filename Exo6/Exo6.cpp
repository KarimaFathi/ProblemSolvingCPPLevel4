#include <iostream>
using namespace std;

short readYear() {
    short year;
    cout << "\n\nPlease enter the year to check : ";
    cin >> year;
    return year;
}

short readMonth() {
    short month;
    cout << "\n\nPlease enter the month to check : ";
    cin >> month;
    return month;
}

bool isLeapYear(short year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInAMonth(short year, short month) {
    if (month < 1 || month > 12) {
        return 0;
    }
    /*if (month == 2) {
        return (isLeapYear(year) ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;*/
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? (isLeapYear(year) ? 29 : 28) : 31;
}

short NumberOfHoursInAMonth(short year, short month) {
    return NumberOfDaysInAMonth(year, month) * 24;
}

int NumberOfMinutesInAMonth(short year, short month) {
    return NumberOfHoursInAMonth(year, month) * 60;
}

int NumberOfSecondsInAMonth(short year, short month) {
    return NumberOfMinutesInAMonth(year, month) * 60;
}

int main() {
    short year = readYear();
    short month = readMonth();

    cout << "\nNumber of days    in month [" << month << "] of year [" << year << "] is : " << NumberOfDaysInAMonth(year, month);
    cout << "\nNumber of hours   in month [" << month << "] of year [" << year << "] is : " << NumberOfHoursInAMonth(year, month);
    cout << "\nNumber of minutes in month [" << month << "] of year [" << year << "] is : " << NumberOfMinutesInAMonth(year, month);
    cout << "\nNumber of seconds in month [" << month << "] of year [" << year << "] is : " << NumberOfSecondsInAMonth(year, month) << endl;
}
