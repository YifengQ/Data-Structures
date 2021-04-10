//
// Created by yifengq on 4/30/18.
//

#ifndef CS302_PROJ7_NODETREE_H
#define CS302_PROJ7_NODETREE_H

#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *leftChildPtr, *rightChildPtr, *parent;

    // Constructor
    Node(int data)
    {
        this->data = data;
        leftChildPtr = rightChildPtr = parent = nullptr;
    }
};

class NodeTree {

private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
// Constructor
    NodeTree() { root = nullptr; }
    void insert(const int &n);
    void inorder();

    void resetNodes();

    int getNumberofNodesHelper(Node *nodePtr) const;

    int getNumberofNodes();

    bool isEmptyHelper(Node *nodePtr) const;

    bool isEmpty();

    int heightHelper(Node *treePtr);

    int getHeight();

    void resetAdd();

    long long int addHelper(Node *root);

    long long int add();

    ~NodeTree();

    void clearHelper(Node *);

    void clear();
};


#endif //CS302_PROJ7_NODETREE_H
