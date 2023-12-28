//#include "Bus.h"
//
//template<class T>
//Buss<T>::Buss()
//{
//	bussType = "Mbus";
//	capacity = 0;
//	maintenanceTime = 0;
//	currentJourney = 0;
//	journeysCompleted = 0;
//	currentStation = 0;
//	isMaintenance = false;
//	busDirecton = "FWD";
//}
//
//template<class T>
//void Buss<T>::setType(string T)
//{
//	bussType = T;
//}
//template<class T>
//string Buss<T>::getType() const
//{
//	return bussType;
//}
//
//template<class T>
//void Buss<T>::setCapacity(int bc)
//{
//	capacity = bc;
//}
//template<class T>
//int Buss<T>::getCapacity() const
//{
//	return capacity;
//}
//template<class T>
//int Buss<T>::getRemCapacity()
//{
//	return capacity;
//}
//
//template<class T>
//void Buss<T>::setMaintenanceTime(int t)
//{
//	maintenanceTime = t;
//}
//template<class T>
//int Buss<T>::getMaintenanceTime() const
//{
//	return maintenanceTime;
//}
//
//template<class T>
//void Buss<T>::setcurrentJourney(int cj)
//{
//	currentJourney = cj;
//}
//template<class T>
//int Buss<T>::getcurrentJourney() const
//{
//	return 	currentJourney;
//}
//
//template<class T>
//void Buss<T>::setJourneysCompleted(int journeyC)
//{
//	journeysCompleted = journeyC;
//}
//template<class T>
//int Buss<T>::getJourneysCompleted() const
//{
//	return journeysCompleted;
//}
//template<class T>
//void Buss<T>:: incrementJourneysCompleted(int j)
//{
//	journeysCompleted++;
//	if (journeysCompleted == j)
//	{
//		if (currentStation == 0)
//		{
//			isMaintenance = true;
//			journeysCompleted = 0;			//The bus is in maintenance
//		}
//		else
//			journeysCompleted++;
//	}
//	if (journeysCompleted > j)
//	{
//		isMaintenance = true;
//		journeysCompleted = 0;			//The bus should be in the maintenance
//	}
//}
//
//template<class T>
//void Buss<T>::setCurrentStation(int station)
//{
//	currentStation = station;
//}
//template<class T>
//int Buss<T>::getCurrentStation() const
//{
//	return currentStation;
//}
//
//template<class T>
//void Buss<T>::setIsMaintenance(bool p)
//{
//	isMaintenance = p;
//}
//template<class T>
//bool Buss<T>::getIsMaintenance() const
//{
//	return isMaintenance;
//}
//
//template<class T>
//void Buss<T>::setBusDirection(string d)
//{
//	busDirecton = d;
//}
//template<class T>
//string Buss<T>::getBusDirection() const
//{
//	return busDirecton;
//}
//template<class T>
//void Buss<T>::changeBusDirection()
//{
//	if (busDirecton == "FWD")
//		busDirecton = "BCK";
//	else
//		busDirecton = "FWD";
//}
//
//template<class T>
//void Buss<T>::getOn(Passenger* p)
//{
//	busPassengers->enqueue(p);
//}
//
//template<class T>
//void Buss<T>::getOff(Passenger* p)
//{
//	
//}
#include "Bus.h"

Buss::Buss()
{
    bussType = "Mbus";
    capacity = 0;
    maintenanceTime = 0;
    currentJourney = 0;
    journeysCompleted = 0;
    currentStation = 0;
    isMaintenance = false;
    busDirecton = "FWD";
    // Initialize busPassengers if needed
    // busPassengers = new LinkedQueue<Passenger*>();
}

void Buss::setType(string T)
{
    bussType = T;
}

string Buss::getType() const
{
    return bussType;
}

void Buss::setCapacity(int bc)
{
    capacity = bc;
}

int Buss::getCapacity() const
{
    return capacity;
}

int Buss::getRemCapacity()
{
    return capacity;
}

void Buss::setMaintenanceTime(int t)
{
    maintenanceTime = t;
}

int Buss::getMaintenanceTime() const
{
    return maintenanceTime;
}

void Buss::setcurrentJourney(int cj)
{
    currentJourney = cj;
}

int Buss::getcurrentJourney() const
{
    return currentJourney;
}

void Buss::setJourneysCompleted(int journeyC)
{
    journeysCompleted = journeyC;
}

int Buss::getJourneysCompleted() const
{
    return journeysCompleted;
}

void Buss::incrementJourneysCompleted(int j)
{
    journeysCompleted++;
    if (journeysCompleted == j)
    {
        if (currentStation == 0)
        {
            isMaintenance = true;
            journeysCompleted = 0; // The bus is in maintenance
        }
        else
            journeysCompleted++;
    }
    if (journeysCompleted > j)
    {
        isMaintenance = true;
        journeysCompleted = 0; // The bus should be in maintenance
    }
}

void Buss::setCurrentStation(int station)
{
    currentStation = station;
}

int Buss::getCurrentStation() const
{
    return currentStation;
}

void Buss::setIsMaintenance(bool p)
{
    isMaintenance = p;
}

bool Buss::getIsMaintenance() const
{
    return isMaintenance;
}

void Buss::setBusDirection(string d)
{
    busDirecton = d;
}

string Buss::getBusDirection() const
{
    return busDirecton;
}

void Buss::changeBusDirection()
{
    if (busDirecton == "FWD")
        busDirecton = "BCK";
    else
        busDirecton = "FWD";
}

void Buss::getOn(Passenger* p)
{
    // Initialize busPassengers if needed
    // if (!busPassengers)
    //     busPassengers = new LinkedQueue<Passenger*>();
    busPassengers->enqueue(p);
}

void Buss::getOff(Passenger* p)
{
    // Implement the function as needed
}
