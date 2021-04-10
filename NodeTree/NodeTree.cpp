//
// Created by yifengq on 4/30/18.
//

#include "NodeTree.h"
#include <fstream>

int nodes = 1;  /// holds how many nodes there are
long long int sum = 0;  ///holds the running total for the sum

/**
 * @brief Inorder helper that recursively calls itself to print out the tree in order
 * @pre Will take in the root to recursively call itself and get the nodes
 * @post Will recursively call itself and cout in order for it to print in order. It will also print it out to a log file.
 */
void inorderHelper(Node *root)
{
    ofstream log;
    log.open("inorder.txt", ofstream::out | ofstream::app);

    if (root == nullptr)
        return;

    inorderHelper(root->leftChildPtr);
    log << root->data << "  ";
    inorderHelper(root->rightChildPtr);
    log.close();
}

/**
 *
 * @param root
 * @param pt
 * @return
 */
Node* BSTInsert(Node* root, Node *pt)
{

    if (root == nullptr)
        return pt;

    if (pt->data < root->data)
    {
        root->leftChildPtr  = BSTInsert(root->leftChildPtr, pt);
        root->leftChildPtr->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->rightChildPtr = BSTInsert(root->rightChildPtr, pt);
        root->rightChildPtr->parent = root;
    }

    return root;
}

void NodeTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_rightChildPtr = pt->rightChildPtr;

    pt->rightChildPtr = pt_rightChildPtr->leftChildPtr;

    if (pt->rightChildPtr != nullptr)
        pt->rightChildPtr->parent = pt;

    pt_rightChildPtr->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_rightChildPtr;

    else if (pt == pt->parent->leftChildPtr)
        pt->parent->leftChildPtr = pt_rightChildPtr;

    else
        pt->parent->rightChildPtr = pt_rightChildPtr;

    pt_rightChildPtr->leftChildPtr = pt;
    pt->parent = pt_rightChildPtr;
}

void NodeTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_leftChildPtr = pt->leftChildPtr;

    pt->leftChildPtr = pt_leftChildPtr->rightChildPtr;

    if (pt->leftChildPtr != nullptr)
        pt->leftChildPtr->parent = pt;

    pt_leftChildPtr->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_leftChildPtr;

    else if (pt == pt->parent->leftChildPtr)
        pt->parent->leftChildPtr = pt_leftChildPtr;

    else
        pt->parent->rightChildPtr = pt_leftChildPtr;

    pt_leftChildPtr->rightChildPtr = pt;
    pt->parent = pt_leftChildPtr;
}

void NodeTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parentPtr = nullptr;
    Node *grandparentPtr = nullptr;

    if (pt -> parent == nullptr)
        return;

    while ((pt != root) && (pt->color != BLACK) &&
            (pt->parent->color == RED))
    {

        parentPtr = pt->parent;
        grandparentPtr = pt->parent->parent;

        if(grandparentPtr == nullptr)
            return;

        if (parentPtr == grandparentPtr->leftChildPtr)
        {

            Node *uncle_pt = grandparentPtr->rightChildPtr;
            
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                grandparentPtr->color = RED;
                parentPtr->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparentPtr;
            }

            else
            {
                
                if (pt == parentPtr->rightChildPtr)
                {
                    rotateLeft(root, parentPtr);
                    pt = parentPtr;
                    parentPtr = pt->parent;
                }

                rotateRight(root, grandparentPtr);
                swap(parentPtr->color, grandparentPtr->color);
                pt = parentPtr;
            }
        }
            
        else
        {
            Node *uncle_pt = grandparentPtr->leftChildPtr;
            
            if ((uncle_pt != nullptr) && (uncle_pt->color == RED))
            {
                grandparentPtr->color = RED;
                parentPtr->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparentPtr;
            }
            else
            {
              
                if (pt == parentPtr->leftChildPtr)
                {
                    rotateRight(root, parentPtr);
                    pt = parentPtr;
                    parentPtr = pt->parent;
                }
                
                rotateLeft(root, grandparentPtr);
                swap(parentPtr->color, grandparentPtr->color);
                pt = parentPtr;
            }
        }
    }

    root->color = BLACK;
}

