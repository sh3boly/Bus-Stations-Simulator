#pragma once
#include "Events.h"
#include "Passenger.h"
class arrivalEvent :   public Events
{
	int eType = 1;
	int type;
	int stype;
	int ID;
	int eH;
	int eM;
	int startStation;
	int endStation;
public:
	arrivalEvent(int h, int m, int start, int end, int typ);
	void Execute(Company *pC);
	int getEType();
};

