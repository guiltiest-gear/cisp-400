#include "Plane.h"

using std::string;

// Do nothing for the default constructor
Plane::Plane() { ; }

Plane::Plane(int year, int speed, string type, string model, int altitude) {
  Plane::setYear(year);
  Plane::setSpeed(speed);
  Plane::setType(type);
  Plane::setModel(model);
  if (altitude > 300000)
    // If we go over the limit, set to the max
    this->altitude = 300000;
  else
    this->altitude = altitude;
}

// Getters
int Plane::getAltitude() { return altitude; }

// Setters
void Plane::setAltitude(int height) {
  if (height > 300000)
    // If we go over the limit, set to the max
    altitude = 300000;
  else
    altitude = height;
}

// Methods
string Plane::serveDrinks() { return "Water and Apple Juice Available"; }
