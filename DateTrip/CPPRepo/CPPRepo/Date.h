#pragma once
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day=1, int month=1, int year=2000);

	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	int getDay();
	int getMonth();
	int getYear();

	void printDate();
};

