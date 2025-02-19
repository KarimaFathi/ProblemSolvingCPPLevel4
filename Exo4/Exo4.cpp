#include <iostream>
using namespace std;

short readYear() {
    short year;
    cout << "\n\nPlease enter the year to check : ";
    cin >> year;
    return year;
}

bool isLeapYear(short year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

}

short NumberOfDaysInAYear(short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}
int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}



int main()
{
    short year = readYear();
    cout << "\nNumber of days    in year [" << year << "] is : " << NumberOfDaysInAYear(year);
    cout << "\nNumber of hours   in year [" << year << "] is : " << NumberOfHoursInAYear(year);
    cout << "\nNumber of minutes in year [" << year << "] is : " << NumberOfMinutesInAYear(year);
    cout << "\nNumber of seconds in year [" << year << "] is : " << NumberOfSecondsInAYear(year) << endl;
}

