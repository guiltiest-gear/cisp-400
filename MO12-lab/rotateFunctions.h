#pragma once
#include <iomanip>
#include <iostream>
#include <vector>

// function to rotate data one to the left
template <typename T>
void rotateLeft(std::vector<T> &v) {
  // Take the first value and push it back
  v.push_back(v.at(0));
  // Delete the first value
  v.erase(v.begin());
}

// Function to output data
template <typename T>
void output(std::vector<T> v) {
  // Fix the precision
  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(2);
  // Get the length of the vector
  unsigned int length = v.size();
  for (unsigned int i = 0; i < length; i++)
    std::cout << std::left << std::setw(9) << v.at(i);
  std::cout << '\n';
}
