#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
class Vehicle {
 private:
  int year;
  int speed;
  std::string type;
  std::string model;

 public:
  Vehicle();
  Vehicle(int year, int speed, std::string type, std::string model);
  void setSpeed(int speed);
  void setYear(int year);
  void setModel(std::string model);
  void setType(std::string type);
  int getSpeed() const;
  int getYear();
  std::string getType();
  std::string getModel();
  virtual void addSpeed(int s);
  virtual std::string toString();
  virtual std::string serveDrinks();
};

#endif
