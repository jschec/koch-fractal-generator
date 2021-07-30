/**
 * Node.h
 *
 * Declarations for the Node class, which stores a reference to the
 * next Node and a value. These compose a Queue ADT.
 *
 * Joshua Scheck
 * 2020-11-20
 */
#pragma once

/**
 * Represents a Node in a Queue ADT
 */
template<class T>
class Node {
public:
   /**
    * Default constructor for Node class, which initializes an empty
    * Node
    */
   Node();

   /**
    * Constructor for Node class, which initializes a Node with the
    * specified value, but has no next Node reference
    * 
    * @param   anEntry  value to be stored in this Node
    */
   Node(const T& anEntry);

   /**
    * Constructor for Node class, which initializes a Node with the
    * specified value and reference to the next Node
    * 
    * @param   anEntry  value to be stored in this Node
    * @param   nextNode reference to the next Node 
    */
   Node(const T& anEntry, Node<T>* nextNode);

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
   void setItem(const T& anEntry);

   /**
    * Assigns the memory address to the next Node for this Node
    *
    * @pre              Node must be initialized
    *
    * @post             new memory address will be stored as a 
    *                   reference to the next Node
    * 
    * @param   nextNode reference to the next Node
    */
   void setNext(Node<T>* nextNode);

   /**
    * Retrieves the value stored in this Node
    *
    * @pre     Node must be initialized with value
    *
    * @post    state of this Node does not change
    *
    * @return  value stored in this Node
    */
   T getItem() const;

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
   Node<T>* getNext() const;
private:
   /** value stored in this Node */
   T item;
   /** reference in memory to the next Node in the Queue */
   Node<T>* next;
}; // end Node.h