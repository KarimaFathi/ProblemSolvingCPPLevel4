
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

bool isDateWithinPeriod(stPeriod period, stDate date) {
    return (isDate1BeforeDate2(date, period.endDate) == true || isDate1EqualDate2(date, period.endDate) == true || isDate1EqualDate2(date, period.startDate) == true);
}


int main()
{
    stPeriod period = readPeriod("Enter Period :");
    stDate date = readDate("\nEnter Date To Check :");
    if (isDateWithinPeriod(period, date) == true) {
        cout << "\nYes, date is within period.";
    }
    else {
        cout << "\nNo, date isn't within period.";
    }
}

