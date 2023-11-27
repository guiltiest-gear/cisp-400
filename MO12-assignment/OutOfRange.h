#pragma once

class OutOfRange {
 private:
 public:
  explicit OutOfRange(int denom) {
    // check denom and throw the appropriate exceptions given belpw
    if (denom == 99) {
      throw DivByZero(99);
    } else if (denom == 100) {
      throw NegativeDenom(100);
    }
  }

 public:
  class DivByZero {
   public:
    int exNum;
    explicit DivByZero(int i) { exNum = i; }
  };
  class NegativeDenom {
   public:
    int exNum;
    explicit NegativeDenom(int i) { exNum = i; }
  };
};
