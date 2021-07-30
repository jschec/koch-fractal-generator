/**
 * Main.cpp
 *
 * Entry point for program
 *
 * Joshua Scheck
 * 2020-11-20
 */

#include <iostream>
#include <cassert>
#include "Queue.h"
#include "Point.h"
#include <cmath>
#include <string>
#include "KochGenerator.h"

/**
 * Entry point for program for generating Koch curve in .ps file 
 * format
 */
int main(int argc, char** argv) {
   // pass in command line arguements
   int x1 = atoi(argv[1]);
   int y1 = atoi(argv[2]);
   int x2 = atoi(argv[3]);
   int y2 = atoi(argv[4]);
   int curveLevel = atoi(argv[5]);

   if(curveLevel < 0) {
      throw std::invalid_argument("Koch curve level must be greater or equal than 0");
   }

   // create Koch curve
   KochGenerator generator(x1, y1, x2, y2, curveLevel);
   
   // output Koch curve points in .ps file format
   std::cout << generator;
} // end Main.cpp