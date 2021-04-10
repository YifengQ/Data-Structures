//
// Created by Yifeng Qin on 4/13/2018.
//

#include "NodeTree.h"
#include <iostream>
#include <fstream>
using namespace std;
int nodes = 1; /// global variable to count the amount of nodes

/**
 * @breif Will insert the values into the tree
 * @param subTreePtr , pointer to the root
 * @param newNode , pointer the a newNode that contains new value
 * @return A pointer to the root
 * @pre Will take in the root pointer and a new node containing the value of the new value
 * @post Will take the root pointer and the new node and set the new node to the right place
 */
Node *NodeTree::insertInorder(Node * subTreePtr, Node * newNode) {


    if(subTreePtr == nullptr){

        return newNode;
    }

    else if(subTreePtr -> getItem() > newNode -> getItem()){

        subTreePtr ->setLeftChildPtr(insertInorder(subTreePtr -> getLeftChildPtr(), newNode));
    }

    else{
        
        subTreePtr -> setRightChildPtr(insertInorder(subTreePtr -> getRightChildPtr(), newNode));
    }

    return subTreePtr;
}

/**
 * @breif Will remove a value from the tree
 * @param subTreePtr
 * @param target
 * @param success
 * @return a pointer the the node
 * @pre Will take in the root , the target and the bool value
 * @post It will recursively call itself to remove the target and return that pointer
 */
