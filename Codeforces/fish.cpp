#include<iostream>
using namespace std;

struct Time{
	int hour, minute;
};

struct Flight{
	Time departureTime;
	Time arrivalTime;
	string flightNo;
	list<string> listOfDays;

	Flight(Time departureTime,
				  Time arrivalTime,
				  string flightNo,
				  list<string> listOfDays){
		this->departureTime = departureTime;
		this->arrivalTime = arrivalTime;
		this->flightNo = flightNo;
		this->listOfDays = listOfDays;
	}
};

struct TimeTable{
	string place1, place2;
	list<Flight> listOfFlights;

	TimeTable(string place1,
		      string place2,
		      list<Flight> listOfFlights){
		this->place1 = place1;
		this->place2 = place2;
		this->listOfFlights = listOfFlights;
	}

	string getTimeTable(){
		
	}
};


