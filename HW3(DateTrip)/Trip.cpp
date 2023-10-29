#include "Trip.h"
#include <string>
#include <iostream>
using namespace std;

//constructor
Trip::Trip(int tCode, string destination, Date tDate) {
	if (validate(tCode)) {
		code = tCode;
	}
	else {
		code = 0;
	}
	if (validate(destination)) {
		dst = destination;
	}
	else {
		dst = "Invalid";
	}

	date = tDate;
}

Trip::Trip(const Trip& other) {
	*this = other;
}

Trip::~Trip() {
}

//get
int Trip::getCode(){
	return this->code;
}

string Trip::getDst() {
	return this->dst;
}

Date Trip::getDate() {
	return this->date;
}

//set
void Trip::setCode(int nCode) {
	if (validate(nCode)) {
		this->code = nCode;
	}
	else {
		this->code = 0;
	}
}
void Trip::setDst(string nDst) {
	if (validate(nDst)) {
		this->dst = nDst;
	}
	else {
		this->dst = "Invalid";
	}
}
void Trip::setDate(Date nDate) {
	this->date = nDate;
}
//validate
bool Trip::validate(int number) {
	return number > 0;
}

bool Trip::validate(string destination) {
	for (int i = 0; destination[i] != '\0'; i++) {
		if (isdigit(destination[i])) {
			return false;
		}
	}
	return true;
}
//operator
const Trip& Trip::operator=(const Trip& other) {
	if (this != &other) {
		code = other.code;
		dst = other.dst;
		date = other.date;
	}
	return *this;
}
//print
void Trip::PrintTrip() {
	cout << "Trip info:\n" << "Code: " << this->getCode() << "\nDestination: " << this->getDst() << "\nDate: " << endl;
	this->getDate().PrintDate();
}