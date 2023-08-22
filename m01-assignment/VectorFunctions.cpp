// Name       : Jade Fox
// ID         : 1722385
// Program    : VectorFunctions.cpp
// Date       : 8-22-2023
// Description: Do the following:
// 1. Declare a vector of integers of VECTOR_SIZE (=10) and each number ranges
// between 1 and MAX_VALUE (=100)
// 2. Populates the vector with random integers between the above values
// 3. Sorts the vector in ascending order using the sort function available in
// the algorithm library
// 4. Displays the vector- use iterators to traverse the vector for display
// 5. Reverses the vector in ascending order using the sort function available
// 6. Displays the reversed vector
// 7. Removes the vector element with least value
// 8. Displays the reduced vector
// 9. Calculates the average of the remaining vector values
// 10. Display the results in a formatted way using 2 decimal places
#include <algorithm>
#include <iomanip>
#include <numeric>

#include "VectorHeader.h"

using std::accumulate, std::cout, std::reverse, std::sort, std::vector,
    std::setprecision, std::fixed, std::showpoint;
// populate the vector with VECTOR_SIZE number of random integers of value
// between 1 and 100 pass by ref ensures vector is returned with values to
// calling program

void initializeVector(vector<int> &numbers) {
  // seed the random number
  srand(time(0));
  // put this in a loop to populate the vector with VECTOR_SIZE (ie 10) number
  // of values
  for (int i = 0; i < 10; i++) {
    // returns random numbers between 1 and 100;
    int randomNumber = rand() % MAX_VALUE + 1;
    numbers.push_back(randomNumber);
  }
}

// use sort on this vector database from the begining to the end. Use
// iterators
void sortVector(vector<int> &numbers) { sort(numbers.begin(), numbers.end()); }

// reverse this vector database
void reverseVector(vector<int> &numbers) {
  reverse(numbers.begin(), numbers.end());
}

// display the vector contents by iterating through the vector
void displayVector(vector<int> numbers) {
  for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
    cout << *iter << " ";
  }
  // Put a newline at the end to make viewing the average easier
  cout << '\n';
}

// remove the number with the least value
void removeLowest(vector<int> &numbers) { numbers.erase(numbers.end()); }

// display the calculated average of the values
void displayResults(double value) {
  // Fix standard output to show 2 points of precision
  cout << fixed << showpoint << setprecision(2);
  // Display the value
  cout << "The average is " << value << '\n';
}

// calculate the average of the vector contents
double calculateAverage(vector<int> numbers) {
  double sum = accumulate(numbers.begin(), numbers.end(), 0);
  // return the value
  return sum / 10.0;
}
