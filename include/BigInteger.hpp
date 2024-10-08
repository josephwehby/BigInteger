#pragma once

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct BigInt {
  std::vector<uint8_t> digits;
  bool isNegative;
  uint32_t size;

  friend std::ostream& operator<<(std::ostream&, const BigInt&);
};
 
namespace bigintmath {
  BigInt BigIntFromString(const std::string&);
  BigInt BigIntFromInt(int);
  int Compare(const BigInt& a, const BigInt& b);
  BigInt Add(const BigInt& a, const BigInt& b);
  BigInt Subtract(const BigInt& a, const BigInt& b);
  BigInt Multiply(const BigInt& a, const BigInt& b);
}
