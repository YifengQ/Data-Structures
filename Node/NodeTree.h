//
// Created by Yifeng Qin on 4/13/2018.
//

#ifndef PROJ6_NODETREE_H
#define PROJ6_NODETREE_H

#include "Node.h"

class NodeTree : public Node{

private:
    Node  *rootPtr;

protected:

    Node *removeValue(Node *subTreePtr, int target, bool &success);

    Node *removeNode(Node *nodePtr);

    Node *removeLeftmostNode(Node *subTreePtr, int &inorderSuccessor);

    Node *findNode(Node *treePtr, const int &target) const;


public:
    NodeTree();

    NodeTree(const int &rootItem);

    NodeTree(const NodeTree &tree);

    Node *insertInorder(Node *subTreePtr, Node * newNode);

    Node *getRootPtr();

    virtual ~NodeTree();

    bool isEmpty(Node * nodePtr) const;

    int getHeight();

    int heightHelper(Node *treePtr);

    int getNumberofNodes(Node * nodePtr) const;

    int getRootData();

    bool remove(const int &data);

    void setRootData(const int &newData);

    void setRoot(Node * root);

    bool add(const int &newData);

    void clear(Node *nodePtr);

    int getEntry(const int &anEntry);

    bool contains(const int &anEntry) const;

    void preorderTransverse(Node *nodePtr) const;

    void inorderTransverse(Node *nodePtr) const;

    void postorderTransverse(Node *nodePtr) const;

    Node *deleteNode(Node *nodePtr, int key);

    Node *minValue(Node * nodePtr);

    void resetCount();

    void inorderDelete(Node *nodePtr, int);
};


#endif //PROJ6_NODETREE_H
