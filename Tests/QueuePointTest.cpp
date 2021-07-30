#include <iostream>
#include <cassert>
#include "Queue.h"
#include "Point.h"
#include <cmath>
#include <string>

/**
 * Tests Queue constructor
 */ 
void testQueueConstructor() {
   Queue<Point> testList;
   assert(testList.getCurrentSize() == 0);
   assert(testList.isEmpty() == true);
   std::cout << "Passed constructor test" << std::endl;
}
/**
 * Tests add, getCurrentSize and isEmpty methods of Queue class
 */
void testAddNode() {
   Queue<Point> testList;

   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   testList.push(point1);
   assert(testList.getCurrentSize() == 1);
   assert(testList.isEmpty() == false);

   testList.push(point2);
   assert(testList.getCurrentSize() == 2);
   assert(testList.isEmpty() == false);
   std::cout << "Passed push Node test" << std::endl;
}

/**
 * Tests clear method of Queue class
 */ 
void testClearNodes() {
   Queue<Point> testList;

   // makes sure that clear works with empty list
   testList.clear();
   assert(testList.getCurrentSize() == 0);

   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);//
   Point point3 = Point(1, -5);
   
   testList.push(point1);
   testList.push(point2);
   testList.push(point3);
   
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
   Queue<Point> testList;
   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);
   
   testList.push(point1);

   assert(testList.front() == point1);

   testList.push(point2);
   testList.push(point3);

   assert(testList.front() == point1);
   std::cout << "Passed front test" << std::endl;
}

/**
 * Tests back method of Queue class
 */
void testBack() {
   Queue<Point> testList;
   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);
   
   testList.push(point1);

   assert(testList.back() == point1);

   testList.push(point2);

   assert(testList.back() == point2);

   testList.push(point3);

   assert(testList.back() == point3);
   std::cout << "Passed back test" << std::endl;
}

/**
 * Tests copy constructor of Queue class
 */ 
void testCopyConstructor() {
   Queue<Point> testList;
   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);
   
   testList.push(point1);
   testList.push(point2);
   testList.push(point3);

   Queue<Point> secondTestList = testList;
   
   assert(testList.getCurrentSize() == secondTestList.getCurrentSize());

   Point frontPointListOne = testList.front();
   Point frontPointListTwo =  secondTestList.front();
   Point backPointListOne = testList.back();
   Point backPointListTwo =  secondTestList.back();
   
   assert(frontPointListOne == frontPointListTwo);
   assert(backPointListOne == backPointListTwo);

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
   Queue<Point> testList;
   assert(testList.pop() == false);

   
   Point point1 = Point(10, 11);
   testList.push(point1);
   assert(testList.pop() == true);
   assert(testList.isEmpty());


   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);
   testList.push(point2);
   testList.push(point3);

   assert(testList.pop() == true);
   assert(testList.getCurrentSize() == 1);
   assert(testList.pop() == true);
   std::cout << "Passed pop test" << std::endl;
}

/**
 * Tests ordering of Nodes in Queue class
 */
void testOrder() {
   Queue<Point> testList;
   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);


   testList.push(point1);
   testList.push(point2);
   testList.push(point3);

   assert(testList.front() == point1);
   assert(testList.back() == point3);
   assert(testList.pop() == true);
   assert(testList.front() == point2);
   assert(testList.back() == point3);
   assert(testList.pop() == true);
   assert(testList.front() == point3);
   assert(testList.back() == point3);
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
   Queue<Point> testList;
   Point point1 = Point(10, 11);
   Point point2 = Point(-9, 2);
   Point point3 = Point(1, -5);

   testList.push(point1);
   testList.push(point2);
   testList.push(point3);

   Queue<Point> secondTestList = testList;

   assert(secondTestList.front() == point1);
   assert(secondTestList.back() == point3);
   assert(secondTestList.pop() == true);
   assert(secondTestList.front() == point2);
   assert(secondTestList.back() == point3);
   assert(secondTestList.pop() == true);
   assert(secondTestList.front() == point3);
   assert(secondTestList.back() == point3);
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