#include <algorithm>
#include <iostream>
#include <memory>

#include "CircleHeader.h"
#include "Painting.h"

using std::cout, std::shared_ptr, std::make_shared;

int main() {
  // Create a shared pointer to circleOne
  shared_ptr<Circle> circleOnePtr = make_shared<Circle>(0, 0, 5);

  // Create a shared pointer to circleTwo
  shared_ptr<Circle> circleTwoPtr = make_shared<Circle>(-2, -2, 10);

  // Check if circleTwo is less than than circleOne
  if (circleTwoPtr < circleOnePtr)
    cout << "Circle Two is bigger\n";
  else
    cout << "Circle One is bigger\n";

  // Init painting p and print it
  cout << "Printing Painting p\n";
  Painting p("dataLab7.txt");
  cout << p.toString();

  // Copy painting p into painting q
  cout << "Printing Painting q\n";
  Painting q(p);
  cout << q.toString();

  // Change painting q
  cout << "Chaning Painting q\n";
  q.setRadius(0, 99);

  // Now print the paintings
  cout << "Printing Painting p\n" << p.toString();
  cout << "Printing Painting q\n" << q.toString();

  return 0;
}
