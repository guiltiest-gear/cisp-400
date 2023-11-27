#include "Dragon.h"

#include "MagicalCreatures.h"

using std::string;

Dragon::Dragon() {
  size = 0;
  hasSpike = true;
}

// constructor using member initializtion list
Dragon::Dragon(string name, string color, string type, int age, int size,
               bool hasSpike)
    : MagicalCreatures(name, color, type, age) {
  this->size = size;
  this->hasSpike = hasSpike;
}

int Dragon::getSize() { return size; }

void Dragon::changeSize(int newSize) { this->size = newSize; }

bool Dragon::getHasSpike() { return hasSpike; }

void Dragon::setHasSpike(bool hasSpike) { this->hasSpike = hasSpike; }

string Dragon::toString() { return "I am a Dragon! I breathe fire"; }
