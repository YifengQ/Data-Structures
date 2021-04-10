#ifndef PROBLEM2_ADJLIST
#define PROBLEM2_ADJLIST

struct AdjList {

    struct AdjListNext *head;
};


struct AdjListNext {
    
    int dest;
    struct AdjListNext* next;
};

class Graph {
    
public:
    
    Graph(int);
    
    AdjListNext* newAdjListNode(int);
    
    void addEdge(int, int);
    
    void print();
    
private:

    int vertex;
    struct AdjList* test;

};

#endif //PROBLEM2_ADJLIST