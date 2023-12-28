#include "LinkedQueuePassengers.h"
#include <iostream>
#include <string>
using namespace std;
LinkedQueuePassengers::LinkedQueuePassengers() {
    queue = Linkedqueue<Passenger>();
}
LinkedQueuePassengers::~LinkedQueuePassengers() {
    queue.~Linkedqueue();
}
int LinkedQueuePassengers::getQueueSize() {
    return queue.getcount();
}
bool LinkedQueuePassengers::isEmpty() {
    return queue.getcount() == 0;
}
void LinkedQueuePassengers::getOn(Passenger passenger) {
    queue.enqueue(passenger,passenger.getPassengerType());
}
bool LinkedQueuePassengers::getOff(Passenger& passenger) {
    return queue.dequeue(passenger);
}
void LinkedQueuePassengers::getFront(Passenger& passenger) {
     queue.peek(passenger);
}
