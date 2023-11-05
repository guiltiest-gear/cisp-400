#ifndef Dragon_h
#define Dragon_h

#include <string>

#include "MagicalCreatures.h"

class Dragon : public MagicalCreatures {
 private:
  int size;
  bool hasSpike;

 public:
  Dragon();
  Dragon(std::string name, std::string color, std::string type, int age,
         int size, bool hasSpike);

  int getSize();
  void changeSize(int newSize);
  bool getHasSpike();
  void setHasSpike(bool hasSpike);
  std::string toString();
};

#endif
