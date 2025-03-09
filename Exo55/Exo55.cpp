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


stDate increaseDateByXDays(stDate& date, int daysToAdd) {
    for (int i = 1; i <= daysToAdd; i++) {
        increaseDateByOneDay(date);
    }
    return date;
}

bool isWeekEnd(stDate date) {
    return (findDayNumber(date.day, date.month, date.year) == 5 || findDayNumber(date.day, date.month, date.year) == 6);
}

stDate calculateReturnDateFromVacation(stDate& date, short vacationDays) {
    short weekEndsDays = 0;
    for (short i = 1; i <= vacationDays + weekEndsDays; i++) {
        if (isWeekEnd(date) == true) {
            weekEndsDays++;
        }
        increaseDateByOneDay(date);
  }
    while (isWeekEnd(date)) {
        increaseDateByOneDay(date);
   }
    return date;
}

short readNumber(string message) {
    short number;
    cout << message;
    cin >> number;
    return number;
}

int main()
{
    stDate date = readDate("\nVacation starts : ");
    short vacationDays = readNumber("\nPlease enter the vacation days : ");
    calculateReturnDateFromVacation(date, vacationDays);
    cout << "\nReturn date is : " << findDayName(findDayNumber(date.day, date.month, date.year)) << ", " << date.day << "/" << date.month << "/" << date.year << endl;

}
