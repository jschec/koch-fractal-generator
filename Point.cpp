/**
 * Point.cpp
 *
 * Implementations for the Point class, which initializes an object
 * with integer values for X and Y coordinates. These Points compose
 * a Koch curve.
 *
 * Joshua Scheck
 * 2020-11-20
 */
#include <cmath>
#include "Point.h"

/**
 * Default constructor for Point class.
 */
Point::Point() {};

/**
 * Constructor for Point class, which initializes both X and
 * Y coordinates.
 * 
 * @param   xCoord   X coordinate for this Point
 * @param   yCoord   Y coordinate for this Point
 */
Point::Point(double xCoord, double yCoord) : 
   xCoord(xCoord), yCoord(yCoord) {}

/**
 * Retrieves the X coordinate for this Point
 *
 * @pre     Point must be initialized with X coordinate
 *
 * @post    state of this Point does not change
 *
 * @return  X coordinate for this Point
 */
double Point::getXCoord() const {
    return xCoord;
}

/**
 * Retrieves the Y coordinate for this Point
 *
 * @pre     Point must be initialized with Y coordinate
 *
 * @post    state of this Point does not change
 *
 * @return  Y coordinate for this Point
 */
double Point::getYCoord() const {
    return yCoord;
}

/**
 * Retrieves a Point object that is rotated based on the provided
 * angle and this and the specified Point 
 * 
 * @pre              Point must be initialized with X and Y 
 *                   coordinates
 *
 * @post             state of this Point does not change
 * 
 * @param   angle    angle in degrees to rotate retrieved Point
 * @param   refPoint specified Point object that acts as
 *                   rotation reference
 * 
 * @return           Point object with rotated X and Y coordinates
 */
Point Point::rotate(double angle, Point refPoint) const {
   // converts degree rotation to radian value
   double theta = angle * (M_PI / 180.0);

   // get central point coordinates
   double xo = refPoint.getXCoord();
   double yo = refPoint.getYCoord();

   // use trig to calculate rotated coordinates
   double xModified  = xo + ((xCoord - xo) * cos(theta) -
      (yCoord - yo) * sin(theta));
   double yModified  = yo + ((xCoord - xo) * sin(theta) + 
      (yCoord - yo) * cos(theta));
   
   // return Point with modified values
   return Point(xModified, yModified);
}

/**
 * Retrieves a Point object based on the specified ratio to
 * between this and the specified Point.
 *
 * @pre              Point must be initialized with X and Y 
 *                   coordinates
 *
 * @post             state of this Point does not change
 * 
 * @param   currLen  length of this Point
 * @param   refLen   length of specified Point
 * @param   refPoint specified Point object that acts as
 *                   on the end points
 * 
 * @return           Point object with X and Y coordinates
 *                   of the identified location between
 *                   this and the specified Point
 */
Point Point::section(double currLen, double refLen, Point refPoint) 
const {

   double xRef = refPoint.getXCoord();
   double yRef = refPoint.getYCoord();

   double xModified = ((refLen * xCoord) + (currLen * xRef)) / 
      (currLen + refLen); 
   double yModified = ((refLen * yCoord) + (currLen * yRef)) /
      (currLen + refLen);

   // return Point with modified values
   return Point(xModified, yModified);
};

/**
 * Overloads the equality operator for use with Point objects.
 * Allows for determining if two points have the same X and Y
 * coordinates.
 *
 * @pre           Point must be initialized with X and Y 
 *                coordinates
 *
 * @post          state of this Point does not change
 * 
 * @param   rhs   Point object on the right hand side of this
 *                operator
 * 
 * @return        true if this and the right hand side Point
 *                are equal, otherwise false
 */
bool Point::operator==(Point& rhs) const {
    if (xCoord == rhs.xCoord || yCoord == rhs.yCoord) {
        return true;
    }
    return false;
}

/**
 * Overloads the assignment operator for use with Point objects.
 *
 * @pre           Point must be initialized with X and Y 
 *                coordinates
 *
 * @post          right hand side Point values are assigned to 
 *                this Point
 * 
 * @param   rhs   Point object on the right hand side of this
 *                operator
 */
void Point::operator=(const Point& rhs) {
    xCoord = rhs.xCoord;
    yCoord = rhs.yCoord;
}

/**
 * Overloads the output stream operator for use with Point objects.
 * Allows for outputting the values of this Point into the output
 * stream.
 *
 * @pre              Point must be initialized with X and Y 
 *                   coordinates
 *
 * @post             value of this Point is sent to output stream
 * 
 * @param   output   output to stream this Point to
 * @param   point    this Point object 
 *
 * @return           output stream
 */
std::ostream& operator<<(std::ostream& output, Point point) {
   output << "[" << point.xCoord << "," << point.yCoord << "]";
   return output;
}; // end Point.cpp