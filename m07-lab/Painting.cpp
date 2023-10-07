#include "Painting.h"

#include <fstream>
#include <memory>
#include <sstream>

#include "CircleHeader.h"

using std::ifstream, std::cout, std::istringstream, std::make_shared,
    std::string, std::shared_ptr, std::shared_ptr, std::make_shared;

// regular constructor
Painting::Painting(string filename) {
  ifstream inputFile(filename);
  istringstream instream;
  string data;
  int count = 0;
  int x, y, radius;
  try {
    if (inputFile) {
      while (!inputFile.eof()) {
        getline(inputFile, data);
        istringstream instream(data);
        instream >> x;
        instream >> y;
        instream >> radius;
        shared_ptr<Circle> circle = make_shared<Circle>(x, y, radius);
        paintingVector.push_back(circle);
        count++;
      }
    } else {
      throw string("File Not Found");
    }
  } catch (string message) {
    cout << message << '\n';
    exit(1);
  }
}

// returns a circle at the given index in the painting vector
shared_ptr<Circle> Painting::getCircle(int index) const {
  return paintingVector.at(index);
}

// gets the size of the painting vector
int Painting::getSize() const { return paintingVector.size(); }

// copy constructor for the Painting Class
Painting::Painting(Painting const &other) {
  // copy individual circles from other to this painting
  // note that deep copy for these circles will need to be done since
  // the painting vector contains pointers to circles

  // this code will involves a for loop to traverse "other"
  //  make temporary pointer to circle which contains a copy of the current
  //  "other" circle
  // push this pointer onto the "this" painting vector
  for (int i = 0; i < other.getSize(); i++) {
    shared_ptr<Circle> tmp = make_shared<Circle>(
        other.paintingVector.at(i)->getX(), other.paintingVector.at(i)->getY(),
        other.paintingVector.at(i)->getRadius());
    this->paintingVector.push_back(tmp);
  }
}

// returns a string containing the painting vector
string Painting::toString() {
  // Init the string
  string paintingString;
  // Add the first bracket
  paintingString.append("[ ");
  // Loop through the vector and append the circles to the string
  for (int i = 0; i < Painting::getSize(); i++)
    paintingString.append(Painting::getCircle(i)->toString() + " ");

  // Tack on the closing bracket
  paintingString.append("]\n");
  // Return the string
  return paintingString;
}

void Painting::setRadius(int index, int radius) {
  paintingVector.at(index)->setRadius(radius);
}

// Default constructor
Painting::Painting() { ; }  // Do nothing
