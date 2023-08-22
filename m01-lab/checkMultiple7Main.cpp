// Program    : CheckMultiple7Main.cpp
// Author     : Jade Fox
// Due Date   : August 27, 2023
// Description: Write a program that determines if an integer is a multiple of 7
//              The program should prompt the user to enter an integer,
//              determine if it is a multiple of 7 by using a given formula and
//              output the result.

#include <iostream>

#include "checkMultipleHeader.h"

int main() {
  int number = inputNumber();
  displayResults(number, checkMultiple7(number));
  return 0;
}
