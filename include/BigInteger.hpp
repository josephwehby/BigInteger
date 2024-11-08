#pragma once

#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


class BigInt {
  public:
    BigInt();
    BigInt(int);
    BigInt(const std::string&);
    BigInt(const std::vector<uint8_t>&);
    std::vector<uint8_t> ToBytes();
    BigInt operator+(const BigInt&) const;
    BigInt operator-() const;
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
    static BigInt Pow(const BigInt&, const BigInt&);
    static BigInt ModPow(const BigInt&, const BigInt&, const BigInt&);
    static bool isEven(const BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);
  private:
    static BigInt BigIntInit(unsigned int);
    void Cleanup();
    BigInt AddAbsolute(const BigInt&) const;
    BigInt SubtractAbsolute(const BigInt&, bool) const;
    int CompareAbsolute(const BigInt&) const;
    std::vector<uint8_t> digits;
    bool isNegative;
    uint32_t size;
};
