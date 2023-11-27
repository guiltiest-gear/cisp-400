#include "Goblin.h"

#include "MagicalCreatures.h"

using std::string;

// Regular constructor
Goblin::Goblin(string name, string color, string type, int age) {
  Goblin::setName(name);
  Goblin::setColor(color);
  Goblin::setType(type);
  Goblin::setAge(age);
}

string Goblin::talk() { return "I talk Gibberish"; }
