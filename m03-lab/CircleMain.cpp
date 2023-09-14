#include <iostream>

#include "CircleHeader.h"

using std::cout;

int main() {
  // Declare and init circleOne and circleTwo
  Circle circleOne, circleTwo(0, 0, 4);
  // Display the circles
  cout << "First Circle " << circleOne.toString();
  cout << "Second Circle " << circleTwo.toString();

  // Display the distance between circle one and two
  cout << "The distance between the two circles is: "
       << circleOne.getDistance(circleTwo) << '\n';

  // Check if circle one intersects circle two
  if (circleOne.intersects(circleTwo)) {
    cout << "The circles do intersect\n";
  } else {
    cout << "The circles do not intersect\n";
  }

  // Create circleThree using the resize function on circleTwo
  Circle circleThree = circleTwo.resize(10);

  // Display circleThree
  cout << "Third Circle created" << circleThree.toString();

  // Move circleThree to (4,5)
  circleThree.moveTo(4, 5);

  // Display circleThree again
  cout << "Moved circle Three - " << circleThree.toString();

  // Check if circle two intersects with circle three
  if (circleTwo.intersects(circleThree)) {
    cout << "The circles Second and Third do intersect\n";
  } else {
    cout << "The circles Second and Third do not intersect\n";
  }

  // Create a fourth circle
  Circle circleFour(4, 5, 1);
  cout << "Fourth Circle created" << circleFour.toString();

  // Check if circle four intersects circle one
  if (circleFour.intersects(circleOne)) {
    cout << "The circles First and Fourth do intersect\n";
  } else {
    cout << "The circles First and Fourth do not intersect\n";
  }

  // Resize circle three
  circleThree.resize(9.5);
  cout << "Resized circle Three - " << circleThree.toString();
  return 0;
}
