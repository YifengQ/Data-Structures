#include <iostream>
#include "AdjList.h"
#define var 5

using namespace std;

int main()
{
    cout << "Adj List" << endl;

    Graph a(var);

    for (int i = 0; i < var; ++i) {
        
        a.addEdge(i, i);
        a.addEdge(i, i + 1);
    }
    
    a.print();
 
    return 0;
}
