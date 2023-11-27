#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CircleHeader.h"

using std::string, std::to_string, std::pow, std::sqrt, std::vector,
    std::ifstream, std::istringstream, std::cout, std::getline;

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

// Return the distance between this circle and another circle
double Circle::getDistance(Circle other) {
  // Distance is sqrt((x2 - x1)^2 + (y2 - y1)^2)
  return sqrt(pow((other.x - this->x), 2) + pow((other.x - this->x), 2));
}

// Move the center of the circle to a new coordinate
void Circle::moveTo(int xcoord, int ycoord) {
  // Basically the same as the setter functions but put togther
  x = xcoord;
  y = ycoord;
}

// Return true if the distance between the centers of the two circles is less
// than the sum of their radii
bool Circle::intersects(Circle other) {
  // Get the distance with a function we already have
  double distance = Circle::getDistance(other);
  int sum = this->radius + other.radius;
  if (distance < sum) {
    return true;
  } else {
    return false;
  }
}

// Multiply the radius by the scale
void Circle::resize(double scale) { radius *= scale; }

// Return a new circle with the same center as this circle, but radius
// multiplied by scale
Circle Circle::resize(int scale) {
  return Circle(this->x, this->y, this->radius * scale);
}

// Return the value of count
int Circle::getCount() { return count; }

// Declare static count variable
int Circle::count = 0;

// Read data from a file and push it into the vector
void inputData(vector<Circle> &vec, string filename) {
  // Open up the file
  ifstream input(filename);
  // Init the variables
  istringstream instream;
  string data;
  int x, y, radius;
  // Attempt to open the file
  try {
    // If we do get it, read from it and push the fields into a circle object
    // and push circle objects into vector
    if (input) {
      while (!input.eof()) {
        getline(input, data);
        istringstream instream(data);
        instream >> x;
        instream >> y;
        instream >> radius;
        Circle circle(x, y, radius);
        vec.push_back(circle);
      }
    } else {
      // If we don't find it, throw an error
      throw string("File Open Error\n");
    }
    // If we throw an error, print it, close the input, and abort
  } catch (string message) {
    cout << message;
    input.close();
    exit(1);
  }

  // NOTE: Do not forget to close the file
  input.close();
}
