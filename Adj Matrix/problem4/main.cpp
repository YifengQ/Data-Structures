#include<iostream>
#include "Graph.h"

using namespace std;

void mst();

struct subset {

    int parent;
    int rank;
};

struct edge {
    
    int ori, dest, weight;
};

struct Graphs {
    
    int vert, edgez;
    
    struct edge* edge;
};

struct Graphs* createGraph(int vert, int edgez);

int find(struct subset sub[], int i);

void toge(struct subset sub[], int i, int j);

int compare(const void* a, const void* b);

void MST(struct Graphs* graph);


int main() {
    
    Graph a(5);
    a.addEdge(0, 1);
    a.addEdge(1, 2);
    a.addEdge(2, 3);
    a.addEdge(3, 4);
    a.addEdge(1, 2);
    a.addEdge(3, 4);
 
    cout << "BFS " << endl;
    a.BFS(2);
 
    cout << endl << endl;
   
    cout << "DFS " << endl;
    a.DFS(2);

    cout << endl << endl;

    cout << "Topological Sort" << endl;
    a.topologicalSort();

    cout << endl << endl;

    if(a.isCyclic())
        cout << "Graph contains cycle" << endl << endl;
    else
        cout << "Graph doesn't contain cycle" << endl << endl;


    if(a.isConnected()) 
        cout << "Connected" << endl;
    
    else
        cout << "Not Connected" << endl << endl;
    

    mst();

    return 0;
}

void mst(){

    int vert = 4;
    int edgez = 5;
    struct Graphs* graph = createGraph(vert, edgez);

    for (int i = 0; i < 5; ++i) {

        graph->edge[i].ori = i;
        graph->edge[i].dest = i + 1;
        graph->edge[i].weight =  i + 2;

    }

    MST(graph);
}

struct Graphs* createGraph(int vert, int edgez) {

    struct Graphs* graph = (struct Graphs*) malloc(sizeof(struct Graphs));
    graph->vert = vert;
    graph->edgez = edgez;

    graph->edge = (struct edge*) malloc(graph->edgez * sizeof(struct edge));

    return graph;
}

int find(struct subset sub[], int i) {

    if (sub[i].parent != i)
        sub[i].parent = find(sub, sub[i].parent);

    return sub[i].parent;
}

void toge(struct subset sub[], int i, int j) {

    int test1 = find(sub, i);
    int test2 = find(sub, j);

    if (sub[test1].rank < sub[test2].rank)
        sub[test1].parent = test2;

    else if (sub[test1].rank > sub[test2].rank)
        sub[test2].parent = test1;

    else {

        sub[test2].parent = test1;
        sub[test1].rank++;
    }
}

int compare(const void* a, const void* b) {

    struct edge* test1 = (struct edge*) a;
    struct edge* test2 = (struct edge*) b;
    return test1->weight > test2->weight;
}

void MST(struct Graphs* graph) {

    int vert = graph->vert;
    struct edge result[vert];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->edgez, sizeof(graph->edge[0]), compare);

    struct subset *sub = (struct subset*) malloc(vert * sizeof(struct subset));

    for (int v = 0; v < vert; ++v) {

        sub[v].parent = v;
        sub[v].rank = 0;
    }

    while (e < vert - 1) {

        struct edge next = graph->edge[i++];

        int i = find(sub, next.ori);
        int j = find(sub, next.dest);

        if (i != j) {

            result[e++] = next;
            toge(sub, i, j);
        }
    }

    cout<<"MST"<< endl;
    
    for (i = 0; i < e; ++i) {

        cout << result[i].ori << " - " << result[i].dest << " = " << result[i].weight << endl;
    }
}