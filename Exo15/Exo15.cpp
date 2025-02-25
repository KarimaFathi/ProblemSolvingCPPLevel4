#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short day, month, year;
};


stDate readDate() {
    stDate date;
    cout << "\n------------------------------\n\n";
    cout << "Please enter a day : ";
    cin >> date.day;
    cout << "Please enter a month : ";
    cin >> date.month;
    cout << "Please enter a year : ";
    cin >> date.year;
    cout << "\n------------------------------\n";
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


bool isDayLastInMonth(stDate date) {
    short DaysInMonth = NumberOfDaysInAMonth(date.year, date.month);
    return (date.day == DaysInMonth);
}

bool isMonthLastInYear(stDate date) {
    return (date.month == 12);
}


int main()
{
    stDate date = readDate();
    if (isDayLastInMonth(date) == true) {
        cout << "Yes, " << date.day << " is the last day in month " << date.month;
    }
    else {
        cout << "No, " << date.day << " is not the last  day in month " << date.month;
    }
    if (isMonthLastInYear(date) == true) {
        cout << "\nYes, " << date.month << " is the last month in year " << date.year;
    }
    else {
        cout << "\nNo, " << date.month << " is not the last  month in year " << date.year;
    }
}