//
// Created by Yifeng Qin on 4/13/2018.
//

#ifndef PROJ6_NODE_H
#define PROJ6_NODE_H


class Node {

public:

    Node();
    Node(const int &anitem);
    Node(const int &item, Node *leftPtr, Node *rightPtr);
    Node *setItem(const int &anitem);
    int getItem();

    void setCount();
    int getCount();

    bool isLeaf() const;
    Node *getLeftChildPtr();
    Node *getRightChildPtr();

    void setLeftChildPtr(Node *leftPtr);
    void setRightChildPtr(Node *rightPtr);

private:
    int item;
    Node *leftChildPtr;
    Node *rightChildPtr;
    int count;

};


#endif //PROJ6_NODE_H
