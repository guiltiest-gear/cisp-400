#ifndef Genie_h
#define Genie_h

#include <string>

#include "MagicalCreatures.h"

// Genie Class
class Genie : public MagicalCreatures {
 private:
  int size;
  bool hasWand;

 public:
  Genie();
  Genie(std::string name, std::string color, std::string type, int age,
        int size, bool hasWand);

  int getSize();
  void changeSize(int newSize);
  bool getHasWand();
  void setHasWand(bool hasWand);
  std::string liveIn();
  // void toString();
};

#endif
