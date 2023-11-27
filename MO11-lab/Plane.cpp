#include "Plane.h"

#include <cstdlib>
#include <iostream>

using std::to_string, std::string, std::cout;

string Plane::toString() {
  return getType() + " " + getModel() + " " + to_string(getYear()) + " Speed " +
         to_string(getSpeed());
}

int Plane::getAltitude() { return altitude; }

// Set altitude provided it is a positive number <300000
void Plane::setAltitude(int height) {
  try {
    // Exceptions in case we exceed the bounds
    if (height < 0) throw "Error! Height cannot be a negative number!";
    if (height > 300000) throw "Error! Height cannot exceed 300000!";
    altitude = height;
  } catch (const char* message) {
    cout << message << '\n';
    exit(1);
  }
}

// Implemented through polymorphism
void Plane::addSpeed(int s) {
  try {
    if (s < 0) throw "Error! Speed cannot be negative!";
    if ((getSpeed() + s) > 1000) throw "Over speed limit of 1000";
    // If neither exception fails, proceed to add speed
    setSpeed(getSpeed() + s);
  } catch (const char* message) {
    cout << message << '\n';
    exit(1);
  }
}

string Plane::serveDrinks() { return "Water and Apple Juice Available"; }
