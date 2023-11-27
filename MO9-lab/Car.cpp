#include "Car.h"

using std::string, std::to_string;

Car::Car() { ; }

Car::Car(int year, int speed, string type, string model, int wheelSize) {
  Car::setYear(year);
  Car::setSpeed(speed);
  Car::setType(type);
  Car::setModel(model);
  this->wheelSize = wheelSize;
}

// Getters
int Car::getWheelSize() { return wheelSize; }

// Methods
string Car::serveDrinks() { return ""; }
string Car::toString() {
  return "Car " + Car::getModel() + " " + to_string(Car::getYear()) +
         " Speed " + to_string(Car::getSpeed()) + " wheelSize " +
         to_string(Car::getWheelSize());
}
