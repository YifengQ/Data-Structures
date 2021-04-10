//
// Created by Yifeng Qin on 4/13/2018.
//

#include "Node.h"
#include <iostream>


/**
 * @brief Default Constructor for Node
 */
Node::Node() {

    this -> setItem(0);
    this -> leftChildPtr = nullptr;
    this -> rightChildPtr = nullptr;
}

/**
 * @breif Constructor for the item only
 * @param anitem
 * @pre Will take in an int to give to the item
 * @post Will give the set the item to the value and set the childs to null
 */
Node::Node(const int &anitem) {

    this -> setItem(anitem);
    this -> leftChildPtr = nullptr;
    this -> rightChildPtr = nullptr;
}

/**
 * @brief Constructor for item, and the child objects
 * @param anitem
 * @param leftPtr
 * @param rightPtr
 * @pre Will take the item and child pointer values
 */
Node::Node(const int &anitem, Node *leftPtr, Node *rightPtr) {

    this -> setItem(anitem);
    this -> leftChildPtr = leftPtr;
    this -> rightChildPtr = rightPtr;
}

/**
 * @brief Will set the value for the item
 * @param anitem
 * @pre Will take in the item value to set it
 * @post Will set the item to the node item
 */
Node *Node::setItem(const int &anitem) {

    this -> item = anitem;
}

/**
 * @brief Will return the item value at that node
 * @return item
 * @pre Will get called at that node
 * @post Will return the value at that node
 */
int Node::getItem()  {

    return this -> item;
}

/**
 * @brief Will return the left child pointer at that node
 * @return leftChildPtr
 * @pre Will get called at that node
 * @post Will return the left child pointer at that node
 */
Node *Node::getLeftChildPtr()  {

    return this -> leftChildPtr;
}

/**
 * @brief Will return the right child pointer at that node
 * @return rightChildPtr
 * @pre Will get called at that node
 * @post Will return the right child pointer at that node
 */
Node *Node::getRightChildPtr()  {

    return this -> rightChildPtr;
}

/**
 * @brief Will set the left child pointer for the item
 * @param leftPtr
 * @pre Will take in the pointer value to set it
 * @post Will set the left child pointer to the node item
 */
void Node::setLeftChildPtr(Node *leftPtr) {

    this -> leftChildPtr = leftPtr;
}

/**
 * @brief Will set the right child pointer for the node
 * @param rightPtr
 * @pre Will take in the pointer value to set it
 * @post Will set the right child pointer to the node
 */
void Node::setRightChildPtr(Node *rightPtr) {

    this -> rightChildPtr = rightPtr;
}

/**
 * @brief Whill cheak if that node has leaft values
 * @return bool
 * @pre Will check it that node has leafs
 * @post Will return a bool value to check the leafs
 */
bool Node::isLeaf() const {

    return this -> rightChildPtr == nullptr && this -> leftChildPtr == nullptr;
}

