#include <cmath>
#include <string>

#include "CircleHeader.h"

using std::string, std::to_string, std::pow;

// Getter definitions
int Circle::getX() { return x; }
int Circle::getY() { return y; }
int Circle::getRadius() { return radius; }

// Setter definitions
void Circle::setX(int xcoord) { x = xcoord; }
void Circle::setY(int ycoord) { y = ycoord; }
void Circle::setRadius(int r) { radius = r; }

// Return the area of the circle using pi*r^2
double Circle::getArea() { return M_PI * pow(radius, 2); }

// Return the circumference using 2*pi*r
double Circle::getCircumference() {
  // Use 2.0 to avoid implicit cast to int
  return 2.0 * M_PI * radius;
}

// Return the circle as a string in the form (x,y):radius
string Circle::toString() {
  return "(" + to_string(x) + "," + to_string(y) + "):" + to_string(radius) +
         '\n';
}
