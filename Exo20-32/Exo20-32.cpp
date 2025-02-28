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


int readNumber(string message) {
    int num;
    cout << message;
    cin >> num;
    return num;
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

stDate increaseDateByOneDay(stDate& date) {
    if (isDayLastInMonth(date) && isMonthLastInYear(date)) {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    else if (isDayLastInMonth(date) && !isMonthLastInYear(date)) {
        date.day = 1;
        date.month++;
    }
    else {
        date.day++;
    }
    return date;
}


stDate increaseDateByXDays(stDate& date, int daysToAdd) {
    for (int i = 1; i <= daysToAdd; i++) {
        increaseDateByOneDay(date);
    }
    return date;
}

stDate increaseDateByOneWeek(stDate& date) {
    for (int i = 1; i <= 7; i++) {
        increaseDateByOneDay(date);
    }
    return date;
}



int main()
{
    stDate date = readDate();
    cout << "\nDate after : \n";
    increaseDateByOneDay(date);
    cout << "\nAdding 1 day is : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXDays(date, 10);
    cout << "\nAdding 10 days is : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneWeek(date);
    cout << "\nAdding 1 week is : " << date.day << "/" << date.month << "/" << date.year;

}