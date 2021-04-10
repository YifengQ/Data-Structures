#include <iostream>
#include "AdjMatrix.h"
using namespace std;

AdjMatrix::AdjMatrix(int var) {

    this -> test = var;
    adj = new int* [var];

    for (int i = 0; i < var; i++) {

        adj[i] = new int [var];

        for(int j = 0; j < var; j++)
            adj[i][j] = 0;
    }
}
     
void AdjMatrix::addEdge(int start, int end) {

    if( start > test || end > test || start < 0 || end < 0)
        cout<<"Invalid" << endl;

    else
        adj[start - 1][end - 1] = 1;

}
       
void AdjMatrix::print() {

    for(int i = 0;i < test;i++) {

        for(int j = 0; j < test; j++) {

            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
}

