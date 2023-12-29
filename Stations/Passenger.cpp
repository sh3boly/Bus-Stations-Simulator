#include "Passenger.h"

Passenger::Passenger()
{
}

Passenger::Passenger(int id, int h, int min, int strt, int end, int typ, string styp)
{
	ID = id;
	arrivalTime = h * 60 + min;
	startStation = strt;
	endStation = end;
	pType = typ;
	spType = styp;
	waitTime = 0;
	setDirection();

}


void Passenger::setStartStation(int strt)
{
	startStation = strt;
}

void Passenger::setEndStation(int end)
{
	endStation = end;
}

void Passenger::setPType(int typ)
{
	pType = typ;
}

void Passenger::setSType(int styp)
{
	spType = styp;
}

int Passenger::getID()
{
	return ID;
}

int Passenger::getArrivalTime()
{
	return arrivalTime;
}

int Passenger::getfinishTime()
{
	return finishTime;
}

int Passenger::getMoveTime()
{
	return moveTime;
}
int Passenger::getWaitTime()
{
	return waitTime;
}



int Passenger::getStartStation()
{
	return startStation;
}

int Passenger::getEndStation()
{
	return endStation;
}

int Passenger::getPType()
{
	return pType;
}



void Passenger::incrementWaitingTime()
{
	waitTime++;
}

string Passenger::getSType()
{
	return spType;
}

void Passenger::promotePassenger()
{
	spType = 1;
}

void Passenger::setDirection()
{
	if (endStation > startStation) {
		direction = "FWD";
	}
	else {
		direction = "BCK";
	}
}

string Passenger::getDirection()
{
	return direction;
}
