#ifndef CIRCLEHEADER_H
#define CIRCLEHEADER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Circle {
 private:
  int x;
  int y;
  int radius;

 public:
  // Static variable to track how many circles have been created
  static int count;
  // Default constructor
  Circle();

  // Regular constructor
  Circle(int, int, int);

  // Getters
  int getX();
  int getY();
  int getRadius();
  // NOTE: Make sure that the prototype is declared as static or you'll get an
  // error
  static int getCount();

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

  // Check if a circle is larger than another circle
  bool greaterThan(std::shared_ptr<Circle>);
};

// Read data from a file and push it into the vector
void inputData(std::vector<std::shared_ptr<Circle>> &, std::string);

#endif  // !CIRCLEHEADER_H
