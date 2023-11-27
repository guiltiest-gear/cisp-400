#include <iostream>

#include "CircleHeader.h"

using std::cout;

int main() {
  // Declare and init circleOne and circleTwo
  Circle circleOne, circleTwo(0, 0, 4);
  // Display the circles
  cout << "Created circleOne " << circleOne.toString() << "Created circleTwo "
       << circleTwo.toString();
  // Declare and init circleThree
  Circle circleThree(-2, -9, 6);
  cout << "Created circleThree " << circleThree.toString();
  // Display the areas and circumferences
  cout << "The area of circleOne is " << circleOne.getArea()
       << " and its circumference is " << circleOne.getCircumference() << '\n';

  cout << "The area of circleTwo is " << circleTwo.getArea()
       << " and its circumference is " << circleTwo.getCircumference() << '\n';

  cout << "The area of circleThree is " << circleThree.getArea()
       << " and its circumference is " << circleThree.getCircumference()
       << '\n';
  return 0;
}
