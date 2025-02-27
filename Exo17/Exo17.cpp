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


int calculateDifferenceInDays(stDate date1, stDate date2) {
    short date1NumOfDays = NumberOfDaysFromTheBeginningOfTheYear(date1.year, date1.month, date1.day);
    short date2NumOfDays = NumberOfDaysFromTheBeginningOfTheYear(date2.year, date2.month, date2.day);
    int differenceResult;
    int daysOfYearsInBetween = 0;
    if (date1.year == date2.year) {
       
          if (date1NumOfDays > date2NumOfDays) {
              differenceResult = date1NumOfDays - date2NumOfDays;
          }
          else {
              differenceResult = date2NumOfDays - date1NumOfDays;
          }
    }
    else if (date1.year < date2.year) {
        for (int i = (date1.year + 1); i < date2.year; i++) {
            daysOfYearsInBetween += (isLeapYear(i) ? 366 : 365);
        }
        differenceResult = daysOfYearsInBetween + ((isLeapYear(date1.year) ? 366 : 365) - date1NumOfDays) + date2NumOfDays;
    }
    else {
        for (int i = (date2.year + 1); i < date1.year; i++) {
            daysOfYearsInBetween += (isLeapYear(i) ? 366 : 365);
        }
        differenceResult = daysOfYearsInBetween + ((isLeapYear(date2.year) ? 366 : 365) - date2NumOfDays) + date1NumOfDays;
    }
    return differenceResult;
}

int main()
{
    stDate date1 = readDate();
    stDate date2 = readDate();
    cout << "\nDifference is  " << calculateDifferenceInDays(date1, date2) << " Day(s)";

}