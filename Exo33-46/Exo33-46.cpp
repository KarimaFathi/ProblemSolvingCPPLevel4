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


bool isDayFirstInMonth(stDate date) {
    return (date.day == 1);
}

bool isMonthFirstInYear(stDate date) {
    return (date.month == 1);
}

stDate decreaseDateByOneDay(stDate& date) {
    if (isDayFirstInMonth(date) && isMonthFirstInYear(date)) {
        date.day = 31;
        date.month = 12;
        date.year--;
    }
    else if (isDayFirstInMonth(date) && !isMonthFirstInYear(date)) {
        date.month--;
        date.day = NumberOfDaysInAMonth(date.year, date.month);
    }
    else {
        date.day--;
    }
    return date;
}

stDate decreaseDateByXDays(stDate& date, int daysToSubtract) {
    for (int i = 1; i <= daysToSubtract; i++) {
        decreaseDateByOneDay(date);
    }
    return date;
}

stDate decreaseDateByOneWeek(stDate& date) {
    for (int i = 1; i <= 7; i++) {
        decreaseDateByOneDay(date);
    }
    return date;
}

stDate decreaseDateByXWeeks(stDate& date, int weeksToSubtract) {
    for (int i = 1; i <= weeksToSubtract; i++) {
        for (int j = 1; j <= 7; j++) {
            decreaseDateByOneDay(date);
        }
    }
    return date;
}

stDate decreaseDateByOneMonth(stDate& date) {
    if (date.month == 1) {
        date.month = 12;
        date.year--;
    }
    else {
        date.month--;
    }
    short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
    if (date.day > numberOfDaysInCurrentMonth) {
        date.day = numberOfDaysInCurrentMonth;
    }
    return date;
}

stDate decreaseDateByXMonth(stDate& date, int monthsToSubtract) {
    for (int i = 1; i <= monthsToSubtract; i++) {
        decreaseDateByOneMonth(date);

    }
    return date;
}

//stDate increaseDateOneYear(stDate& date) {
//    if (date.month == 2) {
//        short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
//        if (date.day > numberOfDaysInCurrentMonth) {
//            date.day = numberOfDaysInCurrentMonth;
//        }
//    }
//    date.year++;
//    return date;
//}
//
//stDate increaseDateByXYears(stDate& date, int yearsToAdd) {
//    for (int i = 1; i <= yearsToAdd; i++) {
//        increaseDateOneYear(date);
//
//    }
//    return date;
//}
//
//stDate increaseDateByOneDecade(stDate& date) {
//    for (int i = 1; i <= 10; i++) {
//        increaseDateOneYear(date);
//
//    }
//    return date;
//}
//
//stDate increaseDateByXDecades(stDate& date, int decadesToAdd) {
//    for (int i = 1; i <= decadesToAdd; i++) {
//        increaseDateByOneDecade(date);
//
//    }
//    return date;
//}
//
//stDate increaseDateByOneCentury(stDate& date) {
//    for (int i = 1; i <= 10; i++) {
//        increaseDateByOneDecade(date);
//
//    }
//    return date;
//}
//
//stDate increaseDateByOneMillennium(stDate& date) {
//    for (int i = 1; i <= 10; i++) {
//        increaseDateByOneCentury(date);
//
//    }
//    return date;
//}

int main()
{
    stDate date = readDate();
    cout << "\nDate after : \n";
    decreaseDateByOneDay(date);
    cout << "\nSubtracting 1    day       is   : " << date.day << "/" << date.month << "/" << date.year;
    decreaseDateByXDays(date, 10);
    cout << "\nSubtracting 10   days      is   : " << date.day << "/" << date.month << "/" << date.year;
    decreaseDateByOneWeek(date);
    cout << "\nSubtracting 1    week      is   : " << date.day << "/" << date.month << "/" << date.year;
    decreaseDateByXWeeks(date, 10);
    cout << "\nSubtracting 10   weeks     is   : " << date.day << "/" << date.month << "/" << date.year;
    decreaseDateByOneMonth(date);
    cout << "\nSubtracting 1    month     is   : " << date.day << "/" << date.month << "/" << date.year;
    decreaseDateByXMonth(date, 5);
    cout << "\nSubtracting 5    months    is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateOneYear(date);
    //cout << "\nAdding 1    year      is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateByXYears(date, 10);
    //cout << "\nAdding 10   years     is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateByOneDecade(date);
    //cout << "\nAdding 1    decade    is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateByXDecades(date, 10);
    //cout << "\nAdding 10  decades    is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateByOneCentury(date);
    //cout << "\nAdding 1  century     is   : " << date.day << "/" << date.month << "/" << date.year;
    //increaseDateByOneMillennium(date);
    //cout << "\nAdding 1  millennium  is   : " << date.day << "/" << date.month << "/" << date.year;

}