#include "Elf.h"

#include "MagicalCreatures.h"

using std::string;

// Regular constructor
Elf::Elf(string name, string color, string type, int age) {
  Elf::setName(name);
  Elf::setColor(color);
  Elf::setType(type);
  Elf::setAge(age);
}

string Elf::toString() { return "I am an Elf...I can spell"; }
