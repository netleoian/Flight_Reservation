// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include "MakingReservation.h" // MakingReservation class definition

extern char airport[ 6 ][ 12 ];
extern int flightPrices[ 6 ][ 6 ];

// MakingReservation constructor initializes data members
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
                                      FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule )
{
} // end MakingReservation constructor
void MakingReservation::execute(){
	string usertime;
	int DA=1, AA=1;
	cout <<endl<< "Input Booking Data  " << endl;
	cout <<endl<< "Departure Date (yyyy/mm/dd)�G ";
	cin >> usertime;
	cout << endl;
	cout << "Departure Airport�G" << endl;
	for (int i=1; i < 6; i++)
		cout << i << "." << airport[i] << endl;
	cout << "?";
	cin >> DA;
	cout << endl <<" Arrival Airport : "<<endl;
	for (int i = DA, b=1; b < 6; b++){
		if (flightPrices[i][b]!=0)//�p�G����0�N�O�S���Z
			cout << b << "." << airport[b] << endl;
	}
	cout << "?";
	cin >> AA;
	flightSchedule.display2(DA,AA,usertime);
	//�q��}�l
	string FN, ID, NAME, MP;
	cout << "Flight Number: ";
	cin >> FN;
	cout << endl << "Input ID Number : ";
	cin >> ID;
	cout << endl << "Name: ";
	cin >> NAME;
	cout << endl << "Mobile Phone : ";
	cin >> MP;
	
	flightSchedule.display3(FN, DA, AA,NAME, usertime);
	Reservation user(FN, ID, NAME, MP, usertime);
	reservationDatabase.addReservation(user);
	cout <<endl<< "Reservation Completed!         " << endl << endl;
} // performs making reservation