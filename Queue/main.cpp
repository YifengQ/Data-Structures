#include <iostream>
#include <fstream>
#include <ctime>
#include "arrayQueue.h"
//#include "linkedList.h"
#include "queue.h"
#define EVENTS 99999 ///Number of Events
#define sRANGE 100000 ///Max Start Time
#define dRANGE 100 ///Max Duration Time
using namespace std;

int generate(int);
void createArrival(int []);
void createDuration(int []);
void countSort(int [] ,int n, int exp);
int getMax(int [], int n);
void radixSort(int [], int n);
void printData(int [], int[]);
void insert(queue& sim);
void simulation1(queue& sim);
void simulation2(queue& sim);
void getData(queue& sim, int, int, int);
int getLineLength(queue& sim);

int main() {
    //array based
    unsigned long long int virtualStart = clock();
    //linkedList list;
    ofstream log;
    log.clear();
    int arrival[EVENTS];
    int duration[EVENTS];
    queue sim;
    createArrival(arrival);
    radixSort(arrival, EVENTS);
    createDuration(duration);
    printData(arrival, duration);
    insert(sim);
    unsigned long long int simulationStart = clock();
    simulation1(sim);
    unsigned long long int simulationEnd = clock();
    //insert(sim);
    simulation2(sim);
    //Linked List
    unsigned long long int virtualEnd = clock();
    log.open("log.txt", std::ofstream::out | std::ofstream::app);

    log << "Simulation Time(seconds): " << (simulationEnd - simulationStart) / double(CLOCKS_PER_SEC) << endl;
    log << "Virtual Time(seconds): " << (virtualEnd - virtualStart) / double(CLOCKS_PER_SEC) << endl;
    log.close();
    return 0;

}
/**
 * @brief Generates a random number between a range
 * @param range , max value
 * @return num , number generated
 * @pre Takes in the Max number, to generate a number between it
 * @post Generates a random number between 0 and the Max number. It then returns that value
 */
int generate(int range){

    int num = 0;
    num = rand() % range + 1;

    return num;
}

/**
 * @brief Creates a random start time
 * @param start, array containing arrival times
 * @pre Takes in the arrival array to give it values
 * @post Calls the generate function to generate a random value and give it to the arrival array
 */
void createArrival(int start[]){

    srand(time(NULL));

    for (int i = 0; i < EVENTS; ++i) {

        start[i] = generate(sRANGE);
    }

}

/**
 * @brief Creates a random duration time
 * @param duration ,array containing duration times
 * @pre Takes in the duration array to give it values
 * @post Calls the generate function to generate a random value and give it to the duration array
 */
void createDuration(int duration[]){
    
    srand(time(NULL));

    for (int i = 0; i < EVENTS; ++i) {
        
        duration[i] = generate(dRANGE);

    }

}

/**
 * @brief has temp array to store the values, then a count array to the  position of the number, it then builds the output array and sets the array to the output array
 * @param n , length of the array
 * @param exp ,  exponent it is on
 * @return none
 * @pre takes in the lenght of the array and the exponent it is on to sort the array
 * @post takes the exponents and sorts them based on that
 */
void countSort(int arrival[], int n, int exp) {

    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arrival[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arrival[i]/exp)%10 ] - 1] = arrival[i];
        count[ (arrival[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++) {
        arrival[i] = output[i];
    }

}

/**
 * @breif Will do a count sort for all digits, it uses the exponent to tell what number it is on
 * @param n
 * @return none
 * @pre Will take in the length of the array to find the max number, and then call count sort for all the digits
 * @post Calls count sort to sort the array
 */
void radixSort(int arrival[], int n) {
    int m = getMax(arrival, n - 1);

    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(arrival, n, exp);
    }
}

/**
 * @breif gets the biggest element in the array
 * @param n
 * @return temp, largest element
 * @pre takes the length of the array and gets the largest value
 * @post runs through the array to find the largest value
 */
int getMax(int arrival[], int n) {
    int max = arrival[0];
    for (int i = 1; i < n; i++) {
        if (arrival[i] > max) {
            max = arrival[i];
        }
    }
    return max;
}

/**
 * @brief Prints the arrival and duration time for 1 event on 1 line
 * @param arrival , array for arrival times
 * @param duration ,array for duration times
 * @pre Takes in arrival and duration arrays to get the data
 * @post Opens a log file to store the numbers to be read for all queues
 */
