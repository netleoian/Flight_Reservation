// ReservationDatabase.cpp
// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <fstream>
#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition

// ReservationDatabase default constructor loads flight reservations from the file Reservations.dat
ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

// ReservationDatabase destructor stores flight reservations into the file Reservations.dat
ReservationDatabase::~ReservationDatabase()
{
   storeReservations();
}

void ReservationDatabase::addReservation( Reservation reservation )
{
   reservations.push_back( reservation );
}

bool ReservationDatabase::empty()
{
   return ( reservations.size() == 0 );
}

bool ReservationDatabase::existReservation( string id )
{
   vector< Reservation >::iterator it;
   for( it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getId() == id )
         return true;

   return false;
}
void  ReservationDatabase::loadReservations(){
	ifstream open("Reservations.dat", ios::binary);
	if (!open){
		cerr << "Reservations.dat can not open!" << endl;
	}
	Reservation tmp;
	reservations.push_back(tmp);
	while (open.read(reinterpret_cast<char *>(&reservations[reservations.size()-1]), sizeof(Reservation))){
		reservations.push_back(tmp);
	}
	if (reservations[0].getId() ==""){
		reservations.erase(reservations.begin());
	}

} // loads flight reservations from the file Reservations.dat
void  ReservationDatabase::storeReservations(){
	ofstream save("Reservations.dat", ios::binary);
	for (unsigned i = 0; i < reservations.size(); i++){
		save.write(reinterpret_cast<char *>(&reservations[i]), sizeof(Reservation));
	}
} // stores flight reservations into the file Reservations.dat
void ReservationDatabase::display(string id){
	FlightSchedule user;
	vector< Reservation >::iterator it;
	int tmp = 1;
	cout << "    " << "Name  Fare     Flight              Segment        Date  Departure time  Arrival time" << endl;
	for (it = reservations.begin(); it != reservations.end(); ++it)
	if (it->getId() == id){
		user.display1(tmp, it->getFlightNumber(), it->getName(), it->getDate());
		tmp++;
	}
	
}
void  ReservationDatabase::cancelReservation(string id, int n){
	if (n < 1){
		cout << endl << "Out of range!" << endl;
		return;
	}
	FlightSchedule user;
	vector< Reservation >::iterator it,tmp,tmp1;
	int tmppos = 1;
	bool success = false;//去找 看有沒有找到
	for (it = reservations.begin(); it != reservations.end(); ++it){
		//cout << n << " " << tmppos << endl;
		if (it->getId() == id){//找到了往前挪
			if (tmppos == n){
				reservations.erase(it);
				/*
				for (tmp = it, tmp1 = it + 1; tmp1 != reservations.end(); tmp++, tmp1++){
				tmp = tmp1;
				}
				reservations.resize(reservations.size() - 1);*/
				cout <<endl<<"Reservation Cancelled!" << endl;
				storeReservations();
				success = true;
				break;
			}
			else
			{//不是那個第幾個就往上加
				tmppos++;
			}
		}
	}
	if (!success){//如果都沒找到 就是輸入大於內定的~
		cout <<endl<< "Out of range!" << endl;
	}
}