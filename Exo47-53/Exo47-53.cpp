#include <iostream>
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


short findDayNumber(short day, short month, short year) {
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


string findDayName(short dayNumber) {
    string daysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return daysName[dayNumber];
}

bool isWeekEnd(short dayOrder) {
    return (dayOrder == 5 || dayOrder == 6);
}

bool isEndOfWeek(short dayOrder) {
    return dayOrder == 6;
}

bool isBusinessDay(short dayOrder) {
    return !isWeekEnd(dayOrder);
}

short determineDaysUntilTheEndOfWeek(short dayNumber) {
    short daysBeforeEndOfWeek = 0;
    while (dayNumber != 6) {
        daysBeforeEndOfWeek++;
        dayNumber++;
    }
    return daysBeforeEndOfWeek;
}

bool isLeapYear(short year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInAMonth(short year, short month) {
    if (month < 1 || month > 12) {
        return 0;
    }
    if (month == 2) {
        return (isLeapYear(year) ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

short determineDaysUntilTheEndOfMonth(stDate date) {
    return NumberOfDaysInAMonth(date.year, date.month) - date.day + 1;
}

short NumberOfDaysFromTheBeginningOfTheYear(short year, short month, short day) {
    short result = 0;
    for (short i = 1; i < month; i++) {
        result += NumberOfDaysInAMonth(year, i);
    }
    result += day;
    return result;
}


short determineDaysUntilTheEndOfYear(stDate date) {
    short daysOfYear = (isLeapYear(date.year) ? 366 : 365);
    return daysOfYear - NumberOfDaysFromTheBeginningOfTheYear(date.year, date.month, date.day) + 1;
}

int main() {
    stDate date = readDate();
    short dayOrder = findDayNumber(date.day, date.month, date.year);
    string dayName = findDayName(findDayNumber(date.day, date.month, date.year));
    cout << "\nToday is " << dayName << ", " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "\nIs it a weekend ?\n";
    if (isWeekEnd(dayOrder) == true) {
        cout << "Yes, it is a weekend.\n";
    }
    else {
        cout << "No, it is not a weekend.\n";
    }
    cout << "\nIs it an end of week ?\n";
    if (isEndOfWeek(dayOrder) == true) {
        cout << "Yes, it is.\n";
    }
    else {
        cout << "No, it isn't.\n";
    }
    cout << "\nIs it a business day?\n";
    if (isBusinessDay(dayOrder) == true) {
        cout << "Yes, it is.\n";
    }
    else {
        cout << "No, it isn't.\n";
    }
    cout << "\nDays until end of week  : " << determineDaysUntilTheEndOfWeek(findDayNumber(date.day, date.month, date.year)) << " day(s)";
    cout << "\nDays until end of month : " << determineDaysUntilTheEndOfMonth(date) << " day(s)";
    cout << "\nDays until end of year  : " << determineDaysUntilTheEndOfYear(date) << " day(s)";

}