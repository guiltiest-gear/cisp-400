#include <algorithm>
#include <iostream>
#include <vector>

#include "CircleHeader.h"

using std::cout, std::vector, std::remove_if;

int main() {
  // Declare a vector to hold the circles
  vector<Circle> circleVector;

  // Open the file and push the data into the vector
  inputData(circleVector, "dataLab4.txt");

  // Display the created circles
  // Generate an iterator
  vector<Circle>::iterator it;
  cout << "The circles created are:\n";
  // Range based for loop for vector
  for (it = circleVector.begin(); it != circleVector.end(); it++)
    cout << it->toString();

  // Display the number of circles using getCount
  cout << "The number of circles, using getCount method is "
       << Circle::getCount() << '\n';

  // Do the same thing but with the length of the array
  cout << "The number of circles, using the vector size method is "
       << circleVector.size() << '\n';

  // Open DataLab5A.txt and push to vector
  inputData(circleVector, "dataLab5.txt");

  // Erase any elements with a radius greater than 8
  auto remove_circle =
      remove_if(circleVector.begin(), circleVector.end(),
                // Lambda to check if radius is greater than 8
                [](Circle circle) -> bool { return (circle.getRadius() > 8); });
  // Remove any circles marked to be removed by the remove_if function
  circleVector.erase(remove_circle, circleVector.end());

  // Display the numbers of circles remaining using the vector size method
  cout << "The numbers of circles remaining is " << circleVector.size() << '\n';

  // Display the remaining circles
  cout << "The circles left are: \n";
  for (it = circleVector.begin(); it != circleVector.end(); it++)
    cout << it->toString();

  // Create two circle objects
  Circle circle1(3, 4, 7), circle2(-2, -4, 4);

  // Insert the circles at position 2 and 3
  circleVector.insert(circleVector.begin() + 2, circle1);
  circleVector.insert(circleVector.begin() + 3, circle2);

  // Display the vector if circles
  cout << "The circles created are:\n";
  for (it = circleVector.begin(); it != circleVector.end(); it++)
    cout << it->toString();

  return 0;
}
