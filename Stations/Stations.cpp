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

void Stations::addWaitingBus(Buss* Bus)
{
	if (Bus->getBusDirection() == "FWD")
		FWDBusses->enqueue(Bus);
	else
		BCKBusses->enqueue(Bus);
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

void Stations::boardPassenger(Passenger *p)
{
	// for NP
	if (p->getDirection() == "FWD") {
		Buss* b;
		FWDBusses->dequeue(b);
		if (p->getPType() == 0) {
			while (b->getType() != "Mbus") {
				FWDBusses->enqueue(b);
				FWDBusses->dequeue(b);
			}
			b->getOn(p);
		}
		else if (p->getPType() == 1) {
			while (b->getType() != "Wbus") {
				FWDBusses->enqueue(b);
				FWDBusses->dequeue(b);
			}
			b->getOn(p);
		}
		else if (p->getPType() == 0) {
			while (b->getType() != "Mbus") {
				FWDBusses->enqueue(b);
				FWDBusses->dequeue(b);
			}
			b->getOn(p);
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


