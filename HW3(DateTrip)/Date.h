#pragma once
class Date
{
private:
	int day; //1-30
	int month; // 1-12
	int year; // 0+
public:
	//constructor
	Date(int nDay = 1, int nMonth = 1, int nYear = 2000);

	//get
	int getDay(); //this
	int getMonth();
	int getYear();

	//set
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	//validate
	bool validate(int number, int type); //type is day/month/year ; 1 = day, 2 = month; 3 = year

	void PrintDate(); // print in DD/MM/YY
	//validate(25,1) = true;
	//validate(25,2) = false;
	//validate(25,3) = true;
};

