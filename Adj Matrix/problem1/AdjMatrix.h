
#ifndef PROBLEM1_ADJMATRIX
#define PROBLEM1_ADJMATRIX

class AdjMatrix {

public:

AdjMatrix(int);

void addEdge(int, int);

void print();

private:

    int test;
    int **adj;

};

#endif //PROBLEM1_ADJMATRIX