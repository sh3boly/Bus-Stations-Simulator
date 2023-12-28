#pragma once
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "PriorityQueue.h"

class Stations
{
	PriorityQueue<Passenger*>* WaitingSpecialPassengers;
	LinkedQueue<Passenger*>* WaitingWheelPassengers;
	LinkedQueue<Passenger*>* WaitingNormalPassengers;
	LinkedQueue<int>* Busses;
	int stationNumber;
	bool isStationZero;
	int timeBetweenEachStation;
public:
	Stations();
	Stations(int time, int no); 
	void addWaitingBus(int Bus);
	void addWaitingPassenger(Passenger *p, int number);
	void removeWaitingPassenger(int id, int number);
	void loadPassenger();
	void unloadPassenger();
	int getStationNumber();

};

