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
