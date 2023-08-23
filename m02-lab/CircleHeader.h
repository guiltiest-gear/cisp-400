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
  void setX(int xcoord);
  void setY(int ycoord);
  void setRadius(int r);

  // Return the area of the circle using pi*r^2
  double getArea();

  // Return the circumference using 2*pi*r
  double getCircumference();

  // Return the circle as a string in the form (x,y) : radius
  std::string toString();
};

#endif  // !CIRCLEHEADER_H
