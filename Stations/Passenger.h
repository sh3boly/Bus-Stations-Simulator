#pragma once
#include <iostream>
using namespace std;
class Passenger
{
	string direction;
	int ID; // passenger ID
	int arrivalTime; // in minutes
	int finishTime; // in minutes
	int moveTime; // in minutes

	int waitTime; // the waiting time of the passenger
	int startStation;
	int endStation; 
	int pType; // Assume NP = 0, WP = 1, SP = 2
	bool isWaiting; // is a waiting passenger
	bool isMoving; // is a moving passenger
	int maxW; // maximum waiting time
	string spType;

public:
	Passenger();
	Passenger(int id, int h, int min,int strt, int end, int typ, string styp);

	void setStartStation(int strt);
	void setEndStation(int end);
	void setPType(int typ);
	void setSType(int styp);
	
	int getID();
	int getArrivalTime();
	int getfinishTime();
	int getMoveTime();
	int getWaitTime();
	int getStartStation();
	int getEndStation();
	int getPType();

	void incrementWaitingTime();
	string getSType();
	void promotePassenger();
	void setDirection();
	string getDirection();
	
};

