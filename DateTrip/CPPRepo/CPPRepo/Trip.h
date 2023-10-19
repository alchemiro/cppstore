#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Trip
{
private:
	int number;
	string destination;
	Date date;
public:
	Trip(int newNumber = 0, string newDst = "Unknown", Date newDate = Date());
	Trip(Trip &tTrip);
	Trip& operator = (Trip& tTrip);
	~Trip();

	void setNumber(int newNumber);
	void setDestination(string newDst);
	void setDate(Date newDate);

	int getNumber();
	string getDestination();
	Date getDate();

	void printTrip();
};

