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
  // default constructor
  MagicalCreatures();
  // custom constructor
  MagicalCreatures(std::string name, std::string color, std::string type,
                   int age);
  // talk method: what does a magical creature say
  std::string talk();
  // live in function: where does a magical creature live
  std::string liveIn();
  // returns string representation of the magical creature
  // ie. all its attributes: see program output for format
  std::string toString();
  // getters and setters for each attribute
  std::string getName();
  void setName(std::string name);
  std::string getColor();
  void setColor(std::string color);
  int getAge();
  void setAge(int age);
  std::string getType();
  void setType(std::string type);
};

#endif
