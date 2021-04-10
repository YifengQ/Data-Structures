//
// Created by yifengq on 4/6/18.
//

#ifndef CS302_PROJ5_ARRAYLIST_H
#define CS302_PROJ5_ARRAYLIST_H
#define EVENTS 99999 ///Number of Events
#define sRANGE 100000 ///Max Start Time
#define dRANGE 100 ///Max Duration Time

class arrayList {

    friend class queue;
public:

    void setArrival(int);
    int getArrival();

    void setDuration(int);
    int getDuration();

    void setWaitTime(int);
    int getWaitTime();

    void setDeparture(int);
    int getDeparture();
private:
    int arrival;
    int duration;
    int departure;
    int waitTime;
};








#endif //CS302_PROJ5_ARRAYLIST_H
