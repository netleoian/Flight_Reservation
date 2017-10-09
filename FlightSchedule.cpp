// FlightSchedule.cpp
// Member-function definitions for class FlightSchedule.
#include <iostream>
#include <fstream>
#include "FlightSchedule.h" // FlightSchedule class definition

// FlightSchedule default constructor loads flight schedule from the file FlightSchedule.dat
FlightSchedule::FlightSchedule()
{
   loadFlightSchedule();
}

FlightSchedule::~FlightSchedule()
{
}
void FlightSchedule::loadFlightSchedule(){
	ifstream open("FlightSchedule.dat", ios::binary);
	if (!open){
		cerr << "FlightSchedule.dat can not open!" << endl;
	}
	Flight tmp;
	flights.push_back(tmp);
	while (open.read(reinterpret_cast<char *>(&flights[flights.size() - 1]), sizeof(Flight))){
		flights.push_back(tmp);
	}
}
// calls the function Flight::display2 to display the information regarding
// the Flight object containing specified flightNumber
void FlightSchedule::display1(int count, string flightNumber, string name, string date){
	vector< Flight >::iterator Fposition = flights.begin();
	//尋找哪筆然後印出來
	for (; Fposition != flights.end(); ++Fposition){
		if (Fposition->getFlightNumber() == flightNumber){
			cout << count << "." << " ";
			Fposition->display2(name, date);
		}
	}
}

// calls the function Flight::display1 to display the information regarding
// the Flight object containing specified departureAirport and arrivalAirport
void FlightSchedule::display2(int departureAirport, int arrivalAirport, string date){
	//航班
	cout << "Flight  Departure airport  Arrival airport        Date  Departure time  Arrival time  Fare"
		<< endl;
	for (vector< Flight >::iterator it = flights.begin(); it != flights.end(); ++it){
		if (it->getDepartureAirport() == departureAirport && it->getArrivalAirport() == arrivalAirport){
			it->display1(date);
		}
	}
}
// calls the function Flight::display2 to display the information regarding
// the Flight object containing specified flightNumber, departureAirport and arrivalAirport
void FlightSchedule::display3(string flightNumber, int departureAirport, int arrivalAirport, string name, string date){
	//客戶的
	cout <<"Name      Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;
	vector< Flight >::iterator Fposition = flights.begin();
	//尋找哪筆然後印出來
	for (; Fposition != flights.end(); ++Fposition){
		if (Fposition->getFlightNumber() == flightNumber){
			Fposition->display2(name, date);
			break;
		}
	}

}