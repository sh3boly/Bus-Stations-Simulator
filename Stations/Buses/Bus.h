#pragma once
#include"../Data Structures/Queue.h"
#include "../Data Structures/LinkedQueue.h"
#include "../Passengers/pass.h"
#include "../Passengers/LinkedQueuePassengers.h"
#include<iostream>

using namespace std;
template<class T>
class bus
{
private:
	string type;
	int capacity;
	int maintenanceCheckupTime;
	int currentJourney;
	int JourneysCompleted;
	int maintenanceJourneys;
	int currentStation;
	bool maintenanceInProgress;
	Linkedqueue<Passenger> passengers;
	void getoff(Linkedqueue<Passenger>& passengerQueue, int currentTime);
public:
	bus();
	void setType(string T);
	void setCapacity(int capacity);
	void setCheckupTime(int checkupTime);
	void currentJourney(int CurrentJourney);
	void setJourneysCompleted(int JourneysCompleted);
	string getType();
	const getCapacity();
	const getcurrentJourney();
	const getCheckupTime();
	const getJourneysCompleted();
	int maintenanceJourneys();
	bool isMaintenanceDue();
	void startMaintenance();
	void finishMaintenance();
	void moveToNextStationforward();
	void moveToNextStationbackward();	
	void passengerGetOn(const Passenger& passenger, int currentTime);
	void Passengersgetoff(Linkedqueue<passengers>& passengerQueue, int currentTime);
	double getUtilization(int totalSimulationTime);
};