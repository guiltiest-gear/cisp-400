#ifndef Elf_h
#define Elf_h

#include <string>

#include "MagicalCreatures.h"

// Elf Class
class Elf : public MagicalCreatures {
 public:
  Elf();
  Elf(std::string name, std::string color, std::string type, int age);
  std::string toString();
};

#endif
