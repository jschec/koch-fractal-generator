/**
 * KochGenerator.h
 *
 * Declarations for the KochGenerator class, which initializes an 
 * object that creates and stores Point objects to draw Koch curves
 *
 * Joshua Scheck
 * 2020-11-20
 */

#pragma once
#include <iostream>
#include "Queue.h"
#include "Point.h"

/**
 * Represents a Point in a Koch curve
 */
class KochGenerator {

/**
 * Overloads the output stream operator for use with KochGenerator 
 * objects. Allows for outputting the values of this KochGenerator 
 * into the output stream.
 *
 * @pre                    KochGenerator must be initialized
 *
 * @post                   value of this KochGenerator is sent to 
 *                         output stream
 * 
 * @param   output         output to stream this KochGenerator to
 * 
 * @param   kochGenerator  this KochGenerator object 
 *
 * @return                 output stream
 */
friend std::ostream& operator<<(std::ostream& output,
   KochGenerator kochGenerator);

public:
   /**
    * Constructor for KochGenerator class
    * 
    * @param   x1    X coordinate of first point
    * @param   y1    Y coordinate of first point
    * @param   x2    X coordinate of second point
    * @param   y2    Y coordinate of second point
    * @param   level Koch level to draw
    */
   KochGenerator(double x1, double y1, double x2, double y2, int level);

   /**
   * Recursively adds points representing Koch curve
   *
   * @pre            KochGenerator must be initialized
   *
   * @post           May add point to points Queue
   * 
   * @param   x1     X coordinate of first point
   * @param   y1     Y coordinate of first point
   * @param   x2     X coordinate of second point
   * @param   y2     Y coordinate of second point
   * @param   level  Koch level to draw
   */
   void drawKoch(double x1, double y1, double x2, double y2, int level);

private:
   /** stores Point objects representing Koch curve */
   Queue<Point> points;
   /** first point inputted into this KochGenerator object */
   Point firstPoint;
   /** Koch curve level */
   int curveLevel;
};

/**
 * Overloads the output stream operator for use with KochGenerator 
 * objects. Allows for outputting the values of this KochGenerator 
 * into the output stream.
 *
 * @pre                    KochGenerator must be initialized
 *
 * @post                   value of this KochGenerator is sent to 
 *                         output stream
 * 
 * @param   output         output to stream this KochGenerator to
 * 
 * @param   kochGenerator  this KochGenerator object 
 *
 * @return                 output stream
 */
std::ostream& operator<<(std::ostream& output,
   KochGenerator kochGenerator);
// end KochGenerator.h