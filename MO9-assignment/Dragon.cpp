#include "Dragon.h"

#include "MagicalCreatures.h"

using std::string;

// Regular constructor
Dragon::Dragon(string name, string color, string type, int age, int size,
               bool hasSpikes) {
  Dragon::setName(name);
  Dragon::setColor(color);
  Dragon::setType(type);
  Dragon::setAge(age);
  Dragon::setHasSpike(hasSpikes);
  Dragon::changeSize(size);
}

// Setters
void Dragon::setHasSpike(bool hasSpikes) { this->hasSpikes = hasSpikes; }
void Dragon::changeSize(int newSize) { size = newSize; }

// Getters
int Dragon::getSize() { return size; }
bool Dragon::getHasSpike() { return hasSpikes; }
string Dragon::toString() { return "I am a Dragon, I breathe fire!"; }
