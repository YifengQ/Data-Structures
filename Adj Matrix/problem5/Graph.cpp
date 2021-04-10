//
// Created by yifengq on 5/12/18.
//

#include "Graph.h"

using namespace std;

Graph::Graph(int i) {

    this->vertex = i;
    adj = new list<int>[i];
}

void Graph::addEdge(int i, int j) {

    adj[i].push_back(j);
}

bool Graph::isReachable(int x, int y) {

    if (x == y)
        return true;

    bool *check = new bool[vertex];

    for (int i = 0; i < vertex; i++)
        check[i] = false;

    list<int> queue;

    check[x] = true;
    queue.push_back(x);
    
    list<int>::iterator i;

    while (!queue.empty()) {

        x = queue.front();
        queue.pop_front();
        
        for (i = adj[x].begin(); i != adj[x].end(); ++i) {
            
            if (*i == y)
                return true;
            
            if (!check[*i]) {

                check[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}