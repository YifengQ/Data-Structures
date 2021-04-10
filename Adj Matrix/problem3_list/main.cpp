#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    cout << "Undirected Adjacency List:" << endl;

    Graph a(5);

    for (int i = 0; i < 5; ++i) {
        a.addEdge(i, i);
        a.addEdge(i, i + 1);
    }
    
    a.print();
 
    return 0;
}
