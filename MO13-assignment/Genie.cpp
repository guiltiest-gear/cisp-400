#include "Genie.h"

#include "MagicalCreatures.h"

using std::string;

Genie::Genie() {
  size = 0;
  hasWand = true;
}

// constructor using member initializtion list
Genie::Genie(std::string name, string color, string type, int age, int size,
             bool hasWand)
    : MagicalCreatures(name, color, type, age) {
  this->size = size;
  this->hasWand = hasWand;
}

string Genie::liveIn() { return "I live in a bottle "; }

int Genie::getSize() { return size; }

void Genie::changeSize(int newSize) { this->size = newSize; }

bool Genie::getHasWand() { return hasWand; }

void Genie::setHasWand(bool hasWand) { this->hasWand = hasWand; }
