#include <string>
#include "Date.h"
#include <iostream>
#pragma once
using namespace std;

class Trip
{

private:
	int code;
	string dst;
	Date date;
public:
	//constructor
	Trip(int tCode = 1, string tDst = "Unknown", Date tDate = Date());
	Trip(const Trip& other);
	~Trip();
	//get
	int getCode();
	string getDst();
	Date getDate();
	//set
	void setCode(int newCode);
	void setDst(string newDst);
	void setDate(Date newDate);
	//validate
	bool validate(int tCode);
	bool validate(string tDst);
	//operator
	const Trip& operator=(const Trip& oTrip); 
	//print
	void PrintTrip();
};

