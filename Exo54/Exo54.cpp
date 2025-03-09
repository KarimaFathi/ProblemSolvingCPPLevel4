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

bool isDate1BeforeDate2(stDate date1, stDate date2) {
    if (date1.year < date2.year) {
        return true;
    }
    else if (date1.year == date2.year) {

        if (date1.month < date2.month) {
            return true;
        }
        else if (date1.month == date2.month && date1.day < date2.day) {
            return true;
        }
    }
    else return false;
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

int calculateVacationDays(stDate date1, stDate date2) {
    int vacationDays = 0;
    while (isDate1BeforeDate2(date1, date2) == true) {
        if(findDayNumber(date1.day, date1.month, date1.year) != 5 && findDayNumber(date1.day, date1.month, date1.year) != 6)
        vacationDays++;
        increaseDateByOneDay(date1);
    }
    return vacationDays;
}



int main()
{
    stDate startDate = readDate("\nVacation starts : ");
    stDate endDate = readDate("\nVacation ends : ");
    cout << "\nVacation from : " << findDayName(findDayNumber(startDate.day, startDate.month, startDate.year)) << ", " << startDate.day << "/" << startDate.month << "/" << startDate.year << endl;
    cout << "\nVacation to : " << findDayName(findDayNumber(endDate.day, endDate.month, endDate.year)) << ", " << endDate.day << "/" << endDate.month << "/" << startDate.year << endl;
    cout << "\n\nActual vacation days : " << calculateVacationDays(startDate, endDate);
}

