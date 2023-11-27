#include <iostream>

#include "CircleHeader.h"

using std::cout;

int main() {
  // Create a circle object
  Circle circleOne(0, 0, 5);

  // Create a pointer to circleOne
  Circle *c1Ptr = &circleOne;

  // Create another circle object
  Circle circleTwo(-2, -2, 10);

  // Create a pointer to circleTwo
  Circle *c2Ptr = &circleTwo;

  // Check if circleTwo is bigger than circleOne
  if (c2Ptr->greaterThan(c1Ptr))
    cout << "CircleTwo is larger\n";
  else
    cout << "CircleOne is larger\n";

  // Create a pointer array
  Circle *circlePointerArray[LENGTH];

  // Fill the array with the data
  inputData(circlePointerArray, "dataLab4.txt");

  // Display the array
  cout << "The circles in the array are:\n";
  for (int i = 0; i < LENGTH; i++) cout << circlePointerArray[i]->toString();

  // Sum the areas of the circles
  double sum_of_area = 0;
  for (int i = 0; i < LENGTH; i++)
    sum_of_area += circlePointerArray[i]->getArea();
  cout << "The total sum of the areas is " << sum_of_area << '\n';

  // Swap the position of the second and fourth circles
  Circle *tmp = circlePointerArray[1];  // We need a tempory pointer to store
                                        // the second value
  circlePointerArray[1] = circlePointerArray[3];
  circlePointerArray[3] = tmp;

  // Display the array
  cout << "The modified array is:\n";
  for (int i = 0; i < LENGTH; i++) cout << circlePointerArray[i]->toString();

  // Delete the objects references in circlePointerArray
  // NOTE: DO NOT FORGET THIS, AND DO NOT FORGET THE POINTER INDICATOR DELETE
  // THE REFERENCED OBJECTS IN THE ARRAY, NOT THE ARRAY ITSELF
  delete[] *circlePointerArray;
  return 0;
}
