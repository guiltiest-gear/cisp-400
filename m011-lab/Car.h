#ifndef CAR_H
#define CAR_H

#include <string>

#include "Vehicle.h"

class Car : public Vehicle {
 private:
  int wheelSize;

 public:
  Car() {}
  Car(int year, int speed, std::string type, std::string model, int wheelSize)
      : Vehicle(year, speed, type, model), wheelSize(wheelSize) {}

  void addSpeed(int s);
  int getWheelSize();
  std::string toString();
  std::string serveDrinks();
};

#endif  // !CAR_H
