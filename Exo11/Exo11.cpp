#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short year, month, day;
};


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


short NumberOfDaysFromTheBeginningOfTheYear(short year, short month, short day) {
    short result = 0;
    for (short i = 1; i < month; i++) {
        result += NumberOfDaysInAMonth(year, i);
    }
    result += day;
    return result;
}


stDate getDateFromNumberOfDays(short daysNumbers, short year) {
    stDate date;
    short numberOfMonths;
    short yearDays = isLeapYear(year) ? 366 : 365;
    short arrMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    short result = 0;
    arrMonths[1] = isLeapYear(year) ? 29 : 28;
    for (int i = 1; i <= 12; i++) {
        result += arrMonths[i - 1];
        if (result >= daysNumbers) {
            date.month = i;
            result = (result - daysNumbers);
            date.day = (NumberOfDaysInAMonth(year, i) - result);
            break;
        }
       }
    date.year = year;
    return date;
}



int main()
{

    short year = readNumber("\nPlease enter a year : ");
    short days = readNumber("\nPlease enter the number of days : ");
    stDate date = getDateFromNumberOfDays(days, year);
    cout << "\nThe date of [" << days << "] is : " << date.day << "/" << date.month << "/" << date.year;

}
