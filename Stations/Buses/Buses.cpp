#include "Buses.h"

template<class T>
void buses<T>::getoff(Linkedqueue<PassengerType>& passengerQueue, int currentTime)
{
	{
		while (!passengerQueue.empty())
		{
			if (passengerQueue.top().getEndStation() == station.currentStation)
			{
				Passenger& currentPassenger = passengerQueue.top();
				currentPassenger.setFinishTime(time.currentTime);
				passengerQueue.pop();
			}
			else
			{
				break;
			}
		}
	}
}

template<class T>
buses<T>::buses()
{
	busType = type;
	capacity = capac;
	currentJourney = 0;
	currentStation = 0;
	maintenanceInProgress = false;
	maintenanceJourneys = maintenanceJ;
	checkupTime = checkupT
}

template<class T>
void buses<T>::setType(string T)
{
	Type = T;
}

template<class T>
void buses<T>::setCapacity(int capacity)
{
	capacityy = capacity;
}
template<class T>
void buses<T>::setCheckupTime(int checkupTime)
{
	checkupTimee = checkupTime;
}
template<class T>
void buses<T>::currentJourney(int cj)
{
	currentj = cj;
}
template<class T>
void buses<T>::setJourneysCompleted(int journeyC)
{
	journeycomp = journeyC
}
template<class T>
string buses<T>::getType()
{
	return Type;
}
template<class T>
const buses<T>::getCapacity()
{
	return capacityy;
}

template<class T>
const buses<T>::getcurrentJourney()
{
	return currentj;
}

template<class T>
const buses<T>::getCheckupTime()
{
	return checkupTimee;
}

template<class T>
const buses<T>::getJourneysCompleted()
{
	return journeycomp;
}
template<class T>
void buses<T>::startMaintenance()
	{
		if (time == time.offhours)
			maintenanceInProgress = true;
	}

template<class T>
void buses<T>::finishMaintenance()
	{
		maintenanceInProgress = false;
		currentJourney = 0;
	}

template<class T>
void buses<T>::moveToNextStation() {
		if (!passengers.isEmpty() || /* Logic to check waiting passengers in the same direction */) {
			currentStation++;
		}
		else {
			// If there are no passengers, return to Station #0
			currentStation = 0;
		}
		currentJourney++;
	}

template<class T>
bool buses<T>::passengerGetOn(const Passenger& passenger)
	{
		if (!maintenanceInProgress && passengers.getQueueSize() < capacity && time != offtime)
		{
			if (passenger.getPassengerType() == WP)
			{
				WP.push(passenger, passenger.getEndStation());
			}
			else if (passenger.getPassengerType() == NP)
			{
				NP.push(passenger, passenger.getEndStation())
			}
			else
				SP.push(passenger, passenger.getEndStation())

			return true;
		}
		return false;
	}

template<class T>
void buses<T>::Passengersgetoff(int currentTime)
	{
		getoff(WP, currentTime);
		getoff(NP, currentTime);
		getoff(SP, currentTime);
	}
template<class T>
double buses<T>::getUtilization(int totalSimulationTime)
	{
		if (n == 0)
		{
			u = 0;
		else
			u = tDC / (BC * N) * (tBT / TSim);
		}
	}