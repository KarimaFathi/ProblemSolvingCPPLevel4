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


short NumberOfDaysFromTheBeginningOfTheYear(short year, short month, short day) {
    short result = 0;
    for (short i = 1; i < month; i++) {
        result += NumberOfDaysInAMonth(year, i);
    }
    result += day;
    return result;
}

void compareDates(stDate date1, stDate date2) {
    if (date1.year == date2.year) {
        if (NumberOfDaysFromTheBeginningOfTheYear(date1.year, date1.month, date1.day) > NumberOfDaysFromTheBeginningOfTheYear(date2.year, date2.month, date2.day)) {
            cout << "date2 is less then date1\n";
        }
        else if (NumberOfDaysFromTheBeginningOfTheYear(date1.year, date1.month, date1.day) < NumberOfDaysFromTheBeginningOfTheYear(date2.year, date2.month, date2.day)) {
            cout << "date1 is less then date2\n";
        }
        else {
            cout << "date1 is equal to date2\n";
        }
    }
    else if (date1.year > date2.year) {
        cout << "date2 is less then date1\n";
    }
    else cout << "date1 is less then date2\n";

}

int main()
{
    stDate date1 = readDate();
    stDate date2 = readDate();
    compareDates(date1, date2);

}


