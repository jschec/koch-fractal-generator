/**
 * KochGenerator.h
 *
 * Implementations for the KochGenerator class, which initializes an 
 * object that creates and stores Point objects to draw Koch curves
 *
 * Joshua Scheck
 * 2020-11-20
 */
#include <cmath>
#include <iostream>
#include "KochGenerator.h"

/**
 * Constructor for KochGenerator class
 * 
 * @param   x1    X coordinate of first point
 * @param   y1    Y coordinate of first point
 * @param   x2    X coordinate of second point
 * @param   y2    Y coordinate of second point
 * @param   level Koch level to draw
 */
KochGenerator::KochGenerator(double x1, double y1, double x2, 
   double y2, int level) {
   
   firstPoint = Point(x1, y1);
   curveLevel = level;
   drawKoch(x1, y1, x2, y2, level);
}

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
void KochGenerator::drawKoch(double x1, double y1, double x2, double y2, int level)
{
   if (level <= 0)
   {
      points.push(Point(x2, y2));
   }
   else
   {
      // create end points for this recursive call
      Point initialPoint = Point(x1, y1);
      Point lastPoint = Point(x2, y2);

      // section koch curve into thirds
      Point firstThird = initialPoint.section(1, 2, lastPoint);
      Point secondThird = firstThird.section(1, 1, lastPoint);
      
      // draw first third
      drawKoch(x1, y1, firstThird.getXCoord(), firstThird.getYCoord(),
         level-1);

      // draw tip of equalaterial triangle in middle
      Point angledPoint = firstThird.rotate(-60, secondThird);
      drawKoch(firstThird.getXCoord(), firstThird.getYCoord(), 
         angledPoint.getXCoord(), angledPoint.getYCoord(), level-1);
      drawKoch(angledPoint.getXCoord(), angledPoint.getYCoord(), 
         secondThird.getXCoord(), secondThird.getYCoord(), level-1);
      
      // draw last third
      drawKoch(secondThird.getXCoord(), secondThird.getYCoord(), 
         lastPoint.getXCoord(), lastPoint.getYCoord(), level-1);

   }
}

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
   KochGenerator kochGenerator) {
   
   output << "%!PS-Adobe-2.0" << std::endl;

   int initialXVal = round(kochGenerator.firstPoint.getXCoord());
   int initialYVal = round(kochGenerator.firstPoint.getYCoord());

   output << initialXVal << "\t" << initialYVal << "\t" <<  
      "moveto" << std::endl;
   
   if (kochGenerator.curveLevel == 0) {
      Point currPoint = kochGenerator.points.front();

      int adjustedXVal = round(currPoint.getXCoord());
      int adjustedYVal = round(currPoint.getYCoord());

      output << adjustedXVal << "\t" << 
         adjustedYVal << "\t" << "lineto" << std::endl;
      
      // remove top Point of the queue
      kochGenerator.points.pop();
   }
   else {
      double priorXCoord = kochGenerator.firstPoint.getXCoord();
      double priorYCoord = kochGenerator.firstPoint.getYCoord();

      while(!kochGenerator.points.isEmpty()) {
         Point currPoint = kochGenerator.points.front();

         int adjustedXVal = round(currPoint.getXCoord() - 
            priorXCoord);
         int adjustedYVal = round(currPoint.getYCoord() - 
            priorYCoord);

         // output adjusted coordinates
         output << adjustedXVal << "\t" << 
            adjustedYVal << "\t" << "rlineto" << std::endl;
         
         // assign prior point coordinates
         priorXCoord = currPoint.getXCoord();
         priorYCoord = currPoint.getYCoord();

         // remove top Point of the queue
         kochGenerator.points.pop();
      }
   }

   output << "stroke" << std::endl;
   output << "showpage" << std::endl;

   return output;
} // end KochGenerator.cpp