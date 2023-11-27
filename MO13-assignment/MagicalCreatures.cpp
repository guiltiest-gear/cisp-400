#include "MagicalCreatures.h"

using std::string, std::to_string;

MagicalCreatures::MagicalCreatures() {
  name = "null";
  color = "null";
  type = "null";
  age = 0;
}

MagicalCreatures::MagicalCreatures(string name, string color, string type,
                                   int age) {
  this->name = name;
  this->color = color;
  this->type = type;
  this->age = age;
}

string MagicalCreatures::talk() { return "Magical Creature is talking."; }

string MagicalCreatures::liveIn() { return "Magical Creature lives anywhere."; }

string MagicalCreatures::getName() { return name; }

void MagicalCreatures::setName(string name) { this->name = name; }

string MagicalCreatures::getColor() { return color; }

void MagicalCreatures::setColor(string color) { this->color = color; }

int MagicalCreatures::getAge() { return age; }

void MagicalCreatures::setAge(int age) { this->age = age; }

string MagicalCreatures::getType() { return type; }

void MagicalCreatures::setType(string type) { this->type = type; }
string MagicalCreatures::toString() {
  string value = "I am a Magical creature ";
  value = value.append("\nName    : ");
  value = value.append(name);
  value = value.append("\nType    : ");
  value = value.append(type);
  value = value.append("\nColor   : ");
  value = value.append(color);
  value = value.append("\nAge     : ");
  value = value.append(to_string(age));
  return value;
}

bool MagicalCreatures::operator==(MagicalCreatures other) {
  // Attempt a comparison across private attributes, if all match, return true,
  // otherwise return false
  if (this->getAge() ^ other.getAge())
    // If we get 0, the ages are the same, if not, they're different
    return false;
  else if (this->getName() != other.getName())
    // We have to use != because we're overloading ==
    // If they don't equal each other, return false
    return false;
  else if (this->getColor() != other.getColor())
    return false;
  else if (this->getType() != other.getType())
    return false;
  else  // If all the tests pass, the objects must be equal
    return true;
}

bool MagicalCreatures::operator>(MagicalCreatures other) {
  if (*this == other)
    return false;
  else if (this->getAge() < other.getAge())
    return false;
  else if (this->getName() < other.getName())
    return false;
  else if (this->getColor() < other.getColor())
    return false;
  else if (this->getType() < other.getColor())
    return false;
  else
    return true;
}
