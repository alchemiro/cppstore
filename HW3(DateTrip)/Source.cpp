#include <iostream>
#include "Date.h"
#include "Trip.h"
using namespace std;

bool isEmpty(int size);
void PrintTrips(Trip* arr, int size);
void EditTrips(Trip* arr, int size);
Trip* AddTrips(Trip* arr, int size);

int main() {
	int option, size = 0;

	Trip* arr = new Trip[0];

	do {
		cout << "\nPlease choose an option:\n1.Print All\n2.Edit Trip\n3.Add Trip\n4.Exit\n" << endl;
		cin >> option;

		switch (option) {
		case 1:
			PrintTrips(arr, size);
			break;
		case 2:
			EditTrips(arr, size);
			break;
		case 3:
			arr = AddTrips(arr, size);
			size++;
			break;
		case 4:
			cout << "\nBye!\n";
			break;
		default:
			cout << "\nInvalid Option!\n";
			break;
		}
	} while (option != 4);
	return 0;
}

bool isEmpty(int size) {
	return size == 0;
}

void PrintTrips(Trip* arr, int size) {
	if (isEmpty(size)) {
		cout << "\nNo trips to print!\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << "\nTrip #" << i+1 << ":\n";
		arr[i].PrintTrip();
	}
	cout << "\nEnd of Trip list.\n";
}

void EditTrips(Trip* arr, int size) {
	if (isEmpty(size)) { //if no trips
		cout << "\nNo trips in array to edit.\n";
		return;
	}
	int tCode, tIndex = -1; //index check
	Trip t = Trip();
	cout << "\nPlease enter the code of the trip you'd like to edit.\n";
	cin >> tCode;

	for (int i = 0; i < size; i++) {//look through array
		if (arr[i].getCode() == tCode) {
			tIndex = i;
			t = arr[i];
			break;
		}
	}

	if (tIndex == -1) { // didn't find code
		cout << "\nCould not find a trip with this code!\n";
		return;
	}

	//if we did find one
	string answer, newDestination;
	cout << "\nWould you like to update the destination? Y/N\n";
	cin >> answer;

	if (answer.compare("Y") == 0) {
		cout << "\nPlease enter a new destination.\n";
		cin >> newDestination;
		t.setDst(newDestination);
	}

	cout << "\nWould you like to update the date? Y/N\n";
	cin >> answer;
	
	if (answer.compare("Y") == 0) {
		int tDay, tMonth, tYear;
		cout << "\nPlease enter a day.\n";
		cin >> tDay;
		cout << "\nPleae enter a month.\n";
		cin >> tMonth;
		cout << "\nPlease enter a year.\n";
		cin >> tYear;
		Date d = Date(tDay, tMonth, tYear);
		t.setDate(d);
	}

	arr[tIndex] = t;
}

Trip* AddTrips(Trip* arr, int size) {
	int tDay, tMonth, tYear, tCode;
	string tDestination;
	
	cout << "\nPlease enter the code of the trip you'd like to add.\n";
	cin >> tCode;
	cout << "\nPlease enter a destination.\n";
	cin >> tDestination;
	cout << "\nPlease enter a day.\n";
	cin >> tDay;
	cout << "\nPleae enter a month.\n";
	cin >> tMonth;
	cout << "\nPlease enter a year.\n";
	cin >> tYear;

	Date d = Date(tDay, tMonth, tYear);
	Trip t = Trip(tCode, tDestination, d);
	Trip* newArray = new Trip[size + 1];
	if (isEmpty(size)) {
		newArray[0] = t;
	}
	else {
		for (int i = 0; i < size; i++) {
			newArray[i] = arr[i];
		}
		newArray[size] = t;
	}
	return newArray;
}