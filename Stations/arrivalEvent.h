#ifndef ARRIVALEVENT_H
#define ARRIVALEVENT_H
#pragma once
#include "Company.h"
#include "Events.h"
#include "Passenger.h"
using namespace std;

class Events;
class arrivalEvent :   public Events
{
	int eType;
	int type;
	string stype;
	int ID;
	int eH;
	int eM;
	int startStation;
	int endStation;
public:
	arrivalEvent(int h, int m, int id, int start, int end, int typ, string styp);
	void Execute(Company *pC);
	int getEType();
	int getEHours();
	int getEMinutes();
};
#endif
