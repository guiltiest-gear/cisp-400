#ifndef Goblin_h
#define Goblin_h

#include <string>

#include "MagicalCreatures.h"

// Goblin Class
class Goblin : public MagicalCreatures {
 public:
  Goblin();
  Goblin(std::string name, std::string color, std::string type, int age);
  std::string talk();
  // void toString();
};

#endif
