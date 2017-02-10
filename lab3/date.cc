#include <ctime>  // time and localtime
#include <string>
#include <iostream>
#include <iomanip>
#include <regex>
#include "date.h"

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(day + 1 > daysPerMonth[month - 1]) {
		day = 1;

		if(month + 1 > 12) {
			month = 1;
			year += 1;
		} else {
			month += 1;
		}

	} else {
		day += 1;
	}
}

istream& operator>>(istream& is, Date& date) {
	string line;
	getline(is, line);
	line = regex_replace(line, regex("\\s*"), "");

	size_t first = line.find("-");
	size_t second = line.rfind("-");

	string y = line.substr(0, first);
	string m = line.substr(first + 1, second - first - 1);
	string d = line.substr(second + 1);

	int i_y = stoi(y);
	int i_m = stoi(m);
	int i_d = stoi(d);

	if(i_y > 0 && i_m > 0 && i_m < 13 && i_d > 0 && i_d <= date.daysPerMonth[i_m - 1]) {
		date.year = i_y;
		date.month = i_m;
		date.day = i_d;
	} else {
		is.setstate(ios_base::failbit);
	}

	return is;
}

ostream& operator<<(ostream& os, Date& date) {
	os << date.year << "-" << setfill('0') << setw(2) << date.month << "-" << setfill('0') << setw(2) << date.day << endl;
	return os;
}
