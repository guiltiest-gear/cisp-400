#include <iostream>
#include <memory>

#include "Car.h"
#include "Plane.h"

using std::cout, std::make_shared, std::shared_ptr;

int main() {
  // create a shared pointer called car to a Car object and
  // construct the Car object using its custom constructor in dynamic memory
  shared_ptr<Car> car = make_shared<Car>(1992, 20, "Car", "Honda", 40);
  cout << "-----------------------------------\n";
  cout << "Making a Car\n";
  cout << "Model: " << car->getModel() << '\n';
  cout << "Year: " << car->getYear() << '\n';
  cout << "Speed: " << car->getSpeed() << '\n';
  cout << "WheelSize: " << car->getWheelSize() << '\n';

  // create a shared pointer called plane to a Plane object and
  // construct the Plane object using its custom constructor in dynamic memory

  shared_ptr<Plane> plane =
      make_shared<Plane>(2020, 200, "Plane", "Boeing", 3000);

  cout << "-----------------------------------\n";
  cout << "Making a Plane\n";
  cout << "Model: " << plane->getModel() << '\n';
  cout << "Year: " << plane->getYear() << '\n';
  cout << "Speed: " << plane->getSpeed() << '\n';
  cout << "Altitude: " << plane->getAltitude() << '\n';
  cout << "-----------------------------------\n";

  // call the getWheelSize() and toString() functions on the car
  cout << "I am a car and my wheelSize is " << car->getWheelSize() << '\n';
  cout << "Using the toString function: " << car->toString() << "\n\n";

  // call the getAltitude() and toString() functions on the plane
  cout << "I am a plane and my altitude is " << plane->getAltitude() << '\n';
  cout << "Using the toString function: " << plane->toString() << "\n\n";
  cout << "-----------------------------------\n";
  // Observe the situations when overriding takes place and when it
  // does not in the following function calls
  cout << "Creating a plane of Declared Type Plane and actual type Plane\n";
  cout << "Serve Drinks Function Overriden by Plane Class\n";
  shared_ptr<Plane> plane2 =
      make_shared<Plane>(2000, 100, "Plane", "Lockheed", 5000);

  cout << "Plane says :" << plane2->serveDrinks() << '\n';

  cout << "-----------------------------------\n";
  cout << "Creating a plane of Declared Type Vehicle and actual type Plane\n";
  shared_ptr<Vehicle> plane3 =
      make_shared<Plane>(1000, 100, "Plane", "Hughes", 2000);
  cout << "Serve Drinks Function Not Overriden by Plane Class, Vehicle Class "
          "prevails\n";
  cout << "Vehicle Says: " << plane3->serveDrinks() << '\n';
}
