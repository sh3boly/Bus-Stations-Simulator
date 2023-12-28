#include "LinkedQueue.h"
#include "pass.h"

class LinkedQueuePassengers {
    private:
        Linkedqueue<Passenger> queue;
    public:
        /**
         * @brief Construct a new Priority Queue Passengers object
         * 
         */
        LinkedQueuePassengers();
        /**
         * @brief Destroy the Priority Queue Passengers object
         * 
         */
        ~LinkedQueuePassengers();
        /**
         * @brief Get the Queue Size 
         * 
         * @return int
         */
        int getQueueSize();
        /**
         * @brief Check if the Queue is Empty
         * 
         * @return true
         */
        bool isEmpty();
        /**
         * @brief Enqueue a Passenger
         * 
         * @param passenger 
         */
        void getOn(Passenger passenger);
        /**
         * @brief Dequeue a Passenger
         * @param passenger 
         * @return true 
         */
        bool getOff(Passenger& passenger);
        
        /**
         * @brief Get the Front Passenger
         * @param passenger
         * @return Passenger 
         */
        void getFront(Passenger& passenger);
};
        