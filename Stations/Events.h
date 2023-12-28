
#ifndef EVENTS_H
#define EVENTS_H
#pragma once

//#include <iostream>
#include "LinkedQueue.h"
using namespace std;
class Company;
class Events
{
	int eType; // 1 for arrival 0 for leave
	int hours;
	int minutes;
	int eventID;
public:
	Events();
	virtual void Execute(Company *pC) = 0;
	virtual int getEType() = 0;
	virtual int getEHours() = 0;
	virtual int getEMinutes() = 0;
};

#endif // !EVENTS_H
