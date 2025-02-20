#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


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


short findDayNumber(short day, short month, short year) {
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
    };
    return (Months[MonthNumber - 1]);
}

void printMonthCalendar(short year, short month) {
    short daysOfMonth = NumberOfDaysInAMonth(year, month);
    short current = findDayNumber(1, month, year);
    string monthName[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    printf("\n _______________%s_______________\n\n", MonthShortName(month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    short i;
    for (i = 0; i < current; i++)
        cout << "     ";
   
    for (short j = 1; j <= daysOfMonth; j++) {
        printf("%5d", j);
        i++;
        if (i == 7) {
            i = 0;
            cout << endl;
        }
    }
    cout << "\n __________________________________ \n\n";
}

void printYearCalendar(short year) {
    printf("\n _________________________________\n\n");
    printf("        Calendar - %d\n", year);
    printf(" _________________________________\n");
    for (short i = 1; i <= 12; i++) {
        printMonthCalendar(year, i);
    }
}


int main()
{
    short year = readNumber("Please enter a year : ");
    printYearCalendar(year);
}
