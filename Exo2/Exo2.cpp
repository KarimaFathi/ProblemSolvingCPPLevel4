#include <iostream>
using namespace std;


int readYear() {
    int year;
    cout << "\n\nPlease enter the year to check : ";
    cin >> year;
    return year;
}




bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if ((year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
            return true;
        }
        return false;
    }
    return false;
}


void printResult(bool isLeap) {
    if (isLeap == true) {
        cout << "\nYes, it is a leap year.\n";
    }
    else cout << "\nNo, it is not a leap year.\n";

}

int main()
{
    printResult(isLeapYear(readYear()));
}

