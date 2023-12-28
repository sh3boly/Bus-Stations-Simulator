#include "leaveEvent.h"

leaveEvent::leaveEvent(int h, int m, int pId, int startStation)
{
	eType = 0;
	eH = h;
	eM = m;
	ID = pId;
	strt = startStation;

}
void leaveEvent::Execute(Company* pC) {
	pC->removePassenger(ID, strt);
}

int leaveEvent::getEType()
{
	return eType;
}

int leaveEvent::getEMinutes()
{
	return eM;
}

int leaveEvent::getEHours()
{
	return eH;
}
