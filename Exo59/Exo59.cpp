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


short calculateDateInPeriod(stPeriod period, bool isLastDayIncluded) {
    short counter = 0;
    while (isDate1BeforeDate2(period.startDate, period.endDate) == true) {
        counter++;
        increaseDateByOneDay(period.startDate);
    }
    if (isLastDayIncluded == false) {
        return counter;
    }
    else return counter + 1;
}


int main()
{
    stPeriod period = readPeriod("Enter Period :");
    cout << "\nPeriod length is : " << calculateDateInPeriod(period, false);
    cout << "\nPeriod length including last day is : " << calculateDateInPeriod(period, true);
}
