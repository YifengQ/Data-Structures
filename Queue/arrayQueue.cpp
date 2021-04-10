//
// Created by yifengq on 4/6/18.
//

#include "arrayQueue.h"
#include <iostream>
using namespace std;

/**
 * @Brief Sets the arrival time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set arrival to the variable
 */
void arrayList::setArrival(int a) {

    arrival = a;
    //cout << "a: " << arrival << endl;
}

/**
 * @breif Will get the arrival time
 * @return arrival
 */
int arrayList::getArrival() {
    //cout << "a: " << arrival << endl;
    return arrival;
}

/**
 * @Brief Sets the duration time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set duration to the variable
 */
void arrayList::setDuration(int d) {

    duration= d;
}

/**
 * @breif Will get the duration time
 * @return duration
 */
int arrayList::getDuration() {
    return duration;
}

/**
 * @Brief Sets the departure time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set wait to the variable
 */
void arrayList::setWaitTime(int w) {

    waitTime = w;
}

/**
 * @breif Will get the wait time
 * @return wait
 */
int arrayList::getWaitTime() {
    return waitTime;
}

/**
 * @Brief Sets the departure time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set departure to the variable
 */
void arrayList::setDeparture(int d) {

    departure = d;
}

/**
 * @breif Will get the departure time
 * @return departure
 */
int arrayList::getDeparture() {
    return departure;
}
