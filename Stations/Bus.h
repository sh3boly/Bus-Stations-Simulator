//#pragma once
//
//#include <iostream>
//#include "Passenger.h"
//#include "LinkedQueue.h"
//using namespace std;
//
//template<class T>
//class Buss
//{
//private:
//	string bussType;
//	int capacity;
//	int maintenanceTime;		
//	int currentJourney;
//	int journeysCompleted;		
//	int currentStation;
//	bool isMaintenance;
//	string busDirecton;
//	LinkedQueue<Passenger*>* busPassengers;
//public:
//	Buss();
//	void setType(string T);
//	string getType() const;
//
//	void setCapacity(int capacity);
//	int getCapacity() const;
//	int getRemCapacity();
//
//	void setMaintenanceTime(int checkupTime);
//	int getMaintenanceTime() const;
//
//	void setcurrentJourney(int CurrentJourney);
//	int getcurrentJourney() const;
//
//	void setJourneysCompleted(int JourneysCompleted);
//	int getJourneysCompleted() const;
//	void incrementJourneysCompleted(int MaxJourneys);
//
//	void setCurrentStation(int station);
//	int getCurrentStation() const;
//
//	void setIsMaintenance(bool p);
//	bool getIsMaintenance() const;
//
//	void setBusDirection(string d);
//	string getBusDirection() const;
//	void changeBusDirection();
//
//	void getOn(Passenger* p);
//	void getOff(Passenger* p);
//};
#pragma once

#include <iostream>
#include "Passenger.h"
#include "LinkedQueue.h"
using namespace std;

class Buss
{
private:
    string bussType;
    int capacity;
    int busID;
    int maintenanceTime;
    int currentJourney;
    int journeysCompleted;
    int currentStation;
    bool isMaintenance;
    int countPassengers;
    string busDirecton;
    LinkedQueue<Passenger*>* busPassengers;

public:
    Buss(int id, int cap);
    void setType(string T);
    string getType() const;

    void setCapacity(int bc);
    int getCountPassenger();
    int getCapacity() const;
    int getRemCapacity();
    int getPassengerID(int no);
    int getID();

    void setMaintenanceTime(int t);
    int getMaintenanceTime() const;

    void setcurrentJourney(int cj);
    int getcurrentJourney() const;

    void setJourneysCompleted(int journeyC);
    int getJourneysCompleted() const;
    void incrementJourneysCompleted(int MaxJourneys);

    void setCurrentStation(int station);
    int getCurrentStation() const;

    void setIsMaintenance(bool p);
    bool getIsMaintenance() const;

    void setBusDirection(string d);
    string getBusDirection() const;
    void changeBusDirection();

    void getOn(Passenger* p);
    void getOff(Passenger* p);
};
