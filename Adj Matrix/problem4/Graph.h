//
// Created by Yifen on 5/13/2018.
//

#ifndef PROBLEM4_GRAPH_H
#define PROBLEM4_GRAPH_H

#include<iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{

private:

    int vertex;

    list<int> *adj;

public:
    Graph(int);

    void BFS(int s);

    void DFS(int v);

    void DFSHelper(int v, bool visited[]);

    void addEdge(int v, int w);

    bool isCyclic();

    bool isCyclicHelper(int v, bool visited[], bool *rs);

    void topologicalSort();

    void topologicalSortHelper(int v, bool visited[], stack<int> &Stack);

    bool isConnected();

    Graph getTranspose();

    ~Graph();

};



#endif //PROBLEM4_GRAPH_H
