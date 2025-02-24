#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short year, month, day;
};


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


short NumberOfDaysFromTheBeginningOfTheYear(short year, short month, short day) {
    short result = 0;
    for (short i = 1; i < month; i++) {
        result += NumberOfDaysInAMonth(year, i);
    }
    result += day;
    return result;
}


//stDate addDaysToDate(short day, short month, short year, short daysToAdd) {
//    stDate date;
//        short numberOfMonths;
//        short yearDays ;
//        short arrMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        while (daysToAdd > isLeapYear(year) ? 366 : 365) {
//            daysToAdd = daysToAdd - (isLeapYear(year) ? 366 : 365);
//            year++;
//        }
//       year--;
//       short i = month - 1;
//        arrMonths[1] = isLeapYear(year) ? 29 : 28;
//        while( daysToAdd > arrMonths[i]) {
//                daysToAdd -= arrMonths[i];
//                if (i < 11) {
//                    i++;
//                    month = i;
//
//                }
//                else {
//                    i = 0;
//                    year += 1;
//                    month = i + 1;
//                    arrMonths[1] = isLeapYear(year) ? 29 : 28;
//                }
//        }
//        if (daysToAdd + day <= arrMonths[month]) {
//            date.day = daysToAdd + day;
//            date.month = month;
//            date.year = year;
//        }
//        else {
//            date.day = daysToAdd + day - arrMonths[month];
//            if ((month + 1) > 12) {
//                date.month = 1;
//                date.year = year + 1;
//            }
//            else {
//                date.month = month;
//                date.year = year;
//            }
//        }
//
//        return date;  
//}

stDate addDaysToDate(short day, short month, short year, short daysToAdd) {
    stDate date;
    short remainingDays = NumberOfDaysFromTheBeginningOfTheYear(year, month, day) + daysToAdd;
    date.month = 1;
    date.year = year;
    while (true) {
        if (remainingDays > NumberOfDaysInAMonth(date.year, date.month)) {
            remainingDays -= NumberOfDaysInAMonth(date.year, date.month);
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
        else {
            date.day = remainingDays;
            break;
        }

    }
    return date;
}



int main()
{

    short year = readNumber("\nPlease enter a year : ");
    short day = readNumber("\nPlease enter a day : ");
    short month = readNumber("\nPlease enter a month : ");
    short daysToAdd = readNumber("\nPlease enter the number of days you want to add : ");

    stDate date = addDaysToDate(day, month, year, daysToAdd);
    cout << "\nThe date after adding [" << daysToAdd << "] days is : " << date.day << "/" << date.month << "/" << date.year;

}