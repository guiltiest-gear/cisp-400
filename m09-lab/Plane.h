#ifndef PLANE_H
#define PLANE_H

#include <string>

#include "Vehicle.h"

class Plane : public Vehicle {
 private:
  int altitude;

 public:
  Plane();
  Plane(int year, int speed, std::string type, std::string model, int altitude);
  int getAltitude();
  void setAltitude(int height);
  std::string serveDrinks();
};

#endif  // !PLANE_H
