#include "Company.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


Company::Company()
{
	noP = 0; noNP = 0; noSP = 0; noWP = 0;
	pUI = new UI(this);
	hours = 0;
	minutes = 0;
	countEvents = 0; s = 0; st = 0; WBus_count = 0; MBus_count = 0; WBus_capactiy = 0; MBus_capacity = 0; maxW = 0; getOnOffTime = 0; J = 0; CWBus = 0; CMBus = 0;
	FinishList = new LinkedQueue<Passenger*>;
	countOfArrivalEvents = 0; countEvents = 0; countOfLeaveEvents = 0; countOfPassengers = 0;
	/*WaitingNormalPassengers = new LinkedQueue<Passenger*>;
	WaitingSpecialPassengers = new PriorityQueue<Passenger*>;
	WaitingWheelPassengers = new LinkedQueue<Passenger*>;*/


}
bool Company::readInput()
{

	fstream myInput("input.txt");
	if (myInput.is_open()) {
		myInput >> s >> st >> WBus_count >> MBus_count >> WBus_capactiy >> MBus_capacity >> J >> CWBus >> CMBus >> maxW >> getOnOffTime >> countEvents;
		busStations = new Stations*[s+1];
		for (int i = 0; i < s+1; i++) {
			Stations* S = new Stations(st, i);
			busStations[i] = S;
		}
		for (int i = 0; i < WBus_count; i++) {
			Buss* b = new Buss(i, WBus_capactiy);
			b->setType("Wbus");
			b->setBusDirection("FWD");
			busStations[0]->addWaitingBus(b);
		}
		for (int i = WBus_count; i < MBus_count + WBus_count; i++) {
			Buss* b = new Buss(i, MBus_capacity);
			b->setType("Mbus");
			b->setBusDirection("FWD");
			busStations[0]->addWaitingBus(b);
		}
		string etype, typ, styp;
		char garbage;
		int eH, eM, id, strt, end;
		for (int i = 0; i < countEvents; i++) {
			myInput >> etype;
			if (etype == "A") {
				countOfArrivalEvents++;
				myInput >> typ >> eH >> garbage >> eM >> id >> strt >> end; // take the inputs of the event
				if (typ == "NP") {
					arrivalEvent* A = new arrivalEvent(eH, eM, id, strt, end, 0, "");
					ActualEvents->enqueue(A);
					countOfPassengers++;
				}
				else if (typ == "WP") {
					arrivalEvent* A = new arrivalEvent(eH, eM, id, strt, end, 1, "");
					ActualEvents->enqueue(A);
					countOfPassengers++;

				}
				else if (typ == "SP") {
					myInput >> styp;
					arrivalEvent* A = new arrivalEvent(eH, eM, id, strt, end, 2, styp);
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
	ofstream myFile;
	myFile.open("output.txt");
	if (myFile.is_open()) {
		myFile << "FT\tID\t\tAT\tWT\tT" << endl;
		Passenger* p;
		while (!FinishList->isEmpty()) {
			FinishList->dequeue(p);
			myFile << changeTime(p->getfinishTime()) << "\t" << p->getID() << "\t" << changeTime(p->getArrivalTime()) << "\t"
				<< changeTime(p->getWaitTime()) << "\t" << changeTime(p->getfinishTime() - p->getMoveTime()) << endl;

		}
		myFile << "Passengers: " << noP << "\t[NP: " << noNP << ", SP: " << noSP << ", WP: " << noWP << "]" << endl;
		myFile << "pasenger Avg wait time: " << endl;
		myFile << "Auto-promoted passenger: " << endl;
		myFile << "Busses: " << endl;
		myFile << "Avg Bus time: " << endl;
		myFile << "Avg Utilization: " << endl;
		return true;
	}
	else {
		cout << "ERROR: Couldn't write an output file!!!! " << endl;

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
	return s;
}

void Company::removePassenger(int id, int number)
{
	Stations* temp;
	temp = busStations[number];
	temp->removeWaitingPassenger(id, number);
	
}

Stations Company::getStation(int number)
{
	return *busStations[number];
}
/*Upgrades the passenger depending on his wait time*/
void Company::upgradePassenger()
{
	for (int i = 0; i < s + 1; i++) {
		busStations[i]->upgradePassenger(maxW);
	}
}
bool Company::movePassenger(int typ, int stationNubmer) {
	if (noP == 0) {
		return false;
	}
	if (typ == 0) {
		if (noNP == 0) {
			return false;
		}
		else {

		}
	}
	else if (typ == 1) {

	}
	else if (typ == 2) {

	}
	else {
		return false;
	}
}
void Company::Simulate()
{
	LinkedQueue<Events*>* TempActualEvents = new LinkedQueue<Events*>;
	int choice;
	int r;
	Events* e;
	readInput();
	hours = 4;
	minutes = 0;
	pUI->setMode();
	choice = pUI->getMode();
	if (choice == 0) {
		pUI->printSilent();
	}
	while (hours != 24) {
		if (minutes >= 60) {
			hours++;
			minutes = minutes - 60;
		}
		while (!(ActualEvents->isEmpty())) {
			ActualEvents->dequeue(e);
			if (e->getEHours() <= hours && e->getEMinutes() <= minutes) {
				e->Execute(this);
			}
			else {
				TempActualEvents->enqueue(e);
			}
		}
		while (!(TempActualEvents->isEmpty())) {
			TempActualEvents->dequeue(e);
			ActualEvents->enqueue(e);
		}
			/*for (int i = 0; i < s; i++) {
				r = rand() % 100 + 1;
				if (r >= 1 && r <= 25 && busStations[i]->getCSP() != 0) {
					busStations[i]->moveOneSPPassenger();
				}
				else if (r >= 35 && r <= 45 && busStations[i]->getCWP() != 0) {
					busStations[i]->moveOneWPPassenger();
				}
				else if (r >= 50 && r <= 60 && busStations[i]->getCNP() != 0) {
					busStations[i]->moveOneNPPassenger();
				}
				
			}*/
		releaseBus();
		boardPassnegers();
		if (choice == 1) {
			pUI->printInteractive();
		}
		minutes = minutes + 5;

		}
}

void Company::releaseBus()
{
	Buss* b;
	if (minutes % 15 == 0) {
		b = busStations[0]->removeFWDBus();
		busStations[1]->addFWDBuss(b);
	}
}

void Company::boardPassnegers()
{
	for (int i = 0; i < s; i++) {
		busStations[i + 1]->boardPassenger();
		busStations[i + 1]->boardWPPassenger();
	}
}

string Company::changeTime(int mins)
{
	int x, y;
	x = mins / 60;
	y = mins % 60;
	string time;
	time = to_string(x) + ":" + to_string(y);
	return time;
}

void Company::setNumberOfPassengers()
{
	for (int i = 0; i < s; i++) {
		noNP = busStations[i]->getCNP();
		noSP = busStations[i]->getCSP();
		noWP = busStations[i]->getCWP();
		noP = noNP + noSP + noWP;
	}
}




