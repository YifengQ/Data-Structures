#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(int var) {
  
  this -> vertex = var;
  array = new AdjList [var];
  
  for (int i = 0; i < var; ++i) {
    
    array[i].head = nullptr;
  }
}
 
AdjListNode* Graph::list(int dest) {
  
  AdjListNode* newNode = new AdjListNode;
  newNode -> dest = dest;
  newNode -> next = nullptr;
  return newNode;
}
       
void Graph::addEdge(int ori, int dest) {
  
  AdjListNode* newNode = list(dest);
  newNode -> next = array[ori].head;
  array[ori].head = newNode;
  newNode = list(ori);
  newNode -> next = array[dest].head;
  array[dest].head = newNode;
}
     
void Graph::print() {
  
  for (int i = 0; i < vertex; ++i) {
    
    AdjListNode* list = array[i].head;
    cout << "List # " << i << endl << "Head ";
    
    while (list) {
      
       cout << "-> " << list -> dest;
       list = list -> next;
    }
    
    cout << endl;
   }
}
