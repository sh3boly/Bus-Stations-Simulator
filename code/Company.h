#pragma once
#include "Stations.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <string>
#include "UI.h"
#include "PriorityQueue.h"
#include "leaveEvent.h"
#include "arrivalEvent.h"
#include "Events.h"
using namespace std;

class UI;
class Company
{	
	LinkedQueue<Events*>* ActualEvents;
	UI* UserInterface;
	Stations** busStations;
	/*PriorityQueue<Passenger*>* WaitingSpecialPassengers;
	LinkedQueue<Passenger*>* WaitingWheelPassengers;
	LinkedQueue<Passenger*>* WaitingNormalPassengers;*/
	int hours, minutes;
	int noOfStations;
	int countEvents, s, st, WBus_count, MBus_count, WBus_capactiy, MBus_capacity, maxW, getOnOffTime, J, CWBus, CMBus;
	int countOfArrivalEvents; // count of arrival events
	int countOfLeaveEvents; // count of leave events
	int countOfPassengers;

public:
	Company();
	Company(int numberOfStations, int timeBetween, int stationNo);
	bool readInput();
	bool writeOutput();
	void addPassenger(Passenger *p, int number);
	int getHour();
	int getMinutes();
	int getNumberOfStations();
	void removePassenger(int id, int number);
	
	void Simulate();
};

