//
// Created by yifengq on 4/10/18.
//

#ifndef CS302_PROJ5_QUEUE_H
#define CS302_PROJ5_QUEUE_H

#define EVENTS 99999 ///Number of Events
#define sRANGE 100000 ///Max Start Time
#define dRANGE 100 ///Max Duration Time

#include "arrayQueue.h"
class queue{

    friend class arrayList;
public:
    queue();
    void setLine(int , int, int);
    void processArrival(int, int);
    void processDeparture(int index);

    void setAvail(bool);
    bool getAvail();

    bool isEmpty(int);

    void setArrival(int);
    int getArrival(int);

    void reset();
    int getDuration(int);
    int getDepart(int i);
    int getWait(int );
private:
    arrayList bankLine[EVENTS];
    int currentTime;
    bool avail;
};


#endif //CS302_PROJ5_QUEUE_H
