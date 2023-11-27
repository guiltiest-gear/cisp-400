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
  virtual std::string getName();
  virtual void setName(std::string name);
  virtual std::string getColor();
  virtual void setColor(std::string color);
  virtual int getAge();
  virtual void setAge(int age);
  virtual std::string getType();
  virtual void setType(std::string type);
  virtual std::string toString();
  bool operator==(MagicalCreatures other);
  bool operator>(MagicalCreatures other);
};

#endif
