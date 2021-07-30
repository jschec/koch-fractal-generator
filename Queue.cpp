/**
 * Queue.cpp
 *
 * Implementations for the Queue class, which initializes as an empty
 * Queue ADT but can be populated with Nodes added sequently at the 
 * end of the Queue. Furthermore, Nodes can be removed from the top
 * of the Queue.
 *
 * Joshua Scheck
 * 2020-11-20
 */
#include <iostream>
#include "Queue.h"
#include "Node.h"
#include "Point.h"


/**
 * Default constructor for this Queue class. Initializes an empty
 * Queue.
 */
template<class T>
Queue<T>::Queue() : 
   currentSize(0), head(nullptr), tail(nullptr) {}

/**
 * Copy constructor for this Queue class
 * 
 * @param   otherQueue  values from another Queue to be deep copied
 *                      to this Queue
 */
template<class T>
Queue<T>::Queue(const Queue& otherQueue) {
   currentSize  = otherQueue.currentSize;
   Node<T>* otherCurrNode = otherQueue.head;

   // create empty Queue if otherQueue is empty
	if (otherCurrNode == nullptr) {
		head = nullptr;
      tail = nullptr;
	}
   // deep copy values from otherQueue
   else {
		head = new Node<T>;
		head->setItem(otherCurrNode->getItem());
		
      // track newly created Nodes
      Node<T>* newCurrNode = head;
      
      otherCurrNode = otherCurrNode->getNext();

		while (otherCurrNode != nullptr) {
         T nextItem = otherCurrNode->getItem();
         Node<T>* newNode = new Node<T>(nextItem);

         newCurrNode->setNext(newNode);

         newCurrNode = newCurrNode->getNext();
         otherCurrNode = otherCurrNode->getNext();
		}
		newCurrNode->setNext(nullptr);
      tail = newCurrNode;
	}
}

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
template<class T>
Queue<T>::~Queue() {
   clear(); 
}

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
template<class T>
int Queue<T>::getCurrentSize() const { 
   return currentSize; 
}

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
template<class T>
bool Queue<T>::isEmpty() const {
  if (currentSize == 0) {
    return true;
  }

  return false;
}

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
template<class T>
void Queue<T>::clear() {
  Node<T> *currNode = head;
  Node<T> *nextNode = nullptr;

  // deallocate memory from Nodes in this Queue if not empty
  while (currNode != nullptr) {
    // obtains the reference for the next node to avoid dangling pointers
    nextNode = currNode->getNext();
    // deallocate memory from currentNode in freestore
    delete currNode;
    currNode = nullptr;
    // move to the next Node in this Queue
    currNode = nextNode;
  }

  // reset this Queue to starting conditions (empty list)
  head = nullptr;
  tail = nullptr;
  currentSize = 0;
}

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
template<class T>
bool Queue<T>::push(T newEntry) {
   try {
      Node<T>* newNode = new Node<T>(newEntry);
      if (currentSize == 0) {
         head = newNode;
         tail = newNode;
      } 
      else {
         tail->setNext(newNode);
         tail = newNode;
      }
      currentSize++;
      return true;
   }
   // inability to allocate memory will throw a std::bad_allac error
   // which will be caught and signals a lack of success
   catch (std::bad_alloc &exc) {
      return false;
   }
}

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
template<class T>
bool Queue<T>::pop() {
   
   if (currentSize > 0) {
      Node<T>* currNode = head;
      Node<T>* nextNode = currNode->getNext();

      // deallocate memory from removed Node and recalculate size
      // of this Queue
      delete currNode;
      currNode = nullptr;
      currentSize--;

      if (currentSize == 0) {
         head = nullptr;
         tail = nullptr;
      } 
      else {
         // after memory deallocation, replace head address to the
         // address of the next Node in this Queue.
         head = nextNode;
      }
      return true;
   }
   return false;
}

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
template<class T>
T Queue<T>::front() const {
   if (isEmpty())
   {
      std::cout << "Cannot peek at the front of an empty queue.\
         Program terminated";
      exit(EXIT_FAILURE);
   }
   return head->getItem();
}

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
template<class T>
T Queue<T>::back() const {
   if (isEmpty())
   {
      std::cout << "Cannot peek at the back of an empty queue.\
         Program terminated";
      exit(EXIT_FAILURE);
   }
   return tail->getItem();
}

/**
 * Displays contents of this Queue through the output stream
 *
 * @pre     Queue must be initialized, which will also initialize
 *          retrieved class member head, tail, and currentSize
 *
 * @post    state of this Queue does not change
 */
template<class T>
void Queue<T>::printList(){
	Node<T>* currNode = head;
	
   std::cout << "[";

	while (currNode != nullptr){
      // print data stored at each Node
		std::cout << currNode->getItem();
		currNode = currNode->getNext();

      // print a comma unless at the end of the list
		if (currNode != nullptr){
			std::cout << ","; 
		}
	}
	std::cout << "]";
}

// generic class only works with int and Point objects
// because of declaration and implementation file segregation 
template class Queue<int>;
template class Queue<Point>;
// end Queue.cpp