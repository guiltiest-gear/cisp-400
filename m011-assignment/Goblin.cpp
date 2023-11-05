#include "Goblin.h"

#include "MagicalCreatures.h"

using std::string;

Goblin::Goblin() {}

// constructor using member initializtion list
Goblin::Goblin(string name, string color, string type, int age)
    : MagicalCreatures(name, color, type, age) {}

string Goblin::talk() { return "I speak Gibberish"; }
