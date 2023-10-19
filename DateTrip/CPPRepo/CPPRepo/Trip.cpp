#include "Trip.h"
#include "Date.h"
#include "string"
#include "iostream"

using namespace std;

Trip::Trip(int tNumber, string tDst, Date tDate) {

	bool hasNumbers = false;

	number = tNumber < 1 ? 1 : tNumber;

	for (int i = 0; i < tDst.length(); i++) {
		if (isdigit(tDst[i])){
			hasNumbers = true;
		}
	}

	destination = hasNumbers ? "Invalid" : tDst;

	date = tDate;
}

Trip::Trip(Trip &tTrip) {
	number = tTrip.getNumber();
	destination = nullptr;
	date = tTrip.getDate();
}

Trip& Trip::operator=(Trip &tTrip) {
	Trip(tTrip);
	return *this;
}



Trip::~Trip() {
	destination.clear();
}

void Trip::setNumber(int tNumber) {
	number = tNumber < 1 ? 1 : tNumber;
}

void Trip::setDestination(string tDst) {
	bool hasNumbers = false;

	for (int i = 0; i < tDst.length(); i++) {
		if (isdigit(tDst[i])) {
			hasNumbers = true;
		}
	}

	destination = hasNumbers ? "Invalid" : tDst;
}

void Trip::setDate(Date tDate) {
	date = tDate;
}

int Trip::getNumber() {
	return number;
}

string Trip::getDestination() {
	return destination;
}

Date Trip::getDate() {
	return date;
}

void Trip::printTrip() {
	cout << "Trip Number: " << getNumber() << ", Trip Destination: " << getDestination() << ", Trip Date: " << endl;
	getDate().printDate();
}

