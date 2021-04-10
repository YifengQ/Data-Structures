#include <iostream>
#include <fstream>
#include <ctime>
#include "Node.h"
#include "NodeTree.h"

#define BTS1 100000 ///The amount of items in BTS1
#define BTS2 10 ///The amount of items in BTS2
#define RANGE 200 ///Range of the values in the array

using namespace std;

int generate(int range);
void setValues(int [], int []);

int main() {

    int arr1[BTS1];
    int arr2[BTS2];

    setValues(arr1, arr2);

    NodeTree test;


    ofstream preorder, inorder, postorder;

    preorder.clear();
    inorder.clear();
    postorder.clear();

    preorder.open("preorder.txt");
    inorder.open("inorder.txt");
    postorder.open("postorder.txt");

    test.setRootData(arr1[0]);

    for (int i = 1; i < BTS1; ++i) {
        //cout << arr1[i] << endl;
        test.add(arr1[i]);
    }

    cout << "BTS1 (Before) Height: " << test.getHeight() << endl;
    cout << "BTS1 (Before) #nodes: " << test.getNumberofNodes(test.getRootPtr()) << endl;
    inorder << "In Order (BTS1)" << endl;
    cout << "In Order (BTS1 Before)" << endl;
    test.inorderTransverse(test.getRootPtr());
    cout << endl;

    NodeTree test2;
    test2.setRootData(arr2[0]);
    for (int j = 1; j < BTS2; ++j) {
        test2.add(arr2[j]);
    }

    cout << endl;
    postorder << "Post Order (BTS1)" << endl;
    cout << "Post Order (BTS1)" << endl;
    test2.postorderTransverse(test2.getRootPtr());
    cout << endl;
    cout << endl;

    inorder << "In Order (BTS2)" << endl;
    cout << "In Order (BTS2)" << endl;
    test2.inorderTransverse(test2.getRootPtr());
    cout << endl;
    cout << endl;

    preorder << "Pre Order (BTS2)" << endl;
    cout << "Pre Order (BTS2)" << endl;
    test2.preorderTransverse(test2.getRootPtr());
    cout << endl;
    cout << endl;

    for (int k = 0; k < BTS2; ++k) {

            //cout << boolalpha << test.contains(arr2[k]);
            test.inorderDelete(test.getRootPtr(), arr2[k]);

    }
    test.resetCount();
    cout << "BTS1 (After) Height: " << test.getHeight() << endl;
    cout << "BTS1 (After) #nodes: " << test.getNumberofNodes(test.getRootPtr()) << endl;
    cout << "In Order (BTS1 After)" << endl;
    test.inorderTransverse(test.getRootPtr());
    cout << endl;
    cout << endl;


    cout << "BTS1 is Empty ( " << boolalpha << test.isEmpty(test.getRootPtr()) << " )" << endl;
    cout << "BTS2 is Empty ( " << boolalpha << test2.isEmpty(test2.getRootPtr()) << " )" << endl;
    test.clear(test.getRootPtr());
    test2.clear(test2.getRootPtr());
    cout << "BTS1 is Empty ( " << boolalpha << test.isEmpty(test.getRootPtr()) << " )" << endl;
    cout << "BTS2 is Empty ( " << boolalpha << test2.isEmpty(test2.getRootPtr()) << " )" << endl;


    preorder.close();
    inorder.close();
    postorder.close();
    return 0;
}

int generate(int range){

    int num = 0;
    num = rand() % range + 1;

    return num;
}

/**
 * @breif Will generate random numbers for BTS1 and BTS2. To make sure that some numbers
 * overlap, all the numbers in BTS2 are also in BTS1. So there should always be 10 overlaps.
 * @pre When it is called it will save the numbers in the file
 * @post It will open the log files, and save them in the designated files.o
 */
void setValues(int arr1[], int arr2[]){

    srand(time(NULL));
    ofstream tree1, tree2;
    tree1.open("BTS1.txt");
    tree2.open("BTS2.txt");

    for (int k = 0; k < BTS2; ++k) {

        int a =  generate(RANGE);
        tree1 << a << endl;
        tree2 << a << endl;
        arr1[k] = a;
        arr2[k] = a;
    }

    for (int i = BTS2 - 1; i < BTS1; ++i) {

        int k = generate(RANGE);
        tree1 << k << endl;
        arr1[i] = k;
    }

    tree1.close();
    tree2.close();
}