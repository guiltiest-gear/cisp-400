#include "Elf.h"

#include "MagicalCreatures.h"

using std::string;

Elf::Elf() {}

// constructor using member initializtion list
Elf::Elf(string name, string color, string type, int age)
    : MagicalCreatures(name, color, type, age) {}
string Elf::toString() { return "I am an Elf.... I can spell"; }
