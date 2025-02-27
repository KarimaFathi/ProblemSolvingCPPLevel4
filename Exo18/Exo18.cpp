#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short day, month, year;
};

stDate readDate() {
    stDate date;
    cout << "\nPlease enter your date of birth : \n\n";
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
stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;
    Date.day = now->tm_mday;
    return Date;
}


int convertAgeToDays(stDate date1, stDate date2) {
    int days = 0;
    while (isDate1BeforeDate2(date1, date2) == true) {
        days++;
        increaseDateByOneDay(date1);
    }
    return days;
}




int main()
{
    stDate date1 = readDate();
    stDate date2 = GetSystemDate();
    cout << "\nYour age is days is : " << convertAgeToDays(date1, date2) << " day(s)\n";
}


