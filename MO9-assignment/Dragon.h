#ifndef Dragon_h
#define Dragon_h

#include "MagicalCreatures.h"

class Dragon : public MagicalCreatures {
 private:
  bool hasSpikes;
  int size;

 public:
  // Regular constructor
  Dragon(std::string name, std::string color, std::string type, int age,
         int size, bool hasSpikes);
  int getSize();
  void changeSize(int newSize);
  bool getHasSpike();
  void setHasSpike(bool hasSpike);
  std::string toString();
};

#endif
