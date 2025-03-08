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

bool isWeekEnd(string dayName) {
    return (dayName == "Fri" || dayName == "Sat");
}

int main() {
    stDate date = readDate();
    string dayName = findDayName(findDayNumber(date.day, date.month, date.year));
    cout << "\nToday is " << dayName << ", " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "\nIs it a weekend ?\n";
    if (isWeekEnd(dayName) == true) {
        cout << "Yes, it is a weekend.\n";
    }
    else {
        cout << "No, it is not a weekend.\n";
    }

}