Node *NodeTree::removeValue(Node *subTreePtr, int target, bool &success) {
    Node * tempPtr;

    if(subTreePtr == nullptr){

        success =false;
        return nullptr;
    }

    else if(subTreePtr -> getItem() == target){

        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }

    else if(subTreePtr -> getItem() > target){

        tempPtr = removeValue(subTreePtr -> getLeftChildPtr(), target, success);
        subTreePtr  -> setLeftChildPtr(tempPtr);
        return subTreePtr;
    }

    else{

        tempPtr = removeValue(subTreePtr -> getRightChildPtr(), target, success);
        subTreePtr  -> setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

/**
 * @brief Will remove the node
 * @param nodePtr
 * @return nodePtr
 * @pre Will take in the pointer to delete the node
 * @post Will take the pointer and delete that node and then fill in the gap
 */
Node *NodeTree::removeNode(Node *nodePtr) {
    //Node * tempPtr;

    if(nodePtr ->getLeftChildPtr() == nullptr && nodePtr -> getRightChildPtr() == nullptr){
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }

    else if(nodePtr == nodePtr -> getLeftChildPtr()&& nodePtr == nodePtr -> getLeftChildPtr()){
         if(nodePtr -> getLeftChildPtr()){
             nodePtr = nodePtr -> getLeftChildPtr();
         }
         else{
             nodePtr = nodePtr -> getRightChildPtr();
             delete nodePtr;
             nodePtr = nullptr;
             return nodePtr;
         }
    }
    else{
        //tempPtr = removeLeftmostNode(nodePtr -> getRightChildPtr(), 0);
        //nodePtr -> setRightChildPtr(tempPtr);
        nodePtr -> setItem(0);
        return nodePtr;
    }

    return nodePtr;
}

/**
 * @breif Will remove the left most Node
 * @param subTreePtr
 * @param inorderSuccessor
 * @return will wall the remove node to remove that node
 * @pre Will take in the root pointer and the value to set it
 * @post Will get traverse to get to the left most node and then call removeNode to delete it
 */
Node *NodeTree::removeLeftmostNode(Node *subTreePtr, int &inorderSuccessor) {

    if(subTreePtr -> getLeftChildPtr()== nullptr){

        inorderSuccessor = subTreePtr -> getItem();
        return removeNode(subTreePtr);
    }

    else{

        return removeLeftmostNode(subTreePtr -> getLeftChildPtr(), inorderSuccessor);
    }
}

/**
 * @brief Will find the node with that value and return the address of it
 * @param treePtr
 * @param target
 * @return treePtr, will return the address to that target
 * @pre Will take in the root and the taret to find it
 * @post Will recursively find the target and return the address of the node
 */
Node *NodeTree::findNode(Node *treePtr, const int &target) const {

    if(treePtr == nullptr){

        return nullptr;
    }

    else if(treePtr -> getItem() == target){

        return treePtr;
    }

    else if(treePtr -> getItem() > target){

        return findNode(treePtr -> getLeftChildPtr(), target);
    }

    else{
        return findNode(treePtr -> getLeftChildPtr(), target);
    }

}

/**
 * @brief The Default constructor for the NodeTree
 */
NodeTree::NodeTree() {
    Node(0, nullptr, nullptr);
    setRoot(nullptr);

}

NodeTree::NodeTree(const int &rootItem) {

    Node(rootItem, nullptr, nullptr);
    setRoot(nullptr);

}

NodeTree::NodeTree(const NodeTree &tree) {
    Node(0, nullptr, nullptr);
    setRoot(nullptr);

}

/**
 * @breif Destructor and will call clear to delete the nodes
 */
NodeTree::~NodeTree() {

    clear(rootPtr);
}

/**
 * @brief Will test if the tree is empty
 * @param nodePtr
 * @return bool, if it is empty
 * @pre Will take in the root pointer
 * @post Will recursively check if the node points to null, or both children are null
 */
bool NodeTree::isEmpty(Node * nodePtr) const {

    if(nodePtr == nullptr){
        return true;
    }

    if(nodePtr -> getLeftChildPtr() == nullptr && nodePtr -> getRightChildPtr() == nullptr){

        return true;
    }

    if((nodePtr -> getLeftChildPtr()) && (nodePtr -> getRightChildPtr())){
        return (isEmpty(nodePtr -> getLeftChildPtr()) && isEmpty(nodePtr -> getRightChildPtr()));
    }

    return false;
}

/**
 * @brief Will get the height by calling the helper
 * @return The int value given by the helper
 * @pre
 * @post Will chall the helper function to return the number
 */
int NodeTree::getHeight() {

    return heightHelper(rootPtr);
}

/**
 * @brief Will return the number of nodes in the tree. It will run until both children get null
 * @param nodePtr
 * @return nodes
 * @pre Will take the rootptr
 * @post Will recursively call itself and increment the node counter to return the total value.
 */
int NodeTree::getNumberofNodes(Node * nodePtr) const {


    if(nodePtr == nullptr){
        return 0;
    }

    if(nodePtr -> getLeftChildPtr() != nullptr){
        nodes++;
        getNumberofNodes(nodePtr -> getLeftChildPtr());

    }

    if(nodePtr -> getRightChildPtr() != nullptr){
        nodes++;
        getNumberofNodes(nodePtr -> getRightChildPtr());

    }

    return nodes;
}

/**
 * @breif Will set the s
 * @param newData
 * @pre Will take in a in to give to the root ptr
 * @post Will call the constructor for a new node and give the root pointer that data
 */
void NodeTree::setRootData(const int &newData) {

    rootPtr = new Node(newData);
}

/**
 * @breif This is the function used to call the insertInorder function
 * @param newData
 * @return true
 * @pre It will take the new data member to give to the insert
 * @post Will create a new node with the data member in it. Then it will pass that new node and the root ptr to add to the tree
 */
bool NodeTree::add(const int &newData) {

    Node *newNodePtr = new Node(newData);
    rootPtr = insertInorder(rootPtr, newNodePtr);

    return true;
}

/**
 * @breif Will recursively call itself to clear all the children and delete the root
 * @param nodePtr
 * @pre Will take in the root
 * @post Will clear all the children and nodes recursively
 */
void NodeTree::clear(Node *nodePtr) {

    if (nodePtr != nullptr) {

        clear(nodePtr->getLeftChildPtr());
        clear(nodePtr->getRightChildPtr());

        delete (nodePtr);

        nodePtr = nullptr;
        setRoot(nodePtr);
    }
}

/**
 * @brief Will find the entry and return the value, if not it will return 0
 * @param anEntry
 * @return anEntry
 * @pre Will take in a int value to pass to findnode
 * @post Will call findnode to get the item, and if its the same it will return that value, if not it will return 0
 */
int NodeTree::getEntry(const int &anEntry) {

    if(findNode(rootPtr, anEntry) -> getItem() == anEntry){

        return anEntry;
    }
    else{
        return 0;
    }
}

/**
 * @breif Will check if the tree contains that value
 * @param anEntry
 * @return bool
 * @pre Will take in a int value to find
 * @post Will call findnode and if that node contains the entry it will return true, else false
 */
bool NodeTree::contains(const int &anEntry) const {

    return findNode(rootPtr, anEntry) -> getItem() == anEntry;
}

/**
 * @brief Will preorder transverse the tree and print the data
 * @param nodePtr
 * @pre Will get the rootptr to transverse the data
 * @post Will recursively call itself to move through the tree to print it in preorder
 */
void NodeTree::preorderTransverse(Node *nodePtr) const {

    ofstream preorder;
    preorder.open("preorder.txt", std::ofstream::out | std::ofstream::app);

    if(nodePtr == nullptr){
        return;
    }

    cout << nodePtr -> getItem() << " ";
    preorder << nodePtr -> getItem() << " ";
    preorderTransverse(nodePtr -> getLeftChildPtr());

    preorderTransverse(nodePtr -> getRightChildPtr());

    preorder.close();

}

/**
 * @brief Will inorder transverse the tree and print the data
 * @param nodePtr
 * @pre Will get the rootptr to transverse the data
 * @post Will recursively call itself to move through the tree to print it in inorder
 */
void NodeTree::inorderTransverse(Node *nodePtr) const {

    ofstream inorder;
    inorder.open("inorder.txt", std::ofstream::out | std::ofstream::app);

    if(nodePtr == nullptr){
        return;
    }

    inorderTransverse(nodePtr -> getLeftChildPtr());

    inorder << nodePtr -> getItem() << " ";
    cout << nodePtr -> getItem() << " ";


    inorderTransverse(nodePtr -> getRightChildPtr());

    inorder.close();
}

/**
 * @brief Will postorder transverse the tree and print the data
 * @param nodePtr
 * @pre Will get the rootptr to transverse the data
 * @post Will recursively call itself to move through the tree to print it in postorder
 */
void NodeTree::postorderTransverse(Node *nodePtr) const {

    ofstream postorder;
    postorder.open("postorder.txt", std::ofstream::out | std::ofstream::app);

    if(nodePtr == nullptr){
        return;
    }

    postorderTransverse(nodePtr -> getLeftChildPtr());

    postorderTransverse(nodePtr -> getRightChildPtr());

    cout << nodePtr -> getItem() << " ";
    postorder << nodePtr -> getItem() << " ";
    postorder.close();
}

/**
 * @breif The heightHelper because it can access the rootPtr itself
 * @param treePtr
 * @return the max height
 * @pre Will take the rootptr to pass to the children
 * @post Will recusievly call itself until if finds the nullptr, it will increment itself when it calls itself and returns the max number
 */
int NodeTree::heightHelper( Node *treePtr) {

    if(treePtr == nullptr){
        return 0;
    }

    int i = heightHelper(treePtr -> getLeftChildPtr());
    int j = heightHelper(treePtr -> getRightChildPtr());

    return max(i,j) + 1;

}
/**
 * @breif Will return the rootPtr
 * @return rootPtr
 */
Node *NodeTree::getRootPtr() {

    return rootPtr;
}

/**
 * @brief Will delete the node with the key
 * @param nodePtr
 * @param key
 * @return nodePtr
 * @pre Will take in the root and key to delete that node
 * @post Will recursively call  itself and set the children to the correct places after the deletion
 */
Node *NodeTree::deleteNode(Node *nodePtr, int key) {

    if (nodePtr == nullptr) return nodePtr;

    if (key < nodePtr->getItem()) {
        nodePtr->setLeftChildPtr(deleteNode(nodePtr->getLeftChildPtr(), key));
    }
    else if (key > nodePtr->getItem()){


        nodePtr->setRightChildPtr(deleteNode(nodePtr->getRightChildPtr(), key));
    }
    else
    {
        if(nodePtr -> isLeaf()){
            return nullptr;
        }

        if (nodePtr->getLeftChildPtr() == nullptr)
        {
            return nodePtr->getRightChildPtr();;
        }
        else if (nodePtr->getRightChildPtr() == nullptr)
        {
            return nodePtr->getLeftChildPtr();
        }

        Node* temp = minValue(nodePtr->getRightChildPtr());

        nodePtr->setItem(temp->getItem());

        nodePtr->setRightChildPtr(deleteNode(nodePtr->getRightChildPtr(), nodePtr->getItem()));
    }
    return nodePtr;
}

/**
 * @breif Will find the min value in the tree
 * @param nodePtr
 * @return current, pointer to the address of the min value
 * @pre Will take in the root to find the mon value
 * @post Will run down the left pointers until it finds null and return the address where it is min value
 */
Node *NodeTree::minValue(Node *nodePtr) {
    Node *current = nodePtr;

    while (current -> getLeftChildPtr() != nullptr){
        current = current -> getLeftChildPtr();
    }

    return current;
}

/**
 * @breif Will reset the node value for getNumberofNodes
 * @post Will reset the global variable nodes to 1
 */
void NodeTree::resetCount() {

    nodes = 1;
}

/**
 * @breif Will rest the rootPtr to a address
 * @param root
 * @pre Will take in a node pointer
 * @post Will set the rootPtr to the root address
 */
void NodeTree::setRoot(Node *root) {

    rootPtr = root;
}

/**
 * @brief Will delete the nodes that are equal to the nodes in BTS2
 * @param nodePtr
 * @param key
 * @pre Will take the root and the key
 * @post Will check if the key and the item in that node are equal, if equal it will call delete node to delete that node
 */
void NodeTree::inorderDelete(Node *nodePtr, int key) {

    if(nodePtr == nullptr){
        return;
    }

    inorderDelete(nodePtr -> getLeftChildPtr(), key);

    if(nodePtr -> getItem() == key)
        deleteNode(nodePtr, key);

    inorderDelete(nodePtr -> getRightChildPtr(), key);

    if(nodePtr -> getItem() == key)
        deleteNode(nodePtr, key);
}



