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
void swapPeriods(stPeriod& period1, stPeriod& period2) {
    stPeriod tempPeriod;
    tempPeriod = period1;
    period1 = period2;
    period2 = period1;
}




bool isDate1EqualDate2(stDate date1, stDate date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
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

short countOverlapDays(stPeriod period1, stPeriod period2) {
    short counter = 0;
    if (isDate1BeforeDate2(period2.startDate, period1.startDate) == true) {
        swapPeriods(period1, period2);
    }
    if (arePeriodsOverLap(period1, period2) == true) {
        while (isDate1BeforeDate2(period2.startDate, period1.endDate) == true && isDate1EqualDate2(period2.startDate, period2.endDate) == false) {
            counter++;
            increaseDateByOneDay(period2.startDate);
            if (isDate1EqualDate2(period2.startDate, period2.endDate) == true) {
                counter++;
            }
        }
        return counter;
    }
    return 0;
}


int main()

{
    stPeriod period1 = readPeriod("Enter Period 1 :");
    stPeriod period2 = readPeriod("\nEnter Period 2 :");
    cout << "\nOverlap days count is : " << countOverlapDays(period1, period2);
}

