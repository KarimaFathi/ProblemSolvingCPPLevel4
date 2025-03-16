#include <iostream>
using namespace std;


struct stDate {
    short day, month, year;
};

enum enDateComparison {before = -1, equal = 0, after = 1};

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


bool isDate1AfterDate2(stDate date1, stDate date2) {
    return !isDate1BeforeDate2(date1, date2);
}


bool isDate1EqualDate2(stDate date1, stDate date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

enDateComparison compareDates(stDate date1, stDate date2) {
    return isDate1BeforeDate2(date1, date2) ? ::before : isDate1AfterDate2(date1, date2) ? ::after : ::equal;
}


int main()
{
    enDateComparison dateComparison;
    stDate date1 = readDate("\nPlease enter date 1 : \n");
    stDate date2 = readDate("\nPlease enter date 2 : \n");
   cout << "\nComparison result : " << compareDates(date1, date2); 
   
}
    
