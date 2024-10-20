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
  BigInt BigIntFromBytes(const std::vector<uint8_t>&);
  int Compare(const BigInt& a, const BigInt& b);
  bool isZero(const BigInt& a);
  bool isEven(const BigInt& a);
  bool gtZero(const BigInt& a);
  BigInt Add(const BigInt& a, const BigInt& b);
  BigInt Subtract(const BigInt& a, const BigInt& b);
  BigInt Multiply(const BigInt& a, const BigInt& b);
  BigInt Divide(const BigInt& a, const BigInt& b);
  BigInt Mod(const BigInt& a, const BigInt& b);
  BigInt Pow(const BigInt& a, unsigned int power);
  BigInt ModPow(const BigInt& a, const BigInt& b, const BigInt& c);
  BigInt RightShift(const BigInt& a);
  BigInt LeftShift(const BigInt& a);
}
