//
// Created by yifengq on 4/6/18.
//

#include "linkedList.h"

/**
 * @Brief Sets the arrival time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set arrival to the variable
 */
void linkedList::setArrival(int a) {
    arrival = a;
}
/**
 * @breif Will get the arrival time
 * @return arrival
 */
int linkedList::getArrival() {
    return arrival;
}
/**
 * @Brief Sets the duration time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set duration to the variable
 */
void linkedList::setDuration(int d) {
    duration= d;
}
/**
 * @breif Will get the duration time
 * @return duration
 */
int linkedList::getDuration() {
    return duration;
}
/**
 * @Brief Sets the departure time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set wait to the variable
 */
void linkedList::setWaitTime(int w) {
    waitTime = w;
}
/**
 * @breif Will get the wait time
 * @return wait
 */
int linkedList::getWaitTime() {
    return waitTime;
}
/**
 * @Brief Sets the departure time
 * @param a
 * @pre Will take the variable and set arrival to it
 * @post Will set departure to the variable
 */
void linkedList::setDeparture(int d) {
    departure = d;
}

/**
 * @breif Will get the departure time
 * @return departure
 */
int linkedList::getDeparture() {
    return departure;
}
