#include "Genie.h"

#include "MagicalCreatures.h"

using std::string;

// Regular constructor
Genie::Genie(string name, string color, string type, int age, int size,
             bool hasWand) {
  this->hasWand = hasWand;
  this->size = size;
  Genie::setName(name);
  Genie::setColor(color);
  Genie::setType(type);
  Genie::setAge(age);
}

// Getters
int Genie::getSize() { return size; }
bool Genie::getHasWand() { return hasWand; }

// Setters
void Genie::setHasWand(bool hasWand) { this->hasWand = hasWand; }
int Genie::changeSize(int newSize) {
  // Do not allow negative sizes
  if (newSize < 0) return -1;
  this->size = newSize;
  return 0;
}

string Genie::liveIn() { return "I live in a bottle"; }
