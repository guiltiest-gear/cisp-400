#include "MagicalCreatures.h"

using std::string, std::to_string;

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

// Default constructor
MagicalCreatures::MagicalCreatures() {
  // Assign all of these the string null
  name = type = color = "null";
  // Set age to 0
  age = 0;
}

// Regular constructor
MagicalCreatures::MagicalCreatures(string name, string color, string type,
                                   int age) {
  // Assign the arguments to the input
  this->name = name;
  this->color = color;
  this->type = type;
  this->age = age;
}

// Getters
string MagicalCreatures::getName() { return name; }
string MagicalCreatures::getColor() { return color; }
string MagicalCreatures::getType() { return type; }
int MagicalCreatures::getAge() { return age; }

// Setters
void MagicalCreatures::setName(string name) { this->name = name; }
void MagicalCreatures::setType(string type) { this->type = type; }
void MagicalCreatures::setColor(string color) { this->color = color; }
void MagicalCreatures::setAge(int age) {
  if (age < 0) this->age = 0;
  this->age = age;
}

// talk method: what does this creature say
string MagicalCreatures::talk() { return "Magical Creature is talking."; }
string MagicalCreatures::liveIn() { return "Magical Creature lives anywhere."; }
