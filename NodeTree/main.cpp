#include <iostream>
#include "ctime"
#include <fstream>
#include "NodeTree.h"

#define VALUES 1000
#define RANGE 10000

using namespace std;

int generate(int);

int main(){

    NodeTree tree;
    ofstream log;

    log.open("inorder.txt");

    int arr1[VALUES];
    srand(time(NULL));

    for (int &i : arr1) {

        i = generate(RANGE);
    }

    for (int j = 0; j <  VALUES; ++j) {

        tree.insert(j);
    }


    cout << "#Nodes: " <<  tree.getNumberofNodes() << endl;
    tree.resetNodes();

    tree.inorder();

    cout << endl;
    cout << "Sum: " << tree.add() << endl;
    tree.resetAdd();
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Is Empty (before): " << boolalpha << tree.isEmpty() << endl;
    tree.clear();
    cout << "Is Empty (after): " << boolalpha << tree.isEmpty() << endl;
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