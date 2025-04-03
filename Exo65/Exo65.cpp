#include <iostream>
#include <string>
#include <vector>
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


string replaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),
			sReplaceTo);
		pos = S1.find(StringToReplace);//find next
	}
	return S1;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = replaceWordInString(DateFormat, "dd",
		to_string(Date.day));
	FormattedDateString = replaceWordInString(FormattedDateString,
		"mm", to_string(Date.month));
	FormattedDateString = replaceWordInString(FormattedDateString,
		"yyyy", to_string(Date.year));
	return FormattedDateString;
}
int main()
{
	string dateString = readString("\nPlease Enter Date (dd / mm / yyyy) ? ");
		stDate Date = convertStringToDate(dateString);
	cout << "\n" << FormatDate(Date) << "\n";
	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
   system("pause>0");
	return 0;
}
