#include <iostream>
#include "Trip.h"
#include "Date.h"
using namespace std;

bool IsEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);

void main()
{
    int option;
    Trip* arr = new Trip[0];
    int size = 0;
    do
    {
        cout << "Please Select an Option : \n1. Print Trips \n2. Edit Trip \n3. Add Trip \n4. Exit" << endl;;
        cin >> option;
        switch (option)
        {
        case 1:
            Print(arr, size);
            break;
        case 2:
            EditTrip(arr, size);
            break;
        case 3:
            arr = AddTrip(arr, size);
            size++;
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "invalid option" << endl;
            break;
        }



    } while (option != 4);
}

bool IsEmpty(int size) {
    return size == 0;
}

void Print(Trip* trips, int size) {
    if (IsEmpty(size)) {
        cout << "No trips.";
        return;
    }
    for (int i = 0; i < size; i++) {
        trips[i].printTrip();
    }
}



void EditTrip(Trip* trip, int size) {
    if (IsEmpty(size)) {
        cout << "No trips.";
        return;
    }
    int tNumber;
    int tIndex = -1;
    cout << "\nPlease enter the trip number of the trip you'd like to edit.\n";
    cin >> tNumber;

    for (int i = 0; i < size; i++) {
        if (trip[i].getNumber() == tNumber) {
            tIndex = i;            
            break;
        }
    }

    if (tIndex == -1) {
        cout << "Trip not found!";
        return;
    }

    char* updateDate = new char[2], *updateDst = new char[2], *updateNumber = new char[2];
    string newDst;
    int newNumber, newDateDay, newDateMonth, newDateYear;

    cout << "\nWould you like to update the destination for this trip? Y - Yes, N - No\n";

    cin >> updateDst;

    if (strcmp(updateDst, "Y") == 0) {
        cout << "\nPlease enter a new destination for this trip.\n";
        cin >> newDst;
        trip[tIndex].setDestination(newDst);
    }
    else
    {
        if (strcmp(updateDst, "N") == 0) {}
        else {
            cout << "Invalid option! Bailing out.";
            return;
        }
    }

    cout << "\nWould you like to update the number for this trip? Y - Yes, N - No\n";

    cin >> updateNumber;

    if (strcmp(updateNumber, "Y") == 0) {
        cout << "\nPlease enter a new number for this trip.\n";
        cin >> newNumber;
        trip[tIndex].setNumber(newNumber);
    }
    else
    {
        if (strcmp(updateNumber, "N") == 0) {}
        else {
            cout << "Invalid option! Bailing out.";
            return;
        }
    }

    cout << "\nWould you like to update the number for this trip? Y - Yes, N - No\n";

    cin >> updateDate;

    if (strcmp(updateDate, "Y") == 0) {
        cout << "\nPlease enter a new day for the date of this trip.\n";
        cin >> newDateDay;

        cout << "\nPlease enter a new month for the date of this trip.\n";
        cin >> newDateMonth;

        cout << "\nPlease enter a new year for the date of this trip.\n";
        cin >> newDateYear;

        Date newDate = Date(newDateDay, newDateMonth, newDateYear);
        trip[tIndex].setDate(newDate);
    }
    else
    {
        if (strcmp(updateNumber, "N") == 0) {}
        else {
            cout << "\nInvalid option! Bailing out.\n";
            return;
        }
    }
}

Trip* AddTrip(Trip* arr, int size) {
    int tNumber;
    int tDateDay, tDateMonth, tDateYear;
    string tDst;
    cout << "\nPlease enter a number for this trip.\n";
    cin >> tNumber;

    cout << "\nPlease enter a destination for this trip.\n";
    cin >> tDst;

    cout << "\nPlease enter a day for the date of this trip.\n";
    cin >> tDateDay;

    cout << "\nPlease enter a month for the date of this trip.\n";
    cin >> tDateMonth;

    cout << "\nPlease enter a year for the date of this trip.\n";
    cin >> tDateYear;

    Date tDate = Date(tDateDay, tDateMonth, tDateYear);
    Trip t(tNumber, tDst, tDate);

    Trip* trips = new Trip[size + 1];

    for (int i = 0; i < size; i++) {
        trips[i] = arr[i];
    }
    trips[size] = t;

    delete[] arr;
    return trips;
}