void printData(int arrival[], int duration[]){

    ofstream data ;
    data.clear();
    data.open("data.txt");

    //data << "Start  Duration" << endl;
    for (int i = 0; i < EVENTS; ++i) {

        data << arrival[i] << " " << duration[i] << endl;
    }

    data.close();
}
/**
 * @brief Inserts the arrival and duration times into the queue
 * @param sim
 * @pre Takes in the the class object to update queue
 * @post Will set all the values in the line for the queue
 */
void insert(queue& sim){


    ifstream data;
    data.open("data.txt");

    int a;
    int d;

    for (int i = 0; i < EVENTS ; ++i) {

        data >> a >> d;
        sim.setLine(i, a, d);
        //cout << "arr" << a << "dur" << d << endl;
    }

    data.close();

}
/**
 * @brief This is the single queue for a single teller
 * @param sim
 * @pre Takes in the queue to run the simulation
 * @post Will process the arrival and departure giving a lot of the info
 */
void simulation1(queue& sim){


    int i= 0;
    int currentTime = 0;
    int length = 0;
    int temp = 0;
    int totalLength= 0;
    for(i=0; i  <= EVENTS - 1 ; i++){

        length = getLineLength(sim);
        totalLength += length;
        sim.processArrival(i, currentTime);
        sim.processDeparture(i);
        currentTime = sim.getDepart(i);

        ///finds the max length of the line
        if(length > temp ){
            temp = length;
        }

    }
    int idle = sim.getArrival(0);
    getData(sim, temp, totalLength, idle);
    //sim.reset();
}
/**
 * @brief This is the single queue for a three tellers
 * @param sim
 * @pre Takes in the queue to run the simulation
 * @post Will process the arrival and departure giving a lot of the info
 */
void simulation2(queue& sim){

    int i= 0;
    int currentTime = 0;
    int length = 0;
    int temp = 0;
    int totalLength= 0;
    bool teller1 = true;
    bool teller2 = true;
    bool teller3 = true;

    while(i < EVENTS - 1){

        if(teller1) {
            teller1=false;
            int k =0;
            int time = 0;
            length = getLineLength(sim);
            totalLength += length;
            sim.processArrival(i, currentTime);
            sim.processDeparture(i);
            currentTime = sim.getDepart(i);
            time = sim.getDuration(i);
            while(k <= time){

                k++;
            }
            i++;
            teller1 = true;
        }
        if(teller2) {
            teller2=false;
            int x =0;
            int time = 0;
            length = getLineLength(sim);
            totalLength += length;
            sim.processArrival(i, currentTime);
            sim.processDeparture(i);
            currentTime = sim.getDepart(i);
            time = sim.getDuration(i);
            while(x <= time){
                x++;
            }
            i++;
            teller2 = true;
        }
       if(teller3) {
           teller3=false;
            int z =0;
            int time = 0;
            length = getLineLength(sim);
            totalLength += length;
            sim.processArrival(i, currentTime);
            sim.processDeparture(i);
            currentTime = sim.getDepart(i);
            time = sim.getDuration(i);
            while(z <= time){
                z++;
            }
            i++;
           teller3 = true;
        }

        ///finds the max length of the line
        if(length > temp ){
            temp = length;
        }

    }
    int idle = sim.getArrival(0);
    getData(sim, temp, totalLength, idle);
}
/**
 * @brief Will calculate the averages for the data required
 * @param sim
 * @param mLength
 * @param totalLength
 * @param idleTime
 * @pre Will take in all the data to be proccessed
 * @post Takes in the queue data and does the appropriate calculations to find requested values. It will also print to a log file.
 */
void getData(queue& sim, int mLength, int totalLength, int idleTime){

    ofstream log;
    log.open("log.txt", std::ofstream::out | std::ofstream::app);

    int long wait= 0;
    int temp = 0;
    for (int i = 0; i < EVENTS; ++i) {

        wait += sim.getWait(i);

        if(wait > temp)
        {
            temp = wait;
        }
    }

    ///gets the average wait time
    int avgWait = wait / EVENTS;
    int avgLength = totalLength / EVENTS;

    log << " avg wait: " << avgWait << " max wait: " << temp << " max length: "<< mLength << " avg length: "<< avgLength << " idle time: "<< idleTime << endl;
    log.close();
}

/**
 * @brief Will get the line length for that index
 * @param sim
 * @return count, line length
 * @pre Will take in the queue to run and find the queue length
 * @post Will run through the queue and and find the queue length for that instance
 */
int getLineLength(queue& sim){

    int count = 0;
    for (int i = 0; i < EVENTS; ++i) {

        if(sim.getWait(i) > 0){

            count ++;
        }
    }

    return count;
}
