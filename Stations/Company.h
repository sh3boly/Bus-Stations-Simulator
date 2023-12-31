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
#include "Events.h"
#include "leaveEvent.h"
#include "arrivalEvent.h"
#include "random"
#include <string>
using namespace std;

class UI;
class Company
{	
	LinkedQueue<Events*>* ActualEvents = new LinkedQueue<Events*>;
	UI* pUI;
	Stations** busStations;
	/*PriorityQueue<Passenger*>* WaitingSpecialPassengers;
	LinkedQueue<Passenger*>* WaitingWheelPassengers;
	LinkedQueue<Passenger*>* WaitingNormalPassengers;*/
	int hours, minutes;
	int countEvents, s, st, WBus_count, MBus_count, WBus_capactiy, MBus_capacity, maxW, getOnOffTime, J, CWBus, CMBus;
	int countOfArrivalEvents; // count of arrival events
	int countOfLeaveEvents; // count of leave events
	int countOfPassengers;
	int noP, noWP, noNP, noSP;

	LinkedQueue<Buss*>* MovingFWDBusses;
	LinkedQueue<Buss*>* MovingBCKBusses;

	LinkedQueue<Buss*>* checkMbus;
	LinkedQueue<Buss*>* checkWbus;

	LinkedQueue<Passenger*>* FinishList;

public:
	Company();
	Company(int timeBetween, int stationNo);
	bool readInput();
	bool writeOutput();
	void addPassenger(Passenger *p, int number);
	void incrementWaitTime();
	int getHour();
	int getMinutes();
	int getNumberOfStations();
	void removePassenger(int id, int number);
	void upgradePassenger();
	void setNumberOfPassengers();
	bool movePassenger(int typ, int stationNumber);
	Stations getStation(int number);
	void Simulate();
	void releaseBus();
	void moveBuses();
	void incrementJourneyTime();
	void boardPassnegers();
	void unboardPassengers();
	string changeTime(int mins); // changes time from minutes to HH::MM
	void addBusToCheckup();
	void movingToWaiting();
};

