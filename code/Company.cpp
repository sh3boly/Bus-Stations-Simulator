#include "Company.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

Company::Company()
{
}
Company::Company(int numberOfStations, int timeBetween, int stationNo)
{
	noOfStations = numberOfStations;
	hours = 0;
	minutes = 0;
	countEvents = 0; s = 0; st = 0; WBus_count = 0; MBus_count = 0; WBus_capactiy = 0; MBus_capacity = 0; maxW = 0; getOnOffTime = 0; J = 0; CWBus = 0; CMBus = 0;
	noOfStations = 0;
	/*WaitingNormalPassengers = new LinkedQueue<Passenger*>;
	WaitingSpecialPassengers = new PriorityQueue<Passenger*>;
	WaitingWheelPassengers = new LinkedQueue<Passenger*>;*/


}
bool Company::readInput()
{

	fstream myInput("input.txt");
	if (myInput.is_open()) {
		myInput >> s >> st >> WBus_count >> MBus_count >> WBus_capactiy >> MBus_capacity >> J >> CWBus >> CMBus >> maxW >> getOnOffTime >> countEvents;
		*busStations = new Stations[s];
		for (int i = 0; i < s; i++) {
			Stations* S = new Stations(st, i);
			busStations[i] = S;
		}
		for (int i = 0; i < WBus_count; i++) {

		}
		for (int i = 0; i < MBus_count; i++) {

		}
		string etype, typ;
		char garbage;
		int eH, eM, id, strt, end;
		for (int i = 0; i < countEvents; i++) {
			myInput >> etype;
			if (etype == "A") {
				countOfArrivalEvents++;
				myInput >> typ >> eH >> garbage >> eM >> id >> strt >> end;
				if (typ == "NP") {
					arrivalEvent* A = new arrivalEvent(eH, id, strt, end, 0);
					ActualEvents->enqueue(A);
					countOfPassengers++;
				}
				else if (typ == "WP") {
					arrivalEvent* A = new arrivalEvent(eH, id, strt, end, 1);
					ActualEvents->enqueue(A);
					countOfPassengers++;

				}
				else if (typ == "SP") {
					arrivalEvent* A = new arrivalEvent(eH, id, strt, end, 2);
					ActualEvents->enqueue(A);
					countOfPassengers++;

				}
			}
			else {
				countOfLeaveEvents++;
				myInput >> eH >> garbage >> eM >> id >> strt;
				leaveEvent* L = new leaveEvent(eH, eM, id, strt);
				ActualEvents->enqueue(L);
				countOfPassengers--;


			}
		}
		return true;
		myInput.close();
	}
	else {
		cout << "ERROR file couldn't be opened!" << endl;
		return false;
	}
}

bool Company::writeOutput()
{
	Passenger;
	ofstream outputFile;
	outputFile.open("output.txt");
	if (outputFile.is_open()) {
		outputFile << "FT\tID\tAT\tWT\tTT\t" << endl;
		for (int i = 0; i < countOfPassengers; i++) {
			
		}
		return true;
	}
	else {
		cout << "File couldn't be opened!" << endl;
		return false;
	}
}

void Company::addPassenger(Passenger *p, int number)
{
	Stations* temp;
	int stationNumber = p->getStartStation();
	
	temp = busStations[number];
	temp->addWaitingPassenger(p,stationNumber);
	
}

int Company::getHour()
{
	return hours;
}

int Company::getMinutes()
{
	return minutes;
}

int Company::getNumberOfStations()
{
	return noOfStations;
}

void Company::removePassenger(int id, int number)
{
	Stations* temp;
	temp = busStations[number];
	temp->removeWaitingPassenger(id, number);
	
}

void Company::Simulate()
{
	Events* e;
	readInput();
	hours = 0;
	minutes = 0;
	while (hours != 24) {
		minutes++;
		if (minutes == 60) {
			hours++;
			minutes = 0;
		}
		while (ActualEvents->isEmpty()) {
		ActualEvents->dequeue(e);
		e->Execute(this);
		while (s != 0) {
			
			
		}
	}

}



