#include "Elf.h"

using std::string;

#include "MagicalCreatures.h"

Elf::Elf() {}

// constructor using member initializtion list
Elf::Elf(string name, string color, string type, int age)
    : MagicalCreatures(name, color, type, age) {}

string Elf::toString() { return "I am an Elf.... I can spell"; }
