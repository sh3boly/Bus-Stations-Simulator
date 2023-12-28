#include "bus.h"

template<class T>
void bus<T>::getoff(Linkedqueue<passengers>& passengerQueue, int currentTime)
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
bus<T>::bus()
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
void bus<T>::setType(string T)
{
	Type = T;
}

template<class T>
void bus<T>::setCapacity(int capacity)
{
	capacityy = capacity;
}

template<class T>
void bus<T>::setCheckupTime(int checkupTime)
{
	checkupTimee = checkupTime;
}

template<class T>
void bus<T>::currentJourney(int cj)
{
	currentj = cj;
}

template<class T>
void bus<T>::setJourneysCompleted(int journeyC)
{
	journeycomp = journeyC
}

template<class T>
string bus<T>::getType()
{
	return Type;
}

template<class T>
const bus<T>::getCapacity()
{
	return capacityy;
}

template<class T>
const bus<T>::getcurrentJourney()
{
	return currentj;
}

template<class T>
const bus<T>::getCheckupTime()
{
	return checkupTimee;
}

template<class T>
const bus<T>::getJourneysCompleted()
{
	return journeycomp;
}

template<class T>
int bus<T>::maintenanceJourneys()
{
	return maintenanceJourneys;
}

template<class T>
bool bus<T>::isMaintenanceDue()
{
	return currentJourney % maintenanceJourneys == 0;
}

template<class T>
void bus<T>::startMaintenance()
{
	if (time == time.offhours)
		maintenanceInProgress = true;
}

template<class T>
void bus<T>::finishMaintenance()
{
	maintenanceInProgress = false;
	currentJourney = 0;
}

template<class T>
void bus<T>::moveToNextStationforward()
{
	if (!passengers.isEmpty())
	{
		currentStation = (currentStation + 1);
	else
	{
		currentStation = 1;
		currentJourney++;
		if (isMaintenanceDue())
		{
			startMaintenance(currentTime);
		}
	}

	}

}
template<class T>
void bus<T>::moveToNextStationbackward()
{
	if (!passengers.isEmpty())
	{
		currentStation = (currentStation - 1);
	else
	{
		currentStation = s;
		currentJourney++;
		if (isMaintenanceDue())
		{
			startMaintenance(currentTime);
		}
	}

	}

}
template<class T>
void  bus<T>::passengerGetOn(const Passenger& passenger, int  currentTime)
{
	if (getType() == "wbus" && passenger.getPassengerType() == WP) {
		if (passengers.getQueueSize() < capacity) {
			passengers.enqueue(passenger, passenger.getPassengerType());
			currentPassenger.setMoveTime(time.currentTime);


			return true;
		}
		else {
			cout << "bus is full" << endl
		}
	}
	else if (getType() == "Mbus" && passenger.getPassengerType() != WP)
	{
		if (passengers.getQueueSize() < capacity) {
			passengers.enqueue(passenger, passenger.getPassengerType());
			currentPassenger.setmoveTime(time.currentTime);

		}
		else {
			cout << "bus is full" << endl
		}
	}
	else {
		cout << " the passenger cannot get in this bus" << endl

			return false;
	}
}
template<class T>
void bus<T>::Passengersgetoff(Linkedqueue<passengers>& passengerQueue, int currentTime)
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
double bus<T>::getUtilization(int totalSimulationTime)
{
	if (n == 0)
	{
		return  0;
	else
		return (tDC / (BC * N) * (tBT / TSim));
	};
}
template<class T>
int getCheckupTime()
{
	return checkupTimee;
}