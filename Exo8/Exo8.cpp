#include <iostream>
#include <string>
#include <iomanip>
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


void printMonthCalendar(short year, short month) {
    short daysOfMonth = NumberOfDaysInAMonth(year, month);
    string monthName[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    cout << "\n\n  ________________" << monthName[month] << "______________  \n\n";
    string daysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    for (int i = 0; i < 7; i++) {
        cout << "  " << daysName[i];
    }
    cout << endl;
    for (int i = 0; i < 7; i++) {
        if (findDayNumber(1, month, year) == i) {
            for (int j = 1; j <= daysOfMonth; j++) {
                if (j == 1 && findDayName(findDayNumber(j, month, year)) == "Sat") {
                    cout << setw(5 * i + 5) << j << endl;
               }
                else if (j != 1 && findDayName(findDayNumber(j, month, year)) == "Sat") {
                    cout << setw(5) << j << endl;
                }
                else if (j != 1 && findDayName(findDayNumber(j, month, year)) != "Sat") {
                    cout << setw(5) << j;
                }
                else {
                    cout << setw(5 * i + 5) << j;
                }
            }
        }
    }
    cout << "\n  __________________________________  \n\n";
}

int main()
{
    short year = readNumber("Please enter a year : ");
    short month = readNumber("\nPlease enter a month : ");
    printMonthCalendar(year, month);
}

