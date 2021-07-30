/**
 * Node.h
 *
 * Implementations for the Node class, which stores a reference to the
 * next Node and a value. These compose a Queue ADT.
 *
 * Joshua Scheck
 * 2020-11-20
 */
#include "Node.h"
#include "Point.h"

/**
 * Default constructor for Node class, which initializes an empty
 * Node
 */
template<class T>
Node<T>::Node() : next(nullptr) {}

/**
 * Constructor for Node class, which initializes a Node with the
 * specified value, but has no next Node reference
 * 
 * @param   anEntry  value to be stored in this Node
 */
template<class T>
Node<T>::Node(const T& anEntry) : 
   item(anEntry), next(nullptr) {}

/**
 * Constructor for Node class, which initializes a Node with the
 * specified value and reference to the next Node
 * 
 * @param   anEntry  value to be stored in this Node
 * @param   nextNode reference to the next Node 
 */
template<class T>
Node<T>::Node(const T& anEntry, Node<T>* nextNode) : 
   item(anEntry), next(nextNode) {}

/**
 * Assigns the value to be stored in this Node
 *
 * @pre              Node must be initialized
 *
 * @post             new stored value will be assigned to this 
 *                   Node
 * 
 * @param   anEntry  value to be stored in this Node
 */
template<class T>
void Node<T>::setItem(const T& anEntry) {
   item = anEntry;
}

/**
 * Assigns the memory address to the next Node for this Node
 *
 * @pre              Node must be initialized
 *
 * @post             new memory address will be stored as a 
 *                   reference to the next Node
 * 
 * @param  nextNode  reference to the next Node
 */
template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr) {
   next = nextNodePtr;
}

/**
 * Retrieves the value stored in this Node
 *
 * @pre     Node must be initialized with value
 *
 * @post    state of this Node does not change
 *
 * @return  value stored in this Node
 */
template<class T>
T Node<T>::getItem() const {
   return item;
}

/**
 * Retrieves the reference in memory to the next Node for this 
 * Node
 *
 * @pre     Node must be initialized with next Node reference
 *
 * @post    state of this Node does not change
 *
 * @return  reference in memory to the next Node
 */
template<class T>
Node<T>* Node<T>::getNext() const {
   return next;
}

// generic class only works with int and Point objects
// because of declaration and implementation file segregation 
template class Node<int>;
template class Node<Point>;
// end Node.cpp