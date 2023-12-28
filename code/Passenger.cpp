#include "Passenger.h"

Passenger::Passenger()
{
}

Passenger::Passenger(int id, int h, int min, int strt, int end, int typ, int styp)
{
	ID = id;
	aHour = h;
	aMinute = min;
	startStation = strt;
	endStation = end;
	pType = typ;
	spType = styp;

}

void Passenger::setAHour(int h)
{
	aHour = h;
}

void Passenger::setAMin(int min)
{
	aMinute = min;
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

int Passenger::getAHour()
{
	return aHour;
}

int Passenger::getAMin()
{
	return aMinute;
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

int Passenger::getSType()
{
	return spType;
}

void Passenger::promotePassenger()
{
	spType = 1;
}
