//
// Created by yifengq on 3/21/18.
//

#include "proj4.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

/**
 * @breif Will give default values
 * @pre
 * @post Will give default values
 */
proj4::proj4() {

    itemCount = 0;
    swaps = 0;
    comparisons = 0;
    maxItems = DEFAULT;
    partitions = 0;
    countSorts = 0;
}

/**
 * @breif Inserts the element in that postion
 * @param position
 * @param value
 * @return true or false depending on if it can insert
 * @pre will take the position and value to add to the array
 * @post Will take position to give the value to that postion in the array
 */
bool proj4::insert(int position, int value) {

    bool check = (position >= 1) && (position <= itemCount + 1) && (itemCount < maxItems);

    if (check) {

        for(int pos = itemCount; pos >= position; pos--){
            items[pos +1] = items[pos];

        }

        items[position] = value;
        itemCount++;
    }
    return check;
}


/**
 * @breif Will reset all the values
 * @pre
 * @post Resets all the values
 */
void proj4::clear() {

    items[0] = '\0';
    itemCount = 0;
    swaps = 0;
    comparisons = 0;
    maxItems = 0;
    partitions = 0;
    countSorts = 0;
    counts = 0;
    recursions =0;
    right = 0;
    left = 0;
}

/**
 * @brief Will return the element at that postion
 * @param position
 * @return the element in that array
 * @pre takes in the position to find that element in that postion
 * @post Will return the item in that position in the array
 */
int proj4::getNumber(int position) {

    return items[position];
}

/**
 * @brief uses two for loops to go through the array and swap neighboring elements
 * @return none
 * @pre will sort the array
 * @post depending on the size of the array, it will run through it that many times to swap items
 */
void proj4::bubble_sort() {

    //cout << "test1" << endl;
    int i, j;
    for (i = 0; i < maxItems-1; i++) {
        //cout << "test2" << endl;
        // Last i elements are already in place
        for (j = 0; j < maxItems - i - 1; j++) {

            comparisons++;
            if (items[j] > items[j + 1]) {
                //cout << "test3" << endl;
                swap(&items[j], &items[j + 1]);
                swaps++;
            }

        }

    }
}

/**
 * @breif takes in two values and swaps them
 * @param xp
 * @param yp
 */
void proj4::swap(int *xp, int *yp) {

    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * @breif gives the max items and amount
 * @param items
 */
void proj4::setMaxItems(int items) {

    maxItems = items;

}

/**
 * @brief returns the amount of swaps
 * @return swaps
 */
unsigned int proj4::getSwaps() {

    return swaps;
}

/**
 * @brief returns the amount of comparisions
 * @return comparisons
 */
unsigned int proj4::getComparisons() {

    return comparisons;
}

/**
 * @brief gets the pivot position and uses recursive call to fully sort it
 * @param low
 * @param high
 * @pre takes the low and high to find the partition pivot
 * @post uses recursion to keep using the partition function to swap the elements till it is sorted
 */


void proj4::quick_sort(int low, int high) {

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quick_sort(low, pi - 1);
        quick_sort(pi + 1, high);
    }
}

/**
 * @brief Will take the pivot positions and compare it to the pivot point to find the postion  while swapping
 * @param low
 * @param high
 * @return pivot position
 * @pre will take in the low and high to compare the elemments in the array
 * @post will find the find the pivot and find if the element is samller to the pivot and swap them
 */
int proj4::partition(int low, int high) {

    int pivot = items[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        comparisons++;
        // If current element is smaller than or
        // equal to pivot
        if (items[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&items[i], &items[j]);
            swaps++;
        }
    }
    swap(&items[i + 1], &items[high]);
    swaps++;
    partitions++;
    return (i + 1);

}

/**
 * @brief has temp array to store the values, then a count array to the  position of the number, it then builds the output array and sets the array to the output array
 * @param n , length of the array
 * @param exp ,  exponent it is on
 * @return none
 * @pre takes in the lenght of the array and the exponent it is on to sort the array
 * @post takes the exponents and sorts them based on that
 */
void proj4 :: count_sort(int n, int exp) {

    int output[n + 1];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(items[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
        counts++;
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (items[i]/exp)%10 ] - 1] = items[i];
        count[ (items[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++) {
        items[i] = output[i];
    }
    countSorts++;
}

/**
 * @breif Will do a count sort for all digits, it uses the exponent to tell what number it is on
 * @param n
 * @return none
 * @pre Will take in the length of the array to find the max number, and then call count sort for all the digits
 * @post Calls count sort to sort the array
 */
void proj4 :: radixsort(int n)
{
    int m = getMax(n);

    for (int exp = 1; m/exp > 0; exp *= 10) {
        count_sort(n, exp);
    }
}
/**
 * @breif gets the biggest element in the array
 * @param n
 * @return temp, largest element
 * @pre takes the length of the array and gets the largest value
 * @post runs through the array to find the largest value
 */
int proj4 :: getMax(int n)
{
   int max = items[0];
    for (int i = 1; i < n; i++) {
        if (items[i] > max) {
            max = items[i];
        }
    }
    return max;
}
/**
 * @breif Will return the number of partitions
 * @return
 * @pre
 * @post Returns the number of partitions
 */
unsigned int proj4::getPartitions() {
    return partitions;
}
/**
 * @breif Will return how many times sort was called
 * @return countSorts
 * @pre
 * @post Returns the number of times count sort was called for radix sort
 */
unsigned int proj4::getCountSorts() {
    return countSorts;
}
/**
 * @breif Will return the amount of times count was used
 * @return  counts
 * @pre
 * @post Will return how many times a values was stored in the array count
 */
unsigned int proj4::getCounts() {
    return counts;
}
/**
 * @brief Will make temp arrays that store the left and right values, then it will merge it back together
 * @param l
 * @param m
 * @param r
 * @return none
 * @pre Takes in the left right and middle to give sizes to the arrays
 * @post Will create temp arrays for the left and right. It will copy the data into both and merge it back to the original, then move any remaining elements back into the original array.
 */
void proj4:: merge(int l, int m, int r)
{
    int i, j, k;
    int lf = m - l + 1;
    int rg =  r - m;

    int L[lf], R[rg];

    for (i = 0; i < lf; i++) {
        L[i] = items[l + i];
        left++;
    }
    for (j = 0; j < rg; j++) {
        R[j] = items[m + 1 + j];
        right++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < lf && j < rg)
    {
        if (L[i] <= R[j])
        {
            items[k] = L[i];
            i++;
        }
        else
        {
            items[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < lf)
    {
        items[k] = L[i];
        i++;
        k++;
    }

    while (j < rg)
    {
        items[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Will take the left and right to sort the array
 * @param l
 * @param r
 * @pre Will take in the left and right values to give to the sort
 * @post Will use the left and right, and keep using recursive calls to change the left and right values to give to the merge function
 */
void proj4:: mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
        recursions++;
    }
}

/**
 * @breif Will return the amount of times recursion was called
 * @return  recursions
 * @pre
 * @post Will return how many times it called itself to sort
 */
int proj4::getReursion() {
    return recursions;
}

/**
 * @breif Will return the amount of items in the left
 * @return  left
 * @pre
 * @post Will return how many times a values was stored in the left array
 */
int proj4::getLeft() {
    return left;
}

/**
 * @breif Will return the amount of items in the right
 * @return  right
 * @pre
 * @post Will return how many times a values was stored in the right array
 */
int proj4::getRight() {
    return right;
}
