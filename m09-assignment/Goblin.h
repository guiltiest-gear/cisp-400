#ifndef Goblin_h
#define Goblin_h

#include <string>

#include "MagicalCreatures.h"

// Goblin Class
class Goblin : public MagicalCreatures {
 public:
  // Regular constructor
  Goblin(std::string name, std::string color, std::string type, int age);

  // Returns "I speak Gibberish"
  std::string talk();
};

#endif
