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

stDate increaseDateByXWeeks(stDate& date, int weeksToAdd) {
    for (int i = 1; i <= weeksToAdd; i++) {
        for (int j = 1; j <= 7; j++) {
            increaseDateByOneDay(date);
        }
    }
    return date;
}

stDate increaseDateByOneMonth(stDate& date) {
    if (date.month == 12) {
        date.month = 1;
        date.year++;
       }
    else {
        date.month++;
    }
    short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
    if (date.day > numberOfDaysInCurrentMonth) {
        date.day = numberOfDaysInCurrentMonth;
    }
    return date;
}

stDate increaseDateByXMonth(stDate& date, int monthsToAdd) {
    for (int i = 1; i <= monthsToAdd; i++) {
            increaseDateByOneMonth(date);
        
    }
    return date;
}

stDate increaseDateOneYear(stDate& date) {
    if (date.month == 2) {
        short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
        if (date.day > numberOfDaysInCurrentMonth) {
            date.day = numberOfDaysInCurrentMonth;
        }
    }
    date.year++;
    return date;
}

stDate increaseDateByXYears(stDate& date, int yearsToAdd) {
    for (int i = 1; i <= yearsToAdd; i++) {
        increaseDateOneYear(date);

    }
    return date;
}

stDate increaseDateByOneDecade(stDate& date) {
    for (int i = 1; i <= 10; i++) {
        increaseDateOneYear(date);

    }
    return date;
}

stDate increaseDateByXDecades(stDate& date, int decadesToAdd) {
    for (int i = 1; i <= decadesToAdd; i++) {
        increaseDateByOneDecade(date);

    }
    return date;
}

stDate increaseDateByOneCentury(stDate& date) {
    for (int i = 1; i <= 10; i++) {
        increaseDateByOneDecade(date);

    }
    return date;
}

stDate increaseDateByOneMillennium(stDate& date) {
    for (int i = 1; i <= 10; i++) {
        increaseDateByOneCentury(date);

    }
    return date;
}

int main()
{
    stDate date = readDate();
    cout << "\nDate after : \n";
    increaseDateByOneDay(date);
    cout << "\nAdding 1    day       is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXDays(date, 10);
    cout << "\nAdding 10   days      is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneWeek(date);
    cout << "\nAdding 1    week      is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXWeeks(date, 10);
    cout << "\nAdding 10   weeks     is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneMonth(date);
    cout << "\nAdding 1    month     is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXMonth(date, 5);
    cout << "\nAdding 5    months    is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateOneYear(date);
    cout << "\nAdding 1    year      is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXYears(date, 10);
    cout << "\nAdding 10   years     is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneDecade(date);
    cout << "\nAdding 1    decade    is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByXDecades(date, 10);
    cout << "\nAdding 10  decades    is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneCentury(date);
    cout << "\nAdding 1  century     is   : " << date.day << "/" << date.month << "/" << date.year;
    increaseDateByOneMillennium(date);
    cout << "\nAdding 1  millennium  is   : " << date.day << "/" << date.month << "/" << date.year;
    
}