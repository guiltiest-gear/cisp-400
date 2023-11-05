#include "Car.h"

#include <cstdlib>
#include <iostream>
#include <string>

using std::cout, std::string, std::to_string;

void Car::addSpeed(int s) {
  try {
    if (s < 0) throw "Error! Speed cannot be negative!";
    if ((getSpeed() + s) > 100) throw "Over speed limit of 100";
    // If neither exception is thrown, proceed to add speed
    Car::setSpeed(Car::getSpeed() + s);
  } catch (const char* message) {
    cout << message << '\n';
    exit(1);
  }
}

string Car::serveDrinks() {
  return "Food and Drinks are not permitted in a car";
}

int Car::getWheelSize() { return wheelSize; }

string Car::toString() {
  return getType() + " " + getModel() + " " + to_string(getYear()) + " Speed " +
         to_string(getSpeed()) + " wheelSize " + to_string(getWheelSize());
}
