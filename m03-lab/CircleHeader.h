#ifndef CIRCLEHEADER_H
#define CIRCLEHEADER_H

#include <string>

class Circle {
 private:
  int x;
  int y;
  int radius;

 public:
  // Default constructor
  Circle() {
    x = 0;
    y = 0;
    radius = 1;
  }

  // Regular constructor
  Circle(int xcoord, int ycoord, int r) {
    x = xcoord;
    y = ycoord;
    radius = r;
  }

  // Getters
  int getX();
  int getY();
  int getRadius();

  // Setters
  void setX(int);
  void setY(int);
  void setRadius(int);

  // Return the area of the circle using pi*r^2
  double getArea();

  // Return the circumference using 2*pi*r
  double getCircumference();

  // Return the circle as a string in the form (x,y) : radius
  std::string toString();

  // Return the distance between this circle and another cirlce
  double getDistance(Circle);

  // Move the center of the circle to a new coordinate
  void moveTo(int, int);

  // Return true if the distance between the centers of the two circles is less
  // than the sum of their radii
  bool intersects(Circle);

  // Multiply the radius by the scale
  void resize(double);

  // Return a new circle with the same center as this circle, but radius
  // multiplied by scale
  Circle resize(int);
};

#endif  // !CIRCLEHEADER_H
