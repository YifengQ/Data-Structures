//
// Created by yifengq on 5/12/18.
//

#ifndef PROJ8_5_GRAPH_H
#define PROJ8_5_GRAPH_H
#include <iostream>
#include <fstream>
#include <list>

class Graph
{
    int vertex;
    std::list<int> *adj;
public:
    Graph(int);
    void addEdge(int, int);
    bool isReachable(int, int);
};


#endif //PROJ8_5_GRAPH_H
