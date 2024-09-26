#pragma once

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BigInt {
  public:
      BigInt(const int&);
      BigInt(const std::string&);
      friend std::ostream& operator<<(std::ostream&, const BigInt&);
  private:  
    std::vector<uint8_t> digits;
    bool isNegative;
    uint32_t size;
};

namespace BigIntegerMath {
  BigInt add(const BigInt& a, const BigInt& b);
  BigInt add(const BigInt& a, const BigInt& b);
}
