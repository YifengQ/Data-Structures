#include <iostream>
#include "graph.h"
using namespace std;

void Graph::input() {

    int w = 1; //CHANGE THIS FOR WEIGHT

    vertices = 3;
    edges = 3;

    cout << "For 3 vertices and 3 edges: " << endl;

    for (int i = 0; i < vertices; ++i) {

        for (int j = 0; j < vertices; ++j) {

            Graph[i][j] = 0;
        }


        for (int k = 0; k < edges; ++k) {

            Graph[i][k] = Graph[k][i] = w;
        }
    }
}

void Graph::print()
{
    cout << endl;
    cout << "Matrix:" << endl;

    for(int i = 0; i < vertices; ++i) {

        for(int j = 0; j < vertices; ++j) {

            cout << Graph[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}
