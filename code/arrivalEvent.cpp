#include "arrivalEvent.h"
arrivalEvent::arrivalEvent(int h, int m, int start, int end, int typ)
{
	type = typ;
	eH = h;
	eM = m;
	startStation = start;
	endStation = end;
}
void arrivalEvent::Execute(Company* pC)
{
	Passenger* p = new Passenger(ID, eH, eM, startStation, endStation, type, stype);
	pC->addPassenger(p, startStation);
}

int arrivalEvent::getEType()
{
	return eType;
}
