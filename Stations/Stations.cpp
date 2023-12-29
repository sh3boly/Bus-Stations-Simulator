#include "Stations.h"

Stations::Stations()
{
	lastFinished = 0;
}

Stations::Stations(int t, int no)
{	
	lastFinished = 0;
	cNP = 0;
	cBCKNP = 0;
	cWP = 0;
	cSP = 0;
	timeBetweenEachStation = t;
	if (no == 0) {
		isStationZero = 1;
	}
	stationNumber = no;
	WaitingFWDNormalPassengers = new LinkedQueue<Passenger*>;
	WaitingBCKNormalPassengers = new LinkedQueue<Passenger*>;

	WaitingFWDSpecialPassengers = new PriorityQueue<Passenger*>;
	WaitingBCKSpecialPassengers = new PriorityQueue<Passenger*>;

	WaitingFWDWheelPassengers = new LinkedQueue<Passenger*>;
	WaitingBCKWheelPassengers = new LinkedQueue<Passenger*>;
	
	FWDBusses = new LinkedQueue<Buss*>;
	BCKBusses = new LinkedQueue<Buss*>;

}

int Stations::getTBetweenEachStation()
{
	return timeBetweenEachStation;
}

void Stations::addWaitingBus(Buss* Bus)
{
	if (Bus->getBusDirection() == "FWD") {
		FWDBusses->enqueue(Bus);
		countBuses++;
	}
	//else
		//BCKBusses->enqueue(Bus);
}
/*Adds a waiting passenger by:
1-Checking the direction 
2-Check the type if SP check the SP type
3-enqueue in the appropriate Queue

*/
void Stations::addWaitingPassenger(Passenger *p, int number)
{
	if (stationNumber == number) {
		if (p->getDirection() == "FWD") {
			if (p->getPType() == 0) {
				WaitingFWDNormalPassengers->enqueue(p);
				cNP++;
			}
			else if (p->getPType() == 1) {
				WaitingFWDWheelPassengers->enqueue(p);
				cWP++;
			}
			else if (p->getPType() == 2) {
				cSP++;
				if (p->getSType() == "Preg") {
					WaitingFWDSpecialPassengers->enqueue(p, 1);

				}
				else if (p->getSType() == "POD") {
					WaitingFWDSpecialPassengers->enqueue(p, 2);

				}
				else if (p->getSType() == "aged") {
					WaitingFWDSpecialPassengers->enqueue(p, 3);

				}
			}
		}
		else {
			if (p->getPType() == 0) {
				WaitingBCKNormalPassengers->enqueue(p);
				cBCKNP++;
			}
			else if (p->getPType() == 1) {
				WaitingBCKWheelPassengers->enqueue(p);
				cWP++;
			}
			else if (p->getPType() == 2) {
				cSP++;
				if (p->getSType() == "Pregnant") {
					WaitingBCKSpecialPassengers->enqueue(p, 1);

				}
				else if (p->getSType() == "POD") {
					WaitingBCKSpecialPassengers->enqueue(p, 2);

				}
				else if (p->getSType() == "aged") {
					WaitingBCKSpecialPassengers->enqueue(p, 3);

				}
			}

		}
	}
}

void Stations::removeWaitingPassenger(int id, int number)
{
	bool isFound = false;
	if (stationNumber = number) {
		
		Passenger* p;
		LinkedQueue<Passenger*>* WaitingFWDNormalPassengerTemp = new LinkedQueue<Passenger*>;
		LinkedQueue<Passenger*>* WaitingBCKNormalPassengerTemp = new LinkedQueue<Passenger*>;
		while (!WaitingFWDNormalPassengers->isEmpty()) {
			WaitingFWDNormalPassengers->dequeue(p);
			if (p->getID() != id) {
				WaitingFWDNormalPassengerTemp->enqueue(p);
			}
			else {
				isFound = true;
			}
		}
		while (!WaitingFWDNormalPassengerTemp->isEmpty()) {
			WaitingFWDNormalPassengerTemp->dequeue(p);
			WaitingFWDNormalPassengers->enqueue(p);
		}
	while (!WaitingBCKNormalPassengers->isEmpty()) {
		WaitingFWDNormalPassengers->dequeue(p);
		if (p->getID() != id) {
			WaitingBCKNormalPassengerTemp->enqueue(p);
		}
		else {
			isFound = true;
		}
	}
	while (!WaitingBCKNormalPassengerTemp->isEmpty()) {
		WaitingBCKNormalPassengerTemp->dequeue(p);
		WaitingBCKNormalPassengers->enqueue(p);
	}
}
	if (isFound = true) {
		cNP--;
	}
}

void Stations::boardWPPassenger()
{
	// for WP 
	Passenger* p;
	Buss* b;
	LinkedQueue<Buss*>tempBFWD(*FWDBusses);
	LinkedQueue<Buss*>tempBBCK(*BCKBusses);
	while (!tempBFWD.isEmpty()) {
		tempBFWD.dequeue(b);
		if (b->getType() == "Wbus") {
			while (!WaitingFWDWheelPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingFWDWheelPassengers->dequeue(p);
				b->getOn(p);
			}
		}
		
	}
	while (!tempBBCK.isEmpty()) {
		tempBBCK.dequeue(b);
		if (b->getType() == "Wbus") {
			while (!WaitingBCKWheelPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingBCKWheelPassengers->dequeue(p);
				b->getOn(p);
			}
		}
		
	}
}

