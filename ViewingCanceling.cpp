#include <iostream>
#include "ViewingCanceling.h" // ViewingCanceling class definition

// ViewingCanceling constructor initializes data members
ViewingCanceling::ViewingCanceling( ReservationDatabase &theReservationDatabase,
                                    FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule ),
     id( "" )
{
} // end ViewingCanceling constructor
void ViewingCanceling::cancelingReservation(){
	int choice;
	viewingReservation();
	cout << "Enter your choice: ";
	cin >> choice;
	reservationDatabase.cancelReservation(id, choice);
} // performs canceling reservation
bool ViewingCanceling::viewingReservation(){
	if (reservationDatabase.empty()){//沒有資料時
		cout <<endl<< "No reservation information!" << endl;
		return false;
	}
	else
	{
		cout << "Enter ID Number : ";
	cin >> id;
	//reservationDatabase.display(id);//有時就顯示
	if (!reservationDatabase.existReservation(id)){//沒有他的ID資料時
		cout <<endl<< "No reservation information!" << endl;
	}
	else
	{
		reservationDatabase.display(id);//有時就顯示
	}
	return true;
	}
}