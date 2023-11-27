#pragma once

#include <string>

class RationalNumber {
 public:
  explicit RationalNumber(int = 0, int = 1);  // default constructor

  // default constructor
  RationalNumber addition(const RationalNumber&);
  RationalNumber subtraction(const RationalNumber&);
  RationalNumber multiplication(const RationalNumber&);
  RationalNumber division(RationalNumber&);
  std::string toString();
  std::string toStringRationalNumber() const;
  std::string toStringRationalNumberAsDouble() const;

  RationalNumber operator+(const RationalNumber&);
  RationalNumber operator-(const RationalNumber&);
  RationalNumber operator*(const RationalNumber&);
  RationalNumber operator/(RationalNumber&);
  bool operator>(const RationalNumber&) const;
  bool operator<(const RationalNumber&) const;
  bool operator>=(const RationalNumber&) const;
  bool operator<=(const RationalNumber&) const;
  bool operator==(const RationalNumber&) const;
  bool operator!=(const RationalNumber&) const;

 private:
  int numerator;
  int denominator;

  void reduction(void);
};
