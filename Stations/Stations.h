#pragma once
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Bus.h"

class Stations
{
	// Special Passegners queues
	PriorityQueue<Passenger*>* WaitingFWDSpecialPassengers;
	PriorityQueue<Passenger*>* WaitingBCKSpecialPassengers;
	// Wheel passengers queue
	LinkedQueue<Passenger*>* WaitingFWDWheelPassengers;
	LinkedQueue<Passenger*>* WaitingBCKWheelPassengers;
	// Normal Passenger Queue
	LinkedQueue<Passenger*>* WaitingFWDNormalPassengers;
	LinkedQueue<Passenger*>* WaitingBCKNormalPassengers;
	//LinkedQueue<int>* Busses;
	LinkedQueue<Buss*>* FWDBusses;
	LinkedQueue<Buss*>* BCKBusses;

	LinkedQueue<Passenger*>* FinishList;

	int stationNumber;
	
	bool isStationZero;
	int countBuses;
	int timeBetweenEachStation;
	int cWP; // count for WP
	int cSP; // count for SP
	int cNP; // count for FWD NP
	int cBCKNP;
	LinkedList<int> finished;
	int lastFinished;
public:
	Stations();
	Stations(int time, int no); 
	void addWaitingBus(Buss* Bus);
	void addWaitingPassenger(Passenger *p, int number);
	void removeWaitingPassenger(int id, int number);
	void boardWPPassenger();
	void boardPassenger();
	void upgradePassenger(int maxW);
	Buss* removeFWDBus();
	Buss* removeBCKBus();
	void addFWDBuss(Buss* b);
	void addBCKBuss(Buss* b);
	int getStationNumber();
	bool moveOneNPPassenger();
	bool moveOneWPPassenger();
	bool moveOneSPPassenger();
	int getCSP();
	int getCNP();
	int getCWP();
	friend ostream& operator<<(ostream& os, const Stations& station) {
		// SP Pritning code
			os << station.cSP << " Waiting SP";
			PriorityQueue<Passenger*> tempQFWD(*station.WaitingFWDSpecialPassengers);
			PriorityQueue<Passenger*> tempQBCK(*station.WaitingBCKSpecialPassengers);

			//temp = station.WaitingSpecialPassengers;
			Passenger* p;
			os << "FWD[";
			while (!(tempQFWD.isEmpty())) {
				tempQFWD.dequeue(p);

				os << p->getID() << "(";
				if (p->getSType() == "Preg") {
					os << "PG";
				}
				else if (p->getSType() == "POD") {
					os << "PD";
				}
				else if (p->getSType() == "aged") {
					os << "AG";
				}
				os << "),";
			}
			os << "] "; 
			os << "BCK[";
			while (!(tempQBCK.isEmpty())) {
				tempQBCK.dequeue(p);

				os << p->getID() << "(";
				if (p->getSType() == "Preg") {
					os << "PG";
				}
				else if (p->getSType() == "POD") {
					os << "PD";
				}
				else if (p->getSType() == "aged") {
					os << "AG";
				}
				os << "),";
			}
			os << "]" << endl;
			// 
			//WP Printing code
			LinkedQueue<Passenger*>tempQWFWD (*station.WaitingFWDWheelPassengers);
			LinkedQueue<Passenger*>tempQWBCK (*station.WaitingBCKWheelPassengers);

			os << station.cWP << " Waiting WP";
			//tempW = station.WaitingWheelPassengers;
			Passenger* p1;
			os << "FWD[";
			while(!(tempQWFWD.isEmpty())){
				tempQWFWD.dequeue(p1);
				os << p1->getID() << ",";
			}
			os << "] " << "BCK[";
			while (!(tempQWBCK.isEmpty())) {
					tempQWBCK.dequeue(p1);
					os << p1->getID() << ",";
				}
			os << "]" << endl;
			// NP Printing code
			LinkedQueue<Passenger*>tempQNFWD(*station.WaitingFWDNormalPassengers);
			LinkedQueue<Passenger*>tempQNBCK(*station.WaitingBCKNormalPassengers);

			os << station.cNP << " Waiting WP";
			//tempN = station.WaitingNormalPassengers;
			Passenger* p2;
			os << "FWD[";
			while (!(tempQNFWD.isEmpty())) {
				tempQNFWD.dequeue(p2);
				os << p2->getID() << ",";
			}
			os << "] " << "BCK[";
			while (!(tempQNBCK.isEmpty())) {
				tempQNBCK.dequeue(p2);
				os << p2->getID() << ",";
			}
			os << "]" << endl;
			int count = station.finished.getCount();
			os << count << " Finsihed passengers: ";
			if (station.finished.isEmpty()) {
				os << "No finished passegner" << endl;
			}
			else {
				station.finished.PrintList();
			}
		
			os << "--------------------------------------------" << endl;
			LinkedQueue<Buss*>tempBFWD(*station.FWDBusses);
			LinkedQueue<Buss*>tempBBCK(*station.BCKBusses);
			Buss* b;
			//Passenger* Bp;
			//LinkedQueue<Passenger*>tempBP;

			os << station.countBuses << " Buses at this station: " << endl;
			int c;
			while (!tempBFWD.isEmpty()) {

				tempBFWD.dequeue(b);
					os << "B" << b->getID();
					os << "[" << b->getBusDirection();
					os << ", ";
					os << b->getType();
					os << ", " << b->getCapacity() << "] ";
					c = b->getCountPassenger();
					os << "{";
					if (c > 0) {
						for (int i = 1; i < c; i++) {
							if (i == c - 1) {
								os << b->getPassengerID(i);
							}
							else {
								os << b->getPassengerID(i) << ", ";
							}
						}
					}
					os << "}" << endl;
			}
			while (!tempBBCK.isEmpty()) {
				tempBBCK.dequeue(b);
				if (c == 1) {
					os << b->getID();
					c--;
				}
				else {
					os << b->getID() << ",";
					c--;
				}
			}
			os << endl;
			return os;
		}


};

