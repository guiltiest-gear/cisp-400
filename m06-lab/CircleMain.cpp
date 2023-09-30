#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "CircleHeader.h"

using std::cout, std::vector, std::shared_ptr, std::make_shared, std::iter_swap;

int main() {
  // Create a shared pointer to circleOne
  shared_ptr<Circle> circleOnePtr = make_shared<Circle>(0, 0, 5);

  // Create a shared pointer to circleTwo
  shared_ptr<Circle> circleTwoPtr = make_shared<Circle>(-2, -2, 10);

  // Check if circleTwo is bigger than circleOne
  if (circleTwoPtr->greaterThan(circleOnePtr))
    cout << "Circle Two is bigger\n";
  else
    cout << "Circle One is bigger\n";

  // Create a vector of pointers to circles
  vector<shared_ptr<Circle>> circlePointerVector;

  // Fill the vector
  inputData(circlePointerVector, "dataLab6.txt");

  // Generate an iterator for the vector
  vector<shared_ptr<Circle>>::iterator it;
  // Display the circles
  cout << "The circles created are:\n";
  for (it = circlePointerVector.begin(); it != circlePointerVector.end(); it++)
    cout << it->get()->toString();

  // Display the sum of the areas of the circle
  double sum = 0;
  for (it = circlePointerVector.begin(); it != circlePointerVector.end(); it++)
    // Iterate and accumulate
    sum += it->get()->getArea();
  cout << "The total area of the circles is " << sum << '\n';

  // Swap the position of the second and fourth circles
  iter_swap(circlePointerVector.begin() + 1, circlePointerVector.begin() + 3);

  // Iterate and display
  cout << "The circles created are:\n";
  for (it = circlePointerVector.begin(); it != circlePointerVector.end(); it++)
    cout << it->get()->toString();

  return 0;
}
