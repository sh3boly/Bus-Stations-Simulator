#pragma once
#include"../Data Structures/Queue.h"
#include "../Data Structures/LinkedQueue.h"
#include "../Passengers/pass.h"
#include "../Passengers/LinkedQueuePassengers.h"
#include<iostream>

using namespace std;
template<class T>
class buses
{
private:
	string type;
	int capacity;
	int maintenanceCheckupTime;
	int currentJourney;
	int maintenanceJourneys;
	int currentStation;
	bool maintenanceInProgress;
	int checkupTime;
	Linkedqueue<PassengerType> WP;
	Linkedqueue<PassengerType> NP;
	Linkedqueue<PassengerType> SP;
	void getoff(Linkedqueue<Passenger>& passengerQueue, int currentTime);
public:
	buses()
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
	void startMaintenance();
	void finishMaintenance();
	void moveToNextStation();
	bool passengerGetOn(const Passenger& passenger);
	void Passengersgetoff(int currentTime);
	double getUtilization(int totalSimulationTime);
};