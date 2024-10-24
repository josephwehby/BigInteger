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
  bool isOne(const BigInt& a);
  bool isEven(const BigInt& a);
  bool gtZero(const BigInt& a);
  BigInt Add(const BigInt& a, const BigInt& b);
  BigInt Subtract(const BigInt& a, const BigInt& b);
  BigInt Multiply(const BigInt& a, const BigInt& b);
  BigInt Divide(const BigInt& a, const BigInt& b);
  BigInt Mod(const BigInt& a, const BigInt& b);
  BigInt Pow(const BigInt& a, const BigInt& power);
  BigInt ModPow(const BigInt& a, const BigInt& b, const BigInt& c);
  BigInt RightShift(const BigInt& a);
  BigInt LeftShift(const BigInt& a);
}

class BigInt {
  public:
    BigInt(int);
    BigInt(const std::string&);
    BigInt(const std::vector<uint8_t>&);
    BigInt operator+(const BigInt&) const;
    BigInt operator-(const BigInt&) const;
    BigInt operator*(const BigInt&) const;
    BigInt operator/(const BigInt&) const;
    BigInt operator%(const BigInt&) const;
    BigInt operator<<(unsigned int) const;
    BigInt operator>>(unsigned int) const;
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator>=(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator==(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    static BigInt Pow(const BigInt&);
    static BigInt ModPow(const BigInt&, const BigInt&, const BigInt&);
    
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
  private:
    BigInt AddAbsolute(const BigInt&);
    BigInt SubtractAbsolute(const BigInt&);
    BigInt BigIntInit(unsigned int);
    std::vector<uint8_t> digits;
    bool isNegative;
    uint32_t size;
};
