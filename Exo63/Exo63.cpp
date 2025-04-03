#include <iostream>
#include <vector>
#include <string>;
using namespace std;

struct stDate {
	short day, month, year;
};

string readString(string message) {
	string stringDate;
	cout << message;
	cin >> stringDate;
	return stringDate;
}

vector<string> splitString(string stringDate, string delim) {
	stDate date;
	short pos;
	vector<string> vec(3);
	short i = 0;
	while (pos = stringDate.find(delim) != std::string::npos) {
		pos = stringDate.find(delim);
		vec[i] = stringDate.substr(0, pos);
		i++;
		stringDate.erase(0, pos + delim.length());
	}
	vec[i] = stringDate;
	return vec;
}

stDate convertStringToDate(string stringDate) {
	stDate date;
	vector<string> vec(3);
    vec = splitString(stringDate, "/");
	date.day = stoi(vec[0]);
	date.month = stoi(vec[1]);
	date.year = stoi(vec[2]);
	return date;
}


int main()
{
	string dateString = readString("Please enter  date (dd/mm/yyyy): ");
	stDate date = convertStringToDate(dateString);
	cout << "\nDay : " << date.day;
	cout << "\nMonth : " << date.month;
	cout << "\nYear : " << date.year;

}

