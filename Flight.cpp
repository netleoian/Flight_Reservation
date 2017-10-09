#include <iostream>
#include <iomanip>
#include "Flight.h" // Flight class definition

extern char airport[ 6 ][ 12 ];
extern int flightPrices[ 6 ][ 6 ];

Flight::Flight( string flightNumberValue, int departureAirportValue,
                int arrivalAirportValue, string departureTimeValue, string arrivalTimeValue )
{
   setFlightNumber( flightNumberValue );
   setDepartureAirport( departureAirportValue );
   setArrivalAirport( arrivalAirportValue );
   setDepartureTime( departureTimeValue );
   setArrivalTime( arrivalTimeValue );
}

void Flight::setFlightNumber( string flightNumberValue )
{
   size_t length = flightNumberValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      flightNumber[ i ] = flightNumberValue[ i ];
   flightNumber[ length ] = '\0';
}

string Flight::getFlightNumber()
{
   return flightNumber;
}

void Flight::setDepartureAirport( int departureAirportValue )
{
   departureAirport = departureAirportValue;
}

int Flight::getDepartureAirport()
{
   return departureAirport;
}

void Flight::setArrivalAirport( int arrivalAirportValue )
{
   arrivalAirport = arrivalAirportValue;
}

int Flight::getArrivalAirport()
{
   return arrivalAirport;
}

void Flight::setDepartureTime( string departureTimeValue )
{
   size_t length = departureTimeValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      departureTime[ i ] = departureTimeValue[ i ];
   departureTime[ length ] = '\0';
}

string Flight::getDepartureTime()
{
   return string( departureTime );
}

void Flight::setArrivalTime( string arrivalTimeValue )
{
   size_t length = arrivalTimeValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      arrivalTime[ i ] = arrivalTimeValue[ i ];
   arrivalTime[ length ] = '\0';
}

string Flight::getArrivalTime()
{
   return string( arrivalTime );
}
// displays flightNumber, airport[ departureAirport ], airport[ arrivalAirport ], date,
// departureTime, arrivalTime and flightPrices[ departureAirport ][ arrivalAirport ]
void  Flight::display1(string date){
	//¯è¯Z
	cout <<left<<setw(12)<< flightNumber 
		<<right<<setw(12)<< airport[departureAirport] 
		<< setw(12) <<airport[arrivalAirport] 
		<< setw(18) << date 
		<< setw(12) << getDepartureTime() 
		<< setw(17) << getArrivalTime() 
		<< setw(7) << flightPrices[departureAirport][arrivalAirport] 
		<< endl;
}

// displays name, flightPrices[ departureAirport ][ arrivalAirport ], flightNumber,
// airport[ departureAirport ], airport[ arrivalAirport ], date, departureTime, arrivalTime
void  Flight::display2(string name, string date){
	//«È¤áªº
	cout <<left<<setw(8)<< name
		<< right << setw(4) << flightPrices[departureAirport][arrivalAirport]
		<< setw(2) << " "
		<< setw(3)<<" " <<"GE"<< getFlightNumber() 
		<<setw(13)<< airport[departureAirport] << "-" << airport[arrivalAirport]
		<<setw(12)<< date
		<< setw(12) << getDepartureTime()
		<<setw(12)<<getArrivalTime()
		<< endl;
}