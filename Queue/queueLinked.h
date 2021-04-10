//
// Created by yifengq on 4/10/18.
//

#ifndef CS302_PROJ5_QUEUELINKED_H
#define CS302_PROJ5_QUEUELINKED_H

#include "linkedList.h"

class queueLinked {

    friend class linkedList;
public:
    queueLinked();
    void setLine(int , int, int);
    void processArrival(int, int);
    void processDeparture(int index);

    void setAvail(bool);
    bool getAvail();

    bool isEmpty(int);

    void setArrival(int);
    int getArrival(int);

    void remove();

    int getDepart(int i);
    int getWait(int );
private:

    linkedList *bankLine;
    int currentTime;
    bool avail;
};




#endif //CS302_PROJ5_QUEUELINKED_H
