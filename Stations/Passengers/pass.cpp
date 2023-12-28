
#include "pass.h"

Passenger::Passenger() {
    arrivalTime = "";
    startStation = "";
    endStation = "";
    getOnOffTime = 0;
    passengerType = NP;
    specialPassengerType = Aged;
    busID = 0;
    seatNumber = 0;
}

Passenger::Passenger(string arrivalTime, string startStation, string endStation, int getOnOffTime, PassengerType passengerType, SpecialPassengerType specialPassengerType, int busID, int seatNumber) {
    this->arrivalTime = arrivalTime;
    this->startStation = startStation;
    this->endStation = endStation;
    this->getOnOffTime = getOnOffTime;
    this->passengerType = passengerType;
    this->specialPassengerType = specialPassengerType;
    this->busID = busID;
    this->seatNumber = seatNumber;
}

string Passenger::getArrivalTime() {
    return arrivalTime;
}

string Passenger::getStartStation() {
    return startStation;
}

string Passenger::getEndStation() {
    return endStation;
}

int Passenger::getGetOnOffTime() {
    return getOnOffTime;
}

PassengerType Passenger::getPassengerType() {
    return passengerType;
}

SpecialPassengerType Passenger::getSpecialPassengerType() {
    return specialPassengerType;
}

int Passenger::getBusID() {
    return busID;
}

int Passenger::getSeatNumber() {
    return seatNumber;
}

void Passenger::setArrivalTime(string arrivalTime) {
    this->arrivalTime = arrivalTime;
}

void Passenger::setStartStation(string startStation) {
    this->startStation = startStation;
}

void Passenger::setEndStation(string endStation) {
    this->endStation = endStation;
}

void Passenger::setGetOnOffTime(int getOnOffTime) {
    this->getOnOffTime = getOnOffTime;
}

void Passenger::setPassengerType(PassengerType passengerType) {
    this->passengerType = passengerType;
}

void Passenger::setSpecialPassengerType(SpecialPassengerType specialPassengerType) {
    this->specialPassengerType = specialPassengerType;
}

void Passenger::setBusID(int busID) {
    this->busID = busID;
}

void Passenger::setSeatNumber(int seatNumber) {
    this->seatNumber = seatNumber;
}

PassengersData Passenger::getPassenger() {
    PassengersData passenger;
    passenger.arrivalTime = arrivalTime;
    passenger.startStation = startStation;
    passenger.endStation = endStation;
    passenger.getOnOffTime = getOnOffTime;
    passenger.passengerType = passengerType;
    passenger.specialPassengerType = specialPassengerType;
    passenger.busID = busID;
    passenger.seatNumber = seatNumber;
    return passenger;
}

void Passenger::setPassenger(PassengersData passenger) {
    arrivalTime = passenger.arrivalTime;
    startStation = passenger.startStation;
    endStation = passenger.endStation;
    getOnOffTime = passenger.getOnOffTime;
    passengerType = passenger.passengerType;
    specialPassengerType = passenger.specialPassengerType;
    busID = passenger.busID;
    seatNumber = passenger.seatNumber;
}

Passenger::~Passenger() {
    arrivalTime = "";
    startStation = "";
    endStation = "";
    getOnOffTime = 0;
    passengerType = NP;
    specialPassengerType = Aged;
    busID = 0;
    seatNumber = 0;
}
