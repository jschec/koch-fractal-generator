/**
 * Queue.h
 *
 * Declarations for the Queue class, which initializes as an empty
 * Queue ADT but can be populated with Nodes added sequently at the 
 * end of the Queue. Furthermore, Nodes can be removed from the top
 * of the Queue.
 *
 * Joshua Scheck
 * 2020-11-20
 */
#pragma once
#include "Node.h"

/**
 * Represents a Queue ADT that stores values as Nodes
 */
template<class T>
class Queue {
public:
  /**
   * Default constructor for this Queue class. Initializes an empty
   * Queue.
   */
  Queue();

  /**
   * Copy constructor for this Queue class
   * 
   * @param   otherQueue  values from another Queue to be deep copied
   *                      to this Queue
   */ 
  Queue(const Queue& otherQueue);

  /**
   * Destructor for this Queue class that destroys this Queue
   * and frees memory allocated by the object.
   *
   * Calls Queue::clear() method.
   *
   * @pre     Queue must be initialized
   *
   * @post    this Queue is destructed with all prior Nodes being 
   *          deallocated from memory
   */
  ~Queue();

  /**
   * Retrieves the current number of Nodes in this Queue
   *
   * @pre     Queue must be initialized, which will also initialize
   *          the retrieved class member currentSize
   *
   * @post    state of this Queue does not change
   *
   * @return  the number of Nodes in this Queue
   */
  int getCurrentSize() const;

  /**
   * Determines if the number of Nodes in this Queue is zero
   *
   * @pre     Queue must be initialized, which will also initialize
   *          the retrieved class member currentSize
   *
   * @post    state of this Queue does not change
   *
   * @return  true if the number of Nodes in this Queue
   *          is zero, false otherwise
   */
  bool isEmpty() const; 

  /**
   * Removes all entries from this Queue by sequentially deallocating
   * memory from each Node existing in this Queue
   *
   * @pre     Queue must be initialized, which will also initialize
   *          manipulated class members head, tail, and currentSize
   *
   * @post    this Queue will have no Nodes (is empty) and class 
   *          member currentSize will be set to 0
   */
  void clear();

   /**
   * Adds Node to the back of this Queue
   *
   * @pre            Queue must be initialized, which will also 
   *                 initialize manipulated class members, tail, and
   *                 currentSize
   *
   * @post           If successful, new Node is added to the tail, 
   *                 size of this Queue increases by 1. No change is
   *                 object state if unsuccessful.
   * 
   * @param anEntry  value to add to the end of this Queue
   * 
   * @return         true if the head Node is successfully added to
   *                 this Queue, false otherwise
   */
  bool push(T anEntry);

   /**
   * Removes head Node from this Queue and shifts all downstream 
   * Nodes up
   *
   * @pre     Queue must be initialized, which will also initialize
   *          manipulated class members head, tail, and currentSize
   *
   * @post    If successful, head Node is deleted, size of this Queue
   *          decreases by 1 and all downstream Nodes are shifted up 
   *          by one. No change is object state if unsuccessful.
   * 
   * @return  true if the head Node is successfully removed from this 
   *          Queue, false otherwise
   */
  bool pop();

   /**
   * Retrieves value from the Node at the front of this Queue
   *
   * @pre     Queue must be initialized, which will also initialize
   *          retrieved class member head
   *
   * @post    state of this Queue does not change
   * 
   * @return  value from front Node
   */
  T front() const;

   /**
   * Retrieves value from the Node at the back of this Queue
   *
   * @pre     Queue must be initialized, which will also initialize
   *          retrieved class member tail
   *
   * @post    state of this Queue does not change
   * 
   * @return  value from back Node
   */
  T back() const;

   /**
   * Displays contents of this Queue through the output stream
   *
   * @pre     Queue must be initialized, which will also initialize
   *          retrieved class member head, tail, and currentSize
   *
   * @post    state of this Queue does not change
   */
  void printList();

protected:
  /** The current number of Nodes in this Queue. */
  int currentSize;
  /** Reference to the address of the first Node in this Queue, 
   * otherwise nullptr. */
  Node<T> *head;
  /** Reference to the address of the last Node in this Queue, 
   * otherwise nullptr. */
  Node<T> *tail;
}; // end Queue.h