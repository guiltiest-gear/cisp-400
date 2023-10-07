#ifndef PAINTING_H
#define PAINTING_H

#include <fstream>
#include <memory>
// #include <sstream>
#include <string>
#include <vector>

#include "CircleHeader.h"

class Painting {
 private:
  std::vector<std::shared_ptr<Circle>> paintingVector;

 public:
  Painting();
  explicit Painting(std::string);
  // ifstream inputFile(filename);

  // try to remove const and see what happens
  std::shared_ptr<Circle> getCircle(int) const;
  // try to remove const and see what happens
  int getSize() const;

  // copy constructor for the Painting class
  Painting(Painting const &);

  // return a string of the painting
  std::string toString();

  void setRadius(int, int);
};

#endif  // !PAINTING_H
