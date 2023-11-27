#include <iostream>

#include "Integer.h"
#include "OutOfRange.h"
#include "RationalNumber.h"

using std::cout;

template <class T>
void print(T obj) {
  cout << obj.toString() << '\n';
}

int main() {
  // int num, denom;
  // RationalNumber z1(1,0);
  // RationalNumber n(1,-1);
  // Integer n(77);
  RationalNumber c(7, 3), d(3, 9), x;
  // print(n);
  // print(c);

  cout << "The numbers are " << c.toStringRationalNumber() << " and "
       << d.toStringRationalNumber() << '\n';

  cout << "Operations using methods\n";
  cout << c.toStringRationalNumber();
  cout << " + ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c.addition(d);
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " - ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c.subtraction(d);
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " * ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c.multiplication(d);
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " / ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c.division(d);
  cout << x.toStringRationalNumber() << '\n';

  cout << "Operations using overloaded operators\n";
  cout << c.toStringRationalNumber();
  cout << " + ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c + d;
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " - ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c - d;
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " * ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c * d;
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " / ";
  cout << d.toStringRationalNumber();
  cout << " = ";
  x = c / d;
  cout << x.toStringRationalNumber();

  cout << '\n';
  cout << c.toStringRationalNumber();
  cout << " is:\n";

  cout << ((c > d) ? " > " : " <= ");
  cout << d.toStringRationalNumber();
  cout << " according to the overloaded > operator\n";

  cout << ((c < d) ? " < " : " >= ");
  cout << d.toStringRationalNumber();
  cout << " according to the overloaded < operator\n";

  // cout << ( ( c >= d ) ? " >= " : " < " );
  cout << "In decimal form is " << c.toStringRationalNumberAsDouble() << '\n';
  cout << "Trying with negative numbers\n";
  RationalNumber e(-7, 3), f(3, 9), y;

  cout << "The numbers are " << e.toStringRationalNumber() << " and "
       << f.toStringRationalNumber() << '\n';

  cout << "Operations using methods " << '\n';
  cout << e.toStringRationalNumber();
  cout << " + ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e.addition(f);
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " - ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e.subtraction(f);
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " * ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e.multiplication(f);
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " / ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e.division(f);
  cout << y.toStringRationalNumber() << '\n';

  cout << "Operations using overloaded operators\n";
  cout << e.toStringRationalNumber();
  cout << " + ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e + f;
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " - ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e - f;
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " * ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e * f;
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " / ";
  cout << f.toStringRationalNumber();
  cout << " = ";
  y = e / f;
  cout << y.toStringRationalNumber();

  cout << '\n';
  cout << e.toStringRationalNumber();
  cout << " is:\n";

  cout << ((e > f) ? " > " : " <= ");
  cout << f.toStringRationalNumber();
  cout << " according to the overloaded > operator\n";

  cout << ((e < f) ? " < " : " >= ");
  cout << f.toStringRationalNumber();
  cout << " according to the overloaded < operator\n";

  // cout << ( ( c >= d ) ? " >= " : " < " );
  cout << "In decimal form is " << e.toStringRationalNumberAsDouble() << '\n';

  cout << "Trying 0 denominator - with number 1/0\n";
  RationalNumber z(1, 0);
  cout << "Trying negative denominator - with number 1/-1\n";
  RationalNumber k(1, -1);
}
