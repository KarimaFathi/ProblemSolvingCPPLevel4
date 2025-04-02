#include <iostream>
using namespace std;


struct stDate {
    short day, month, year;
};

struct stPeriod {
    stDate startDate;
    stDate endDate;
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

stPeriod readPeriod(string message) {
    stPeriod period;
    stDate date1;
    stDate date2;
    cout << message;
    period.startDate = readDate("\nEnter start date : \n");
    period.endDate = readDate("\nEnter end date : \n");
    return period;
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


bool isDate1EqualDate2(stDate date1, stDate date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}


void swapPeriods(stPeriod& period1, stPeriod& period2) {
    stPeriod tempPeriod;
    tempPeriod = period1;
    period1 = period2;
    period2 = period1;
}



bool arePeriodsOverLap(stPeriod period1, stPeriod period2) {
    if (isDate1BeforeDate2(period2.startDate, period1.startDate) == true) {
        swapPeriods(period1, period2);
    }
    if (isDate1BeforeDate2(period2.startDate, period1.endDate) == true || isDate1EqualDate2(period2.startDate, period1.endDate) == true || isDate1EqualDate2(period1.startDate, period2.startDate) == true) {
            return true;
    }
    
    return false;
}

int main()
{
    stPeriod period1 = readPeriod("Enter Period 1 :");
    stPeriod period2 = readPeriod("\nEnter Period 2 :");
    if (arePeriodsOverLap(period1, period2) == true) {
        cout << "\nYes, Periods overlap";
    }
    else {
        cout << "\nNo, Periods don't overlap.";
    }
}

