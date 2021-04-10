//
// Created by Yifen on 5/13/2018.
//

#include "Graph.h"

using namespace std;

Graph::Graph(int i) {

    this -> vertex = i;
    adj = new list<int>[i];
}

void Graph::BFS(int s) {
    
    bool *check = new bool[vertex];
    for(int i = 0; i < vertex; i++)
        check[i] = false;
    
    list<int> queue;

    check[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()) {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i) {

            if (!check[*i]) {

                check[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSHelper(int var, bool check[]) {

    check[var] = true;
    cout << var << " ";

    list<int>::iterator i;
    for (i = adj[var].begin(); i != adj[var].end(); ++i)
        
        if (!check[*i])
            DFSHelper(*i, check);
}

void Graph::DFS(int var) {

    bool *check = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        check[i] = false;

    DFSHelper(var, check);
}


void Graph::addEdge(int var, int i) {

    adj[var].push_back(i);
}


void Graph::topologicalSortHelper(int var, bool check[], stack<int> &test) {
    
    check[var] = true;
    
    list<int>::iterator i;
    for (i = adj[var].begin(); i != adj[var].end(); ++i) {

        if (!check[*i])
            topologicalSortHelper(*i, check, test);
    }
    
    test.push(var);
}

void Graph::topologicalSort() {

    stack<int> test;
    
    bool *check = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        check[i] = false;
    
    for (int i = 0; i < vertex; i++)
        if (!check[i])
            topologicalSortHelper(i, check, test);
    
    while (!test.empty()) {
        cout << test.top() << " ";
        test.pop();
    }
}

bool Graph::isCyclicHelper(int var, bool check[], bool *look) {

    if(!check[var]) {
        
        check[var] = true;
        look[var] = true;
        
        list<int>::iterator i;
        for(i = adj[var].begin(); i != adj[var].end(); ++i) {

            if ( !check[*i] && isCyclicHelper(*i, check, look) )
                return true;
            else if (look[*i])
                return true;
        }

    }
    
    look[var] = false;
    return false;
}

bool Graph::isCyclic() {
    
    bool *check = new bool[vertex];
    bool *look = new bool[vertex];
    for(int i = 0; i < vertex; i++) {

        check[i] = false;
        look[i] = false;
    }
    
    for(int i = 0; i < vertex; i++)
        if (isCyclicHelper(i, check, look))
            return true;

    return false;
}

Graph Graph::getTranspose()
{
    Graph b(vertex);
    for (int var = 0; var < vertex; var++) {
        
        list<int>::iterator i;
        for(i = adj[var].begin(); i != adj[var].end(); ++i)
            b.adj[*i].push_back(var);
    }
    return b;
}


bool Graph::isConnected() {
    
    bool check[vertex];

    for (int i = 0; i < vertex; i++)

        check[i] = false;
    
    DFSHelper(0, check);
    
    for (int i = 0; i < vertex; i++)

        if (!check[i])
            return false;
    
    Graph a = getTranspose();
    
    for(int i = 0; i < vertex; i++)

        check[i] = false;
    
    a.DFSHelper(0, check);

    for (int i = 0; i < vertex; i++)

        if (!check[i])
            return false;

    return true;
}

Graph::~Graph() { 
    
    delete [] adj; 
}