void NodeTree::insert(const int &data)
{
    Node *pt = new Node(data);

    root = BSTInsert(root, pt);
    
    fixViolation(root, pt);
}

void NodeTree::inorder() {

    inorderHelper(root);
}

long long int NodeTree::addHelper(Node *root) {

    if (root == nullptr)
        return sum;

    addHelper(root->leftChildPtr);
    sum += root->data;
    addHelper(root->rightChildPtr);

}

long long int NodeTree::add() {

    return addHelper(root);
}

void NodeTree::resetAdd() {

    sum = 0;
}

/**
 * @brief Will get the height by calling the helper
 * @return The int value given by the helper
 * @pre
 * @post Will chall the helper function to return the number
 */
int NodeTree::getHeight() {

    return heightHelper(root);
}

/**
 * @breif The heightHelper because it can access the rootPtr itself
 * @param treePtr
 * @return the max height
 * @pre Will take the root to pass to the children
 * @post Will recusievly call itself until if finds the nullptr, it will increment itself when it calls itself and returns the max number
 */
int NodeTree::heightHelper( Node *treePtr) {

    if(treePtr == nullptr){
        return 0;
    }

    int i = heightHelper(treePtr -> leftChildPtr);
    int j = heightHelper(treePtr -> rightChildPtr);

    return max(i,j) + 1;

}

/**
 * @breif Destructor and will call clear to delete the nodes
 */
NodeTree::~NodeTree() {

    clear();
}

/**
 * @breif Will recursively call itself to clear all the children and delete the root
 * @param nodePtr
 * @pre Will take in the root
 * @post Will clear all the children and nodes recursively
 */
void NodeTree::clearHelper(Node *nodePtr) {

    if (nodePtr != nullptr) {

        clearHelper(nodePtr->leftChildPtr);
        clearHelper(nodePtr->rightChildPtr);

        delete (nodePtr);
    }
}

/**
 * @brief Will test if the tree is empty
 * @param nodePtr
 * @return bool, if it is empty
 * @pre Will take in the root pointer
 * @post Will recursively check if the node points to null, or both children are null
 */
bool NodeTree::isEmptyHelper(Node * nodePtr) const {

    if(nodePtr == nullptr){
        return true;
    }

    if(nodePtr -> leftChildPtr == nullptr && nodePtr -> rightChildPtr == nullptr){

        return true;
    }

    if((nodePtr -> leftChildPtr) && (nodePtr -> rightChildPtr)){
        return (isEmptyHelper(nodePtr -> leftChildPtr) && isEmptyHelper(nodePtr -> rightChildPtr));
    }

    return false;
}

/**
 * @brief Will return the number of nodes in the tree. It will run until both children get null
 * @param nodePtr
 * @return nodes
 * @pre Will take the root
 * @post Will recursively call itself and increment the node counter to return the total value.
 */
int NodeTree::getNumberofNodesHelper(Node * nodePtr) const {


    if(nodePtr == nullptr){
        return 0;
    }

    if(nodePtr -> leftChildPtr != nullptr){
        nodes++;
        getNumberofNodesHelper(nodePtr -> leftChildPtr);

    }

    if(nodePtr -> rightChildPtr != nullptr){
        nodes++;
        getNumberofNodesHelper(nodePtr -> rightChildPtr);

    }

    return nodes;
}

void NodeTree::resetNodes() {

    nodes = 0;
}

void NodeTree::clear() {

    clearHelper(root);

    root = nullptr;
}

int NodeTree::getNumberofNodes() {

    return getNumberofNodesHelper(root);
}

bool NodeTree::isEmpty() {

    return isEmptyHelper(root);
}
