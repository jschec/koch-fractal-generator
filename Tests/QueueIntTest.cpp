#include <iostream>
#include <cassert>
#include "Queue.h"
#include <cmath>
#include <string>

/**
 * Tests Queue constructor
 */ 
void testQueueConstructor() {
   Queue<int> testList;
   assert(testList.getCurrentSize() == 0);
   assert(testList.isEmpty() == true);
   std::cout << "Passed constructor test" << std::endl;
}
/**
 * Tests add, getCurrentSize and isEmpty methods of Queue class
 */
void testAddNode() {
   Queue<int> testList;

   testList.push(10);
   assert(testList.getCurrentSize() == 1);
   assert(testList.isEmpty() == false);

   testList.push(1);
   assert(testList.getCurrentSize() == 2);
   assert(testList.isEmpty() == false);
   std::cout << "Passed push Node test" << std::endl;
}

/**
 * Tests clear method of Queue class
 */ 
void testClearNodes() {
   Queue<int> testList;

   // makes sure that clear works with empty list
   testList.clear();
   assert(testList.getCurrentSize() == 0);
   
   testList.push(4);
   testList.push(-0);
   testList.push(1);
   
   // make sure that clear works with populated list
   assert(testList.getCurrentSize() == 3);
   testList.clear();
   
   assert(testList.getCurrentSize() == 0);
   assert(testList.isEmpty() == true);
   std::cout << "Passed clear test" << std::endl;
}

/**
 * Tests front method of Queue class
 */
void testFront() {
   Queue<int> testList;
   
   testList.push(11);

   assert(testList.front() == 11);

   testList.push(44);
   testList.push(33);

   assert(testList.front() == 11);
   std::cout << "Passed front test" << std::endl;
}

/**
 * Tests back method of Queue class
 */
void testBack() {
   Queue<int> testList;
   
   testList.push(1);

   assert(testList.back() == 1);

   testList.push(-14);

   assert(testList.back() == -14);

   testList.push(99);

   assert(testList.back() == 99);
   std::cout << "Passed back test" << std::endl;
}

/**
 * Tests copy constructor of Queue class
 */ 
void testCopyConstructor() {
   Queue<int> testList;
   
   testList.push(-11);
   testList.push(0);
   testList.push(45);

   Queue<int> secondTestList = testList;
   
   assert(testList.getCurrentSize() == secondTestList.getCurrentSize());
   assert(testList.front() == secondTestList.front());
   assert(testList.back() == secondTestList.back());

   std::cout << "list 1: ";
   testList.printList();
   std::cout << std::endl;
   std::cout << "list 2: ";
   secondTestList.printList();
   std::cout << std::endl;
   std::cout << "Passed copy constructor test" << std::endl;
}

/**
 * Tests pop method of Queue class
 */
void testPop() {
   Queue<int> testList;
   assert(testList.pop() == false);
   
   testList.push(10);
   assert(testList.pop() == true);
   assert(testList.isEmpty());

   testList.push(-9);
   testList.push(1);

   assert(testList.pop() == true);
   assert(testList.getCurrentSize() == 1);
   assert(testList.pop() == true);
   std::cout << "Passed pop test" << std::endl;
}

/**
 * Tests ordering of Nodes in Queue class
 */
void testOrder() {
   Queue<int> testList;

   testList.push(10);
   testList.push(-9);
   testList.push(1);

   assert(testList.front() == 10);
   assert(testList.back() == 1);
   assert(testList.pop() == true);
   assert(testList.front() == -9);
   assert(testList.back() == 1);
   assert(testList.pop() == true);
   assert(testList.front() == 1);
   assert(testList.back() == 1);
   assert(testList.pop() == true);
   assert(testList.isEmpty());
   assert(testList.pop() == false);
   std::cout << "Passed order test" << std::endl;
}

/**
 * Tests ordering of Nodes after invoking copy constructor
 * in Queue class
 */
void testCopyConstructorOrder() {
   Queue<int> testList;

   testList.push(10);
   testList.push(-9);
   testList.push(1);

   Queue<int> secondTestList = testList;

   assert(secondTestList.front() == 10);
   assert(secondTestList.back() == 1);
   assert(secondTestList.pop() == true);
   assert(secondTestList.front() == -9);
   assert(secondTestList.back() == 1);
   assert(secondTestList.pop() == true);
   assert(secondTestList.front() == 1);
   assert(secondTestList.back() == 1);
   assert(secondTestList.pop() == true);
   assert(secondTestList.isEmpty());
   assert(secondTestList.pop() == false);
   std::cout << "Passed copy constructor order test" << std::endl;
}

/**
 * A single method with all of the tests used to assess structure
 * and feature requirements of Queue classes
 */ 
void runAllTests() {
   testQueueConstructor();
   testAddNode();
   testClearNodes();
   testCopyConstructor();
   testFront();
   testBack();
   testPop();
   testOrder();
   testCopyConstructorOrder();
}

int main() {
   runAllTests();
} // end QueuePointTest.cpp