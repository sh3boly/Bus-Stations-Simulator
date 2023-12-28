#ifndef LEAVEEVENT_H
#define LEAVEEVENT_H
#pragma once
#include "Company.h"
#include "Events.h"
#include "Passenger.h"
using namespace std;

class Events;
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
	int getEHours();
	int getEMinutes();
};
#endif
