#pragma once

#include <string>
class Integer {
  int n;

 public:
  explicit Integer(int i) { n = i; }
  int getInt() { return n; }
  void setInt(int i) { n = i; }
  std::string toString() { return std::to_string(n); }
};
