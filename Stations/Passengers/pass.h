#include <iostream>
#include <string>
using namespace std;
/*
Passengers:
The following pieces of information are available for each passenger:
- Arrival Time: the time (hh:mm) when the passenger arrives at the station and is ready to get on a bus.
- Passenger's start and end stations.
- Passenger Get ON/OFF Time: it is the time (in seconds)needed for one passenger to get on/off the bus.
- Passenger Type: There are 3 types of passengers:
• (SP) Special categories passengers: Those are the passengers that have the highest priority to get on the bus before others. SP type includes 3 subcategories: aged passengers, POD (people of determination), and pregnant women
• (WP) passengers with wheelchairs have to use special types of buses that are equipped for that purpose.
• (NP) Normal passengers: all other passenger
*/
/**
 * @brief this class is used to store the information of each passenger
 * @param arrivalTime the time (hh:mm) when the passenger arrives at the station and is ready to get on a bus.
 * @param startStation the station where the passenger will get on the bus
 * @param endStation the station where the passenger will get off the bus
 * @param getOnOffTime the time (in seconds)needed for one passenger to get on/off the bus.
 * @param passengerType the type of the passenger
 * @param busID the ID of the bus that the passenger will get on
 * @param seatNumber the seat number of the passenger in the bus
*/

enum SpecialPassengerType {Aged, POD, Pregnant};
struct SP{
    SpecialPassengerType specialPassengerType;
};
enum PassengerType {SP, WP, NP};
struct PassengersData {
    string arrivalTime;
    string startStation;
    string endStation;
    int getOnOffTime;
    PassengerType passengerType;
    SpecialPassengerType specialPassengerType;
    int busID;
    int seatNumber;
};
class Passenger {
    private:
        string arrivalTime;
        string startStation;
        string endStation;
        int getOnOffTime;
        PassengerType passengerType;
        SpecialPassengerType specialPassengerType;
        int busID;
        int seatNumber;
    public:
        /**
         * @brief Construct a new Passenger object
         * 
         */
        Passenger();
        Passenger(string arrivalTime, string startStation, string endStation, int getOnOffTime, PassengerType passengerType, SpecialPassengerType specialPassengerType, int busID, int seatNumber);
        /**
         * @brief Get the Arrival Time object
         * 
         * @return string 
         */
        string getArrivalTime();
        /**
         * @brief Get the Start Station object
         * 
         * @return string 
         */
        string getStartStation();
        /**
         * @brief Get the End Station object
         * 
         * @return string 
         */
        string getEndStation();
        /**
         * @brief Get the Get On Off Time object
         * 
         * @return int 
         */
        int getGetOnOffTime();
        /**
         * @brief Get the Passenger Type object
         * 
         * @return PassengerType 
         */
        PassengerType getPassengerType();
        /**
         * @brief Get the Special Passenger Type object
         * 
         * @return SpecialPassengerType 
         */
        SpecialPassengerType getSpecialPassengerType();
        /**
         * @brief Get the Bus ID object
         * 
         * @return int 
         */
        int getBusID();
        /**
         * @brief Get the Seat Number object
         * 
         * @return int 
         */
        int getSeatNumber();
        /**
         * @brief Set the Arrival Time object
         * 
         * @param arrivalTime 
         */
        void setArrivalTime(string arrivalTime);
        /**
         * @brief Set the Start Station object
         * 
         * @param startStation 
         */
        void setStartStation(string startStation);
        /**
         * @brief Set the End Station object
         * 
         * @param endStation 
         */
        void setEndStation(string endStation);
        /**
         * @brief Set the Get On Off Time object
         * 
         * @param getOnOffTime 
         */
        void setGetOnOffTime(int getOnOffTime);
        /**
         * @brief Set the Passenger Type object
         * 
         * @param passengerType 
         */
        void setPassengerType(PassengerType passengerType);
        /**
         * @brief Set the Special Passenger Type object
         * 
         * @param specialPassengerType 
         */
        void setSpecialPassengerType(SpecialPassengerType specialPassengerType);
        /**
         * @brief Set the Bus ID object
         * 
         * @param busID 
         */
        void setBusID(int busID);
        /**
         * @brief Set the Seat Number object
         * 
         * @param seatNumber 
         */
        void setSeatNumber(int seatNumber);
        /**
         * @brief Get the Passenger object
         * 
         * @return PassengersData 
         */
        PassengersData getPassenger();
        /**
         * @brief Set the Passenger object
         * 
         * @param passenger 
         */
        void setPassenger(PassengersData passenger);
        /**
         * @brief Destroy the Passenger object
         * 
         */
        ~Passenger();
};
