#include <iostream>
#include <memory>

#include "Car.h"
#include "Plane.h"

using std::cout, std::shared_ptr, std::make_shared;

int main() {
  shared_ptr<Vehicle> car = make_shared<Car>(1992, 20, "Car", "Honda", 40);
  cout << "-----------------------------------\n";
  cout << "Making a Car\n";
  cout << "Model: " << car->getModel() << '\n';
  cout << "Year: " << car->getYear() << '\n';
  cout << "Speed: " << car->getSpeed() << '\n';

  shared_ptr<Vehicle> plane =
      make_shared<Plane>(2020, 200, "Plane", "Boeing", 3000);

  cout << "-----------------------------------\n";
  cout << "Making a Plane\n";
  cout << "Model: " << plane->getModel() << '\n';
  cout << "Year: " << plane->getYear() << '\n';
  cout << "Speed: " << plane->getSpeed() << '\n';

  cout << "-----------------------------------\n";

  cout << "Using the toString function: " << car->toString() << "\n\n";

  cout << "Using the toString function: " << plane->toString() << "\n\n";
  cout << "-----------------------------------\n";

  cout << "Serve Drinks: Plane Class " << plane->serveDrinks() << '\n';
  cout << "Serve Drinks: Car Class " << car->serveDrinks() << '\n';

  cout << "-----------------------------------\n";
  cout << "Adding speed (20 mph) to car\n";
  car->addSpeed(20);
  cout << "Speed is now : " << car->getSpeed() << "\n\n";
  /* car->addSpeed(-1);
   cout<<"Speed is now : "<<car->getSpeed()<<'\n'<<'\n';
   */
  cout << "-----------------------------------\n";
  cout << "Adding speed (700 mph) to plane\n";
  plane->addSpeed(700);
  cout << "Speed is now : " << plane->getSpeed() << "\n\n";
  cout << "-----------------------------------\n";
  cout << "Adding speed (200) to plane\n";
  plane->addSpeed(200);
  cout << "Speed is now : " << plane->getSpeed() << "\n\n";
  cout << "-----------------------------------\n";
}
