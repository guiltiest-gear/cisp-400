#include <iostream>
#include <vector>

#include "CircleHeader.h"

using std::cout, std::vector;

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

  // Clear the vector
  cout << "Erasing the vector of circles\n";
  circleVector.clear();

  // Create a circle named c and push it to the vector
  cout << "Creating a new circle\n";
  // Create using default constructor
  Circle c;
  // Push it back into the vector
  circleVector.push_back(c);

  // Display the number of circles using getCount
  cout << "The number of circles, using getCount method is "
       << Circle::getCount() << '\n';

  // Do the same thing but with the length of the array
  cout << "The number of circles, using the vector size method is "
       << circleVector.size() << '\n';

  return 0;
}
