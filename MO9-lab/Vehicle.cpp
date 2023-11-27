#include "Vehicle.h"

using std::string;

// Default constructor
Vehicle::Vehicle() {
  // Set fields to zero and null if no arguments are provided
  year = speed = 0;
  type = "null";
  model = "null";
}

// Regular constructor
Vehicle::Vehicle(int year, int speed, string type, string model) {
  this->year = year;
  this->speed = speed;
  this->type = type;
  this->model = model;
}

// Setters
void Vehicle::setSpeed(int speed) { this->speed = speed; }
void Vehicle::setYear(int year) { this->year = year; }
void Vehicle::setModel(string model) { this->model = model; }
void Vehicle::setType(string type) { this->type = type; }

// Getters
int Vehicle::getSpeed() const { return speed; }
int Vehicle::getYear() { return year; }
string Vehicle::getModel() { return model; }
string Vehicle::getType() { return type; }

// Methods
string Vehicle::serveDrinks() { return "Drinks served only on Planes"; }
string Vehicle::toString() { return "I am a Vehicle"; }
