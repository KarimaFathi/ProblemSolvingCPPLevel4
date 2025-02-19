#include <iostream>
#include <string>
using namespace std;

short readNumber(string message) {
    short number;
    cout << message;
    cin >> number;
    return number;
}

short findDayNumber(short day, short month, short year) {
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))%7;
}


string findDayName(short dayNumber) {
    string daysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return daysName[dayNumber];
}

int main()
{
    short year = readNumber("\nPlease enter a year : ");
    short month = readNumber("\n\nPlease enter a month : ");
    short day = readNumber("\n\nPlease enter a day : ");
    short dayNumber = findDayNumber(day, month, year);

    cout << "\nDate          : " << day << "/" << month << "/" << year;
    cout << "\nDay order     : " << dayNumber;
    cout << "\nDay name      : " << findDayName(dayNumber);
}

