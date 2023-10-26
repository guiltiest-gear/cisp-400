#ifndef CAR_H
#define CAR_H

#include <string>

#include "Vehicle.h"

class Car : public Vehicle {
 private:
  int wheelSize;

 public:
  Car();
  Car(int year, int speed, std::string type, std::string model, int wheelSize);
  std::string serveDrinks();
  int getWheelSize();
  std::string toString();
};

#endif  // !CAR_H
