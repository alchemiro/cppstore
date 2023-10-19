#include "Date.h"
#include "iostream"
using namespace std;

Date::Date(int dateDay, int dateMonth, int dateYear) {
	if (dateDay < 1 || dateDay > 30) {
		day = 0;
	}
	else {
		day = dateDay;
	}

	if (dateMonth < 1 || dateMonth > 12) {
		month = 0;
	}
	else {
		month = dateMonth;
	}

	if (dateYear < 0) {
		year = 0;
	}
	else {
		year = dateYear;
	}
}

void Date::setDay(int newDay) {
	if (newDay < 1 || newDay > 30) {
		day = 0;
	}
	else {
		day = newDay;
	}
}

void Date::setMonth(int newMonth) {
	if (newMonth < 1 || newMonth > 12) {
		month = 0;
	}
	else {
		month = newMonth;
	}
}

void Date::setYear(int newYear) {
	if (newYear < 0) {
		year = 0;
	}
	else {
		year = newYear;
	}
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

void Date::printDate() {
	cout << getMonth() << "/" << getDay() << "/" << getYear << endl;
}