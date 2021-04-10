#include <iostream>
#include "graph.h"
using namespace std;

int main(){

    Graph a;

    cout << "Undirected Weighted/Unweighted Adjacency Matrix:" << endl;

    a.input();
    a.print();

    return 0;
}