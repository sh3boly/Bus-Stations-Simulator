#pragma once
#include "Events.h"
#include "Company.h"
#include "Passenger.h"
class Company;
class leaveEvent :    public Events
{
	int eType;
	int eH;
	int eM;
	int ID;
	int strt;
public:
	leaveEvent(int h, int m, int pId, int startStation);
	void Execute(Company* pC);
	int getEType();

};

