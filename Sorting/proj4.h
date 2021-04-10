//
// Created by yifengq on 3/21/18.
//

#ifndef CS302_PROJ4_PROJ4_H
#define CS302_PROJ4_PROJ4_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class proj4 {

public:
    proj4();

    bool insert(int position, int value);

    void clear();
    void setMaxItems(int items);
    unsigned int getSwaps();
    unsigned int getComparisons();
    unsigned int getPartitions();
    unsigned int getCountSorts();
    unsigned int getCounts();

    int getReursion();
    int getLeft();
    int getRight();
    ///just a function that shows how it is working

    int getNumber(int position);


    void bubble_sort();
    void swap(int *xp, int *yp);

    void quick_sort(int low, int high);
    int partition(int low, int high);

    void count_sort(int n, int exp);
    int getMax(int n);
    void radixsort(int n);

    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
private:

    static const int DEFAULT = 1000000;
    int items[DEFAULT];
    int itemCount;
    int maxItems;
    unsigned int swaps;
    unsigned int comparisons;
    unsigned int partitions;
    unsigned int countSorts;
    unsigned int counts;
    int recursions;
    int left;
    int right;
};


#endif //CS302_PROJ4_PROJ4_H
