#ifndef VECTORHEADER_H
#define VECTORHEADER_H

#include <algorithm>  // for vector libraries
#include <cstdlib>    // for random number
#include <ctime>      // for seeding random number
#include <iomanip>    // for formatting output
#include <iostream>   // for console output
#include <vector>

// The contents of the vector can have values from 1 to MAX_VALUE.
// Use random number with this constant to generate values
const int MAX_VALUE = 100;

const int VECTOR_SIZE = 10;  // size - ie number of vector elements

// populate the vector with VECTOR_SIZE number of random integers of value
// between 1 and 100 pass by ref ensures vector is returned with values to
// calling program
void initializeVector(std::vector<int> &numbers);

// use the vector and algorithm library to sort this vector database
void sortVector(std::vector<int> &numbers);

// use the vector and algorithm library to reverse this vector database
void reverseVector(std::vector<int> &numbers);

// display the vector contents by iterating through the vector
void displayVector(std::vector<int> numbers);

// remove the number with the least value
void removeLowest(std::vector<int> &numbers);

// display the calculated average of the values
void displayResults(double value);

// calculate the average of the vector contents
double calculateAverage(std::vector<int> numbers);
#endif  // !VECTORHEADER_H
