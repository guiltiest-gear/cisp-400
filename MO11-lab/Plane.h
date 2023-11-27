#ifndef PLANE_H
#define PLANE_H

#include <string>

#include "Vehicle.h"

class Plane : public Vehicle {
 private:
  int altitude;

 public:
  Plane() {}
  Plane(int year, int speed, std::string type, std::string model, int altitude)
      : Vehicle(year, speed, type, model), altitude(altitude) {}
  void setAltitude(int height);
  void addSpeed(int speed);
  int getAltitude();
  std::string serveDrinks();
  std::string toString();
};

#endif  // !PLANE_H
