#include <algorithm>
#include <numeric>

#include "VectorHeader.h"

// populate the vector with VECTOR_SIZE number of random integers of value
// between 1 and 100 pass by ref ensures vector is returned with values to
// calling program
using std::accumulate, std::cout, std::reverse, std::sort, std::vector;

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
void removeLowest(vector<int> &numbers) { numbers.erase(numbers.begin()); }

// display the calculated average of the values
void displayResults(double value) {
  cout << "The average is " << value << '\n';
}

// calculate the average of the vector contents
double calculateAverage(vector<int> numbers) {
  double sum = accumulate(numbers.begin(), numbers.end(), 0);
  // return the value
  return sum / 10.0;
}
