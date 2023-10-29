#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int nDay, int nMonth, int nYear) {
	if (validate(nDay, 1)) {
		day = nDay;
	}
	else {
		day = 0;
	}
	if (validate(nMonth, 2)) {
		month = nMonth;
	}
	else {
		month = 0;
	}
	if (validate(nYear,3)) {
		year = nYear;
	}
	else {
		year = 0;
	}
}

//get
int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}

//set
void Date::setDay(int newDay) { //must validate
	if (validate(newDay, 1)) {
		this->day = newDay;
	}
	else {
		this->day = 0;
	}
}

void Date::setMonth(int newMonth) {
	if (validate(newMonth, 2)) {
	this->month = newMonth;
	}
	else {
		this->month = 0;
	}
}

void Date::setYear(int newYear) {
	if (validate(newYear, 3)) {
		this->year = newYear;
	}
	else {
		this->year = 0;
	}
}
//validate

bool Date::validate(int number, int type) {
	switch (type) {
	case 1: //day
		return number <= 30 && number >= 1;
	case 2: //month
		return number <= 12 && number >= 1;
	case 3:
		return number > 0;
	default:
		return false;
	}
}
//print

void Date::PrintDate() {
	cout << this->getDay() << "/" << this->getMonth() << "/" << this->getYear() << endl;
}