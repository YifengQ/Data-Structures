#include <iostream>
#include "AdjList.h"
using namespace std;

Graph::Graph(int var) {

    this -> vertex = var;
    test = new AdjList [var];

    for (int i = 0; i < var; ++i)
        test[i].head = nullptr;
}

AdjListNext* Graph::newAdjListNode(int dest) {

    AdjListNext* newNode = new AdjListNext;
    newNode -> next = nullptr;
    newNode -> dest = dest;
    

    return newNode;
}

void Graph::addEdge(int ori, int dest) {

    AdjListNext* newNode = newAdjListNode(dest);

    newNode -> next = test[ori].head;
    test[ori].head = newNode;
    newNode = newAdjListNode(ori);
    newNode -> next = test[dest].head;
    test[dest].head = newNode;
}

void Graph::print() {

    int i;
    for (i = 0; i < vertex; ++i) {

        AdjListNext* list = test[i].head;
        cout << endl;
        cout<<"List #: "<<i << endl << "Head ";

        while (list) {

            cout<<"-> "<<list -> dest;
            list = list -> next;
        }

        cout<<endl;
    }
}
