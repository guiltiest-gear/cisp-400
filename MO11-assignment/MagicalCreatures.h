#ifndef MagicalCreatures_h
#define MagicalCreatures_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// MagicalCreatures Class
class MagicalCreatures {
 private:
  std::string name, color, type;
  int age;

 public:
  MagicalCreatures();
  MagicalCreatures(std::string name, std::string color, std::string type,
                   int age);
  virtual std::string talk();
  virtual std::string liveIn();
  std::string getName();
  void setName(std::string name);
  std::string getColor();
  void setColor(std::string color);
  int getAge();
  void setAge(int age);
  std::string getType();
  void setType(std::string type);
  virtual std::string toString();
};

#endif
