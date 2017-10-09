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
	if (reservationDatabase.empty()){//�S����Ʈ�
		cout <<endl<< "No reservation information!" << endl;
		return false;
	}
	else
	{
		cout << "Enter ID Number : ";
	cin >> id;
	//reservationDatabase.display(id);//���ɴN���
	if (!reservationDatabase.existReservation(id)){//�S���L��ID��Ʈ�
		cout <<endl<< "No reservation information!" << endl;
	}
	else
	{
		reservationDatabase.display(id);//���ɴN���
	}
	return true;
	}
}