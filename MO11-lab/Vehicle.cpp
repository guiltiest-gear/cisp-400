#include "Vehicle.h"

using std::string;

// Default constructor
Vehicle::Vehicle() {
  year = 0;
  speed = 0;
  model = "";
  type = "";
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
void Vehicle::setType(string type) { this->type = type; }
void Vehicle::setModel(string model) { this->model = model; }

// Getters
int Vehicle::getSpeed() const { return speed; }
int Vehicle::getYear() { return year; }
string Vehicle::getType() { return type; }
string Vehicle::getModel() { return model; }

// Methods
void Vehicle::addSpeed(int s) {}
string Vehicle::toString() { return "I am a Vehicle"; }
string Vehicle::serveDrinks() { return "Drinks are only served in Planes"; }
