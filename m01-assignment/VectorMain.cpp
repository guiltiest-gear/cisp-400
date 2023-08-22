#include "VectorHeader.h"

int main() {
  // declare a vector of integers
  std::vector<int> numbers;
  // populate the vector with VECTOR_SIZE number of random integers of value
  // between 1 and 100
  initializeVector(numbers);
  // use the vector and algorithm library to sort this vector database
  sortVector(numbers);
  // display the vector contents by iterating through the vector
  displayVector(numbers);
  // use the vector and algorithm library to reverse this vector database
  reverseVector(numbers);
  // display the vector contents by iterating through the vector
  displayVector(numbers);
  // remove the number with the least value
  removeLowest(numbers);
  // display the reduced vector contents by iterating through the vector
  displayVector(numbers);
  // calculate the average of the contents of the vector.
  displayResults(calculateAverage(numbers));
  return 0;
}
