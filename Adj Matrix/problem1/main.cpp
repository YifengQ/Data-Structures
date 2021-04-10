#include <iostream>
#include "AdjMatrix.h"

#define nodes 3

using namespace std;

int main() {

    cout << "Adj Matrix" << endl;

    int max = 0;

    AdjMatrix test(nodes);

    max = nodes * (nodes - 1); // max number of nodes

    for (int i = 1; i < max; i++) {

        test.addEdge(i, i);
    }
    test.print();

    return 0;
}

