#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
  // attributes of the Vehicle class
 private:
  int year;
  int speed;
  std::string type;
  std::string model;

  // default and custom constructor of the Vehicle class
 public:
  Vehicle();
  Vehicle(int year, int speed, std::string type, std::string model);
  // getters and setters for each field
  void setSpeed(int speed);
  void setYear(int year);
  void setModel(std::string model);
  void setType(std::string type);
  int getSpeed() const;
  int getYear();
  std::string getType();
  std::string getModel();
  // other methods of the Vehicle class
  std::string toString();
  std::string serveDrinks();
};

#endif  // !VEHICLE_H
