#include <iostream>
#include <string>
using namespace std;



struct stDate {
    short day, month, year;
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

string convertDateToString(stDate date) {
    string strDate;
    strDate = to_string(date.day) + '/' + to_string(date.month) + '/' + to_string(date.year);
    return strDate;
}



int main()
{
    stDate date = readDate("Please enter date : ");
    string stringDate = convertDateToString(date);
    cout << "\nYou entered : " << stringDate;
}

