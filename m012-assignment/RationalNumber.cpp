#include "RationalNumber.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "OutOfRange.h"

using std::cout, std::endl, std::string, std::to_string;

RationalNumber::RationalNumber(int n, int d) {
  // constructor..here is where the try catch comes in
  //  assign numerator and denominator and do the reduction
  try {
    if (d == 0)
      throw OutOfRange(99);
    else if (d < 0)
      throw OutOfRange(100);
  } catch (OutOfRange::DivByZero ex) {
    cout << "Division by Zero Error " << ex.exNum << endl;
    // exit(0);
  } catch (OutOfRange::NegativeDenom ex) {
    cout << "Negative Denominator Error " << ex.exNum << endl;
    // exit(0);
  }
  {
    numerator = n;
    denominator = d;
    reduction();
  }
}

string RationalNumber::toString() {
  return to_string(numerator) + "/" + to_string(denominator);
}

RationalNumber RationalNumber::addition(
    const RationalNumber &a) {  // this code is given to you, use this to
                                // complete other operatations
  RationalNumber t;

  t.numerator = a.numerator * denominator;
  t.numerator += a.denominator * numerator;
  t.denominator = a.denominator * denominator;
  t.reduction();

  return t;
}

RationalNumber RationalNumber::subtraction(const RationalNumber &s) {
  // complete this
  RationalNumber t;

  t.numerator = s.numerator * denominator;
  t.numerator = numerator * s.denominator - t.numerator;
  t.denominator = s.denominator * denominator;
  t.reduction();

  return t;
}

RationalNumber RationalNumber::multiplication(const RationalNumber &m) {
  // complete this
  RationalNumber t;

  t.numerator = m.numerator * numerator;
  t.denominator = m.denominator * denominator;
  t.reduction();

  return t;
}

RationalNumber RationalNumber::division(RationalNumber &v) {
  // complete this
  RationalNumber t;

  if (v.numerator != 0) {
    t.numerator = v.denominator * numerator;
    t.denominator = v.numerator * denominator;
    t.reduction();
  } else {
    cout << "Divide by zero error: terminating program\n";
    exit(1);
  }

  return t;
}

RationalNumber RationalNumber::operator+(const RationalNumber &a) {
  // this code which overloads the + operator is given to you
  // use it to complete other overloaded operators
  RationalNumber sum;

  sum.numerator = numerator * a.denominator + denominator * a.numerator;
  sum.denominator = denominator * a.denominator;
  sum.reduction();
  return sum;
}

RationalNumber RationalNumber::operator-(const RationalNumber &s) {
  RationalNumber difference;

  difference.numerator = numerator * s.denominator - denominator * s.numerator;
  difference.denominator = denominator * s.denominator;
  difference.reduction();
  return difference;
}

RationalNumber RationalNumber::operator*(const RationalNumber &m) {
  RationalNumber product;

  product.numerator = numerator * m.numerator;
  product.denominator = denominator * m.denominator;
  product.reduction();
  return product;
}

RationalNumber RationalNumber::operator/(RationalNumber &d) {
  // this code is given to you please inspect it to see why its written this way
  RationalNumber divide;

  if (d.numerator != 0) {  // check for a zero in numerator
    divide.numerator = numerator * d.denominator;
    divide.denominator = denominator * d.numerator;
    divide.reduction();
    // cout<<"In divide "<<divide.toStringRationalNumber();

  } else {
    cout << "Divide by zero error: terminating program\n";
    exit(1);  // stdlib function
  }

  return divide;
}

bool RationalNumber::operator>(const RationalNumber &gr) const {
  // this code is given to you

  if (static_cast<double>(numerator) / denominator >
      static_cast<double>(gr.numerator) / gr.denominator)
    return true;
  else
    return false;
}

bool RationalNumber::operator<(const RationalNumber &lr) const {
  if (static_cast<double>(numerator) / denominator <
      static_cast<double>(lr.numerator) / lr.denominator)
    return true;
  else
    return false;
}

bool RationalNumber::operator>=(
    const RationalNumber &ger) const {  // code is givento you
  return *this == ger || *this > ger;
}

bool RationalNumber::operator<=(
    const RationalNumber &ler) const {  // complete this
  return *this == ler || *this < ler;
}

bool RationalNumber::operator==(const RationalNumber &er) const {
  // complete this
  // HACK: Using a bitwise XOR definitely works, but I probably wouldn't ever do
  // this again
  if (this->numerator ^ er.numerator && this->denominator ^ er.denominator)
    // We should get a 0 if both numbers are the same, if not, then they're
    // different
    return false;
  else
    return true;
}

bool RationalNumber::operator!=(
    const RationalNumber &ner) const {  // given to you

  return !(*this == ner);
}

std::string RationalNumber::toStringRationalNumber() const {
  // given to you

  if (numerator == 0)  // print fraction as zero
    // cout << numerator;
    return to_string(numerator);
  else if (denominator == 1)  // print fraction as integer
    return to_string(numerator);
  // cout << numerator;
  else
    // cout << numerator << '/' << denominator;
    return to_string(numerator) + "/" + to_string(denominator);
}
std::string RationalNumber::toStringRationalNumberAsDouble() const {
  // given to you
  return to_string(numerator * 1.0 / denominator);
}
void RationalNumber::reduction(void) {
  // given to you
  int largest, gcd = 1;  // greatest common divisor;

  largest = (numerator > denominator) ? numerator : denominator;

  for (int loop = 2; loop <= largest; ++loop)
    if (numerator % loop == 0 && denominator % loop == 0) gcd = loop;

  numerator /= gcd;
  denominator /= gcd;
  // cout<<"In reduction "<<numerator <<" "<<denominator<<endl;
}
