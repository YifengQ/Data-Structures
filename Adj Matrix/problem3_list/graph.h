#ifndef PROJ8_3
#define PROJ8_3

struct AdjListNode {

    int dest;
    struct AdjListNode* next;
};

struct AdjList {

    struct AdjListNode *head;
};

class Graph {

    private:
        int vertex;
        struct AdjList* array;
        
    public:

        Graph(int );
      

        AdjListNode* list(int);
       

        void addEdge(int, int);
       

        void print();
};

#endif