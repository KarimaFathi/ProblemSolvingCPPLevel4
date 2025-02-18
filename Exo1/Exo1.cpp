#include <iostream>
#include <string>
#include <vector>
using namespace std;




long long int readNumber() {
    long long int number;
    cout << "\n\nEnter a number : ";
    cin >> number;
    return number;
}


string convertNumberToWords(long long int number) {
    if (number >= 0 && number <= 19) {
        vector<string> vec1 = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        return vec1[number] + " ";
    }
    if (number >= 20 && number <= 99) {
        vector<string> vec2 = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        return vec2[number / 10] + "-" + convertNumberToWords(number % 10);
    }
    if (number >= 100 && number <= 999) {
        if (number % 100 == 0) {
            return convertNumberToWords(number / 100) + "hundred";
        }
        else {
            return convertNumberToWords(number / 100) + "hundred and " + convertNumberToWords(number % 100);
        }
    }
    if (number >= 1000 && number <= 999999) {
        if (number % 1000 == 0) {
            return convertNumberToWords(number / 1000) + "thousand";
        }
        else return convertNumberToWords(number / 1000) + "thousand " + convertNumberToWords(number % 1000);
    }
    if (number >= 1000000 && number <= 999999999) {
        if (number % 1000000 == 0) {
            return convertNumberToWords(number / 1000000) + "million";
        }
        else return convertNumberToWords(number / 1000000) + "million " + convertNumberToWords(number % 1000000);
    }
    if (number >= 1000000000 && number <= 999999999999) {
        if (number % 1000000000 == 0) {
            return convertNumberToWords(number / 1000000000) + "billion";
        }
        else return convertNumberToWords(number / 1000000000) + "billion " + convertNumberToWords(number % 1000000000);
    }


}


int main()
{
    long long int number = readNumber();
    cout << convertNumberToWords(number) << endl;
}