void Stations::boardPassenger()
{
	Passenger* p;
	Buss* b;
	LinkedQueue<Buss*>tempBFWD(*FWDBusses);
	LinkedQueue<Buss*>tempBBCK(*BCKBusses);
	while (!tempBFWD.isEmpty()) {
		tempBFWD.dequeue(b);
		if (b->getType() == "Mbus") {
			while (!WaitingFWDSpecialPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingFWDSpecialPassengers->dequeue(p);
				b->getOn(p);
			}
			while (!WaitingFWDNormalPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingFWDNormalPassengers->dequeue(p);
				b->getOn(p);
			}
		}
	}
	while (!tempBBCK.isEmpty()) {
		tempBBCK.dequeue(b);
		if (b->getType() == "Mbus") {
			while (!WaitingBCKSpecialPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingBCKSpecialPassengers->dequeue(p);
				b->getOn(p);
			}
			while (!WaitingBCKNormalPassengers->isEmpty() && b->getCapacity() != 0) {
				WaitingBCKNormalPassengers->dequeue(p);
				b->getOn(p);
			}
		}
	}
}



int Stations::getStationNumber()
{
	return stationNumber;
}

bool Stations::moveOneNPPassenger()
{
	Passenger* NP;
	if (cNP == 0){
		return false;
	}
	else {
		WaitingFWDNormalPassengers->dequeue(NP);
		finished.InsertEnd(NP->getID());
		lastFinished++;
		FinishList->enqueue(NP);
		return true;
	}
}

bool Stations::moveOneWPPassenger()
{
	Passenger* WP;
	if (cWP == 0) {
		return false;
	}
	else {
		WaitingFWDWheelPassengers->dequeue(WP);
		finished.InsertEnd(WP->getID());
		lastFinished++;
		FinishList->enqueue(WP);
		return true;
	}
}

bool Stations::moveOneSPPassenger()
{
	Passenger* SP;
	if (cSP == 0) {
		return false;
	}
	else {
		WaitingFWDSpecialPassengers->dequeue(SP);
		finished.InsertEnd(SP->getID());
		lastFinished++;
		FinishList->enqueue(SP);
		return true;
	}
}

int Stations::getCSP()
{
	return cSP;
}

int Stations::getCNP()
{
	return cNP;
}

int Stations::getCWP()
{
	return cWP;
}
void Stations::incrementPassengerWaitTime()
{
	Passenger* p;
	LinkedQueue<Passenger*> temp(*WaitingFWDNormalPassengers);
	while (!temp.isEmpty()) {
		temp.dequeue(p);
		p->incrementWaitingTime();
	}
	LinkedQueue<Passenger*> temp1(*WaitingBCKNormalPassengers);
	while (!temp1.isEmpty()) {
		temp1.dequeue(p);
		p->incrementWaitingTime();
	}
	PriorityQueue<Passenger*> temp2(*WaitingFWDSpecialPassengers);
	while (!temp2.isEmpty()) {
		temp2.dequeue(p);
		p->incrementWaitingTime();
	}
	PriorityQueue<Passenger*> temp3(*WaitingBCKSpecialPassengers);
	while (!temp3.isEmpty()) {
		temp3.dequeue(p);
		p->incrementWaitingTime();
	}
	LinkedQueue<Passenger*> temp4(*WaitingBCKWheelPassengers);
	while (!temp4.isEmpty()) {
		temp4.dequeue(p);
		p->incrementWaitingTime();
	}
	LinkedQueue<Passenger*> temp5(*WaitingFWDWheelPassengers);
	while (!temp5.isEmpty()) {
		temp5.dequeue(p);
		p->incrementWaitingTime();
	}
}
/*
Upgrade Passenger:
1- Loops over the count of back normal passengers and forward passengers
2- dequeues the passenger then checks the wait time if it's greater than the maxW
3- if it is enqueue it in Special Passengers as aged
4- if not enqueue back in Normal Passengers
*/
void Stations::upgradePassenger(int maxW)
{
	Passenger* p;
	for (int i = 0; i < cBCKNP; i++) {
		WaitingBCKNormalPassengers->dequeue(p);
		if (p->getWaitTime() > maxW) {
			WaitingBCKSpecialPassengers->enqueue(p, 2);
		}
		else {
			WaitingBCKNormalPassengers->enqueue(p);
		}
	}
	for (int i = 0; i < cNP; i++) {
		WaitingFWDNormalPassengers->dequeue(p);
		if (p->getWaitTime() > maxW) {
			WaitingFWDSpecialPassengers->enqueue(p, 2);
		}
		else {
			WaitingFWDNormalPassengers->enqueue(p);
		}
	}
}

Buss* Stations::removeFWDBus()
{
	if (FWDBusses->isEmpty()) {
		return nullptr;
	}
	Buss* b;
	FWDBusses->dequeue(b);
	countBuses--;
	return b;
}

Buss* Stations::removeBCKBus()
{
	if (FWDBusses->isEmpty()) {
		return nullptr;
	}
	Buss* b;
	FWDBusses->dequeue(b);
	countBuses--;
	return b;
}

void Stations::addFWDBuss(Buss* b)
{
	FWDBusses->enqueue(b);
	countBuses++;
}

void Stations::addBCKBuss(Buss* b)
{
	BCKBusses->enqueue(b);
	countBuses++;
}


