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


void swapDates(stDate &date1, stDate &date2) {
    stDate tempDate;
    tempDate.year = date2.year;
    tempDate.month = date2.month;
    tempDate.day = date2.day;

    date2.year = date1.year;
    date2.month = date1.month;
    date2.day = date1.day;

    date1.year = tempDate.year;
    date1.month = tempDate.month;
    date1.day = tempDate.day;

}


int calculateDifferenceInDays(stDate date1, stDate date2) {
    int days = 0;
    short swapFlag = 1;
    if (!isDate1BeforeDate2(date1, date2) == true) {
        swapDates(date1, date2);
        swapFlag = -1;
    }
    while (isDate1BeforeDate2(date1, date2) == true) {
        days++;
        increaseDateByOneDay(date1);
    }
    return days * swapFlag;
}

int main()
{
    stDate date1 = readDate();
    stDate date2 = readDate();
    cout << "\nDifference is  " << calculateDifferenceInDays(date1, date2) << " Day(s)";

}