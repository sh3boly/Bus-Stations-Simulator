#include "Stations.h"

Stations::Stations()
{
}

Stations::Stations(int t, int no)
{	
	timeBetweenEachStation = t;
	if (no == 0) {
		isStationZero = 1;
	}
	stationNumber = no;
	WaitingNormalPassengers = new LinkedQueue<Passenger*>;
	WaitingSpecialPassengers = new PriorityQueue<Passenger*>;
	WaitingWheelPassengers = new LinkedQueue<Passenger*>;
}

void Stations::addWaitingBus(int Bus)
{
	Busses->enqueue(Bus);
}

void Stations::addWaitingPassenger(Passenger *p, int number)
{
	if (stationNumber == number) {
		if (p->getPType() == 0) {
			WaitingNormalPassengers->enqueue(p);
		}
		else if (p->getPType() == 1) {
			WaitingWheelPassengers->enqueue(p);
		}
		else if (p->getPType() == 2) {
			if (p->getSType() == 1) {
				WaitingSpecialPassengers->enqueue(p, 1);

			}
			else if (p->getSType() == 2) {
				WaitingSpecialPassengers->enqueue(p, 2);

			}
			else if (p->getSType() == 3) {
				WaitingSpecialPassengers->enqueue(p, 3);

			}
		}
	}
}

void Stations::removeWaitingPassenger(int id, int number)
{
	if (stationNumber = number) {
		Passenger* p;
		LinkedQueue<Passenger*>* WaitingNormalPassengerTemp = new LinkedQueue<Passenger*>;
		while (!WaitingNormalPassengers->isEmpty()) {
			WaitingNormalPassengers->dequeue(p);
			if (p->getID() != id) {
				WaitingNormalPassengerTemp->enqueue(p);
			}
		}
		while (!WaitingNormalPassengerTemp->isEmpty()) {
			WaitingNormalPassengerTemp->dequeue(p);
			WaitingNormalPassengers->enqueue(p);
		}
	}
}

void Stations::loadPassenger()
{

}

void Stations::unloadPassenger()
{
}

int Stations::getStationNumber()
{
	return stationNumber;
}
