#ifndef Genie_h
#define Genie_h

#include "MagicalCreatures.h"

// Genie Class
class Genie : public MagicalCreatures {
 private:
  bool hasWand;
  int size;

 public:
  // Regular constructor
  Genie(std::string name, std::string color, std::string type, int age,
        int size, bool hasWand);
  std::string liveIn();
  int getSize();
  int changeSize(int newSize);
  bool getHasWand();
  void setHasWand(bool hasWand);
};

#endif
