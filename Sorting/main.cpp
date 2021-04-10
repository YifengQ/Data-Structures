#include <iostream>
#include <fstream>
#include <ctime>
#include "proj4.h"

using namespace std;

int generate(int amount);

int main() {

    srand(time(NULL));
    int maxNum = 1000000;
    int numRuns = 1000;
    int loop = 1;
    int array[numRuns];

    ///declares all the log files
    ofstream logB, logQ, logR, logBubble, logQuick, logRadix;
    ///clears all the log files, don't know why clear(); wasn't working for me

    logB.open("bubble_data.txt");
    logB.close();
    logQ.open("quick_data.txt");
    logQ.close();
    logR.open("radix_data.txt");
    logR.close();
    logBubble.open("bubble_sort.txt");
    logBubble.close();
    logQuick.open("quick_sort.txt");
    logQuick.close();
    logRadix.open("radix_sort.txt");
    logRadix.close();

    ///opens all the files
    logB.open("bubble_data.txt", std::ofstream::out | std::ofstream::app);
    logQ.open("quick_data.txt", std::ofstream::out | std::ofstream::app);
    logR.open("radix_data.txt", std::ofstream::out | std::ofstream::app);

    logBubble.open("bubble_sort.txt", std::ofstream::out | std::ofstream::app);
    logQuick.open("quick_sort.txt", std::ofstream::out | std::ofstream::app);
    logRadix.open("radix_sort.txt", std::ofstream::out | std::ofstream::app);

    do {
        proj4 sort;
        ///sets the max items/runs

        sort.setMaxItems(numRuns);

        int value;
        ///will call generate to get a random number between 0 and the max, then give it to the array
        ///can comment out the generate to make a sorted list
        for (int i = 0; i < numRuns; i++) {

            value = generate(maxNum);
            array[i] = value;

            //array[i] = i;

        }


        for (int k = 0; k < numRuns ; ++k) {

            sort.insert(k, array[k]);
            logBubble << "Bubble(Before): " << sort.getNumber(k) << endl;
        }
        ///starts and stops the clock so i get the time interval between
        unsigned long long int start_s = clock();
        sort.bubble_sort();
        unsigned long long int stop_s = clock();
        logB << "//////////////////////////Bubble Sort" << "(" << loop << ")" << "////////////////////////////////////" << endl;
        logB << "time(seconds): " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << endl;
        logB << "swaps: " << sort.getSwaps() << endl;
        logB << "comparisons: " << sort.getComparisons() << endl;


        for (int z = 0; z < numRuns; ++z) {

            logBubble << "Bubble(After): " << sort.getNumber(z) << endl;
        }

        sort.clear();

        for (int l = 0; l < numRuns ; ++l) {
            sort.insert(l, array[l]);
            logQuick << "Merge(Before): " << array[l] << endl;
        }
        sort.setMaxItems(numRuns);
        unsigned long long int quick_start = clock();
        sort.mergeSort(0, numRuns - 1);
        unsigned long long int quick_stop = clock();
        logQ << "//////////////////////////Merge Sort" << "(" << loop << ")" << "////////////////////////////////////" << endl;
        logQ << "time(seconds): " << (quick_stop - quick_start) / double(CLOCKS_PER_SEC) << endl;
        logQ << "recursion: " << sort.getReursion() << endl;
        logQ << "left: " << sort.getLeft() << endl;
        logQ << "right: " << sort.getRight() << endl;


        for (int j = 0; j < numRuns; ++j) {

            logQuick << "Merge(After): " << sort.getNumber(j) << endl;
        }

        sort.clear();

        for (int m = 0; m < numRuns; ++m) {
            sort.insert(m, array[m]);
            logRadix << "Radix(Before): " << array[m] << endl;
        }
        sort.setMaxItems(numRuns);

        unsigned long long int radix_start = clock();
        sort.radixsort(numRuns - 1);
        unsigned long long int radix_stop = clock();
        logR << "//////////////////////////Count Sort" << "(" << loop << ")" << "////////////////////////////////////" << endl;
        logR << "time(seconds): " << (radix_stop - radix_start) / double(CLOCKS_PER_SEC) << endl;
        logR << "counts: " << sort.getCounts() << endl;
        logR << "exp: " << sort.getCountSorts() << endl;


        for (int j = 0; j < numRuns; ++j) {

            logRadix << "Radix(After): " << sort.getNumber(j) << endl;
        }

        sort.clear();
        loop++;

    }while(loop < 11); /// runs ten times


    logB.close();
    logQ.close();
    logR.close();
    logBubble.close();
    logQuick.close();
    logRadix.close();

    return 0;
}


int generate(int amount){

    int num = 0;
    num = rand() % amount + 1;

    return num;
}