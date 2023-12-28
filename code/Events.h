#pragma once
#include <iostream>
#include "Company.h"
#include "LinkedQueue.h"

class Events
{
	int eType; // 1 for arrival 0 for leave
	int hours;
	int minutes;
	int eventID;
public:
	virtual void Execute(Company *pC) = 0;
	virtual int getEType() = 0;
};

