#pragma once
class Passenger
{
	int ID; // passenger ID
	int aHour; // arrival hour
	int aMinute; // arrival minute
	int startStation;
	int endStation; 
	int pType; // Assume NP = 0, WP = 1, SP = 2
	bool isWaiting; // is a waiting passenger
	bool isMoving; // is a moving passenger
	int maxW; // maximum waiting time
	int spType; // Assume -1 for Wheel(has no priority as it has it's own queue) 0 for Normal, 1 for pregnant, 2 for POD, 3 for aged.

public:
	Passenger();
	Passenger(int id, int h, int min,int strt, int end, int typ, int styp);
	void setAHour(int h);
	void setAMin(int min);
	void setStartStation(int strt);
	void setEndStation(int end);
	void setPType(int typ);
	void setSType(int styp);
	int getID();
	int getAHour();
	int getAMin();
	int getStartStation();
	int getEndStation();
	int getPType();
	int getSType();
	void promotePassenger();

};

