//
// Created by yifengq on 4/10/18.
//

#include "queueLinked.h"
/**
 * @brief Default C-tor
 * @pre When a class object is called it gives it default values
 * @post Will give all the values 0
 */
queueLinked::queueLinked() {

    for (int i = 0; i < EVENTS; ++i) {

        bankLine -> setArrival(0);
        bankLine -> setDuration(0);
        bankLine -> setWaitTime(0);
        bankLine++;
    }

    setAvail(true);
}
/**
 * @brief Will give the values of the arrival times and duration times
 * @param index
 * @param arrival
 * @param duration
 * @pre Will take in the index, arrival and duration time to give to the class
 * @post Will set the arrival and duration time for that index in the class
 */
void queueLinked::setLine(int index , int arrival, int duration) {

    bankLine += index;
    bankLine -> setArrival(arrival);
    bankLine -> setDuration(duration);

}
/**
 * @brief Will procces the arrival time for that index
 * @param index
 * @param time
 * @pre Will take in current time to set the wait time
 * @post Will set the wait time for that index, and set the tller to false
 */
void queueLinked::processArrival(int index, int time) {

    bankLine += index;
    int arrival = bankLine -> getArrival();

    int wait = time - arrival;

    if(wait < 0){
        wait =0;
    }

    bankLine -> setWaitTime(wait);
    avail = false;
}
/**
 * @brief Will proccess the departure time and all the other data
 * @param index
 * @pre Will take in the index to get and set data for that index
 * @post Will calcualte the departure time for the customer
 */
void queueLinked::processDeparture(int index) {

    bankLine += index;
    int arrival = bankLine -> getArrival();
    int duration = bankLine -> getDuration();
    int wait = bankLine -> getWaitTime();
    int depart = arrival + duration + wait;
    bankLine -> setDeparture(depart);
    avail = true;
}
/**
 * @brief Will set the teller to true or false
 * @param a
 * @pre Takes in a bool value to set
 * @post sets the availibility to a
 */
void queueLinked::setAvail(bool a) {
    avail = a;
}
/**
 * @brief Will check if it is empty
 * @param index
 * @return bool
 * @pre Will check that index position
 * @post If the index goes over the set amount it is at the end
 */
bool queueLinked::getAvail() {
    return avail;
}

bool queueLinked::isEmpty(int) {

    return false;
}

void queueLinked::setArrival(int) {

}

int queueLinked::getArrival(int index) {
    bankLine += index;
    return bankLine -> getArrival();
}

void queueLinked::remove() {

}

int queueLinked::getDepart(int i) {
    return 0;
}

int queueLinked::getWait(int) {
    return 0;
}

