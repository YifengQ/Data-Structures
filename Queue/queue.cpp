//
// Created by yifengq on 4/10/18.
//

#include "queue.h"
#include <iostream>
using namespace std;
/**
 * @brief Default C-tor
 * @pre When a class object is called it gives it default values
 * @post Will give all the values 0
 */
queue::queue() {

    for (int i = 0; i < EVENTS ; ++i) {
        bankLine[i].setArrival(0);
        bankLine[i].setDuration(0);
        bankLine[i].setWaitTime(0);
        bankLine[i].setDeparture(0);
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
void queue::setLine(int index , int arrival, int duration) {

    bankLine[index].setArrival(arrival);
    //int test = bankLine[index].getArrival();
    //cout << "set" << test << endl;
    bankLine[index].setDuration(duration);
}


/**
 * @brief Will procces the arrival time for that index
 * @param index
 * @param time
 * @pre Will take in current time to set the wait time
 * @post Will set the wait time for that index, and set the tller to false
 */
void queue::processArrival(int index, int time ) {

    int arrival = bankLine[index].getArrival();

    //cout << "arrival" << arrival << endl;
    int wait = time - arrival;

    if(wait < 0){
        wait =0;
    }

    bankLine[index].setWaitTime(wait);
    avail = false;
}

/**
 * @brief Will proccess the departure time and all the other data
 * @param index
 * @pre Will take in the index to get and set data for that index
 * @post Will calcualte the departure time for the customer
 */
void queue::processDeparture(int index) {

    int arrival = bankLine[index].getArrival();
    int duration = bankLine[index].getDuration();
    int wait = bankLine[index].getWaitTime();
    int depart = arrival + duration + wait;
    bankLine[index].setDeparture(depart);
    avail = true;
}

/**
 * @brief Will set the teller to true or false
 * @param a
 * @pre Takes in a bool value to set
 * @post sets the availibility to a
 */
void queue::setAvail(bool a) {

    avail = a;
}

/**
 * @brief Will check if it is empty
 * @param index
 * @return bool
 * @pre Will check that index position
 * @post If the index goes over the set amount it is at the end
 */
bool queue::isEmpty(int index) {

    if(index <= EVENTS) {

        return true;
    }
    return false;

}


int queue::getArrival(int i) {
    return bankLine[i].getArrival();
}

int queue::getDepart(int i) {
    return bankLine[i].getDeparture();
}

int queue::getWait(int i) {
    return bankLine[i].getWaitTime();
}

/**
 * @breif Will reset the values for the next question
 * @post Will set all the values back to zero and all bool values to their postions
 */
void queue::reset() {

    for (int i = 0; i < EVENTS ; ++i) {
        bankLine[i].setArrival(0);
        bankLine[i].setDuration(0);
        bankLine[i].setWaitTime(0);
        bankLine[i].setDeparture(0);
    }

    setAvail(true);
    isEmpty(false);
}

int queue::getDuration(int i) {
    return bankLine[i].getDuration();
}


