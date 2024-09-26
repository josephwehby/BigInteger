#include "BigInteger.hpp"

BigInt::BigInt(int n) {
  if (n < 0) {
    isNegative = true;
  } else {
    isNegative = false;
  }
  
  while (n > 0) {
    int digit = n%10;
    digits.push_back(digit);
    n = n/10;
  }

}

BigInt::BigInt(const std::string& n) {

  if (n[0] == '-') {
    isNegative = true;
  } else {
    isNegative = false;
  }
  
  if (isNegative) {
    digits.resize(n.length() - 1);
  } else {
    digits.resize(n.length());
  }

  for (unsigned int i = 0; i < n.length(); i++) {
    char digit = n[i];

    if (digit == '-') continue;
    
    if (isdigit(digit)) {
      digits[n.length()-i-1] = (static_cast<uint8_t>(digit - '0'));
    } else {
      throw std::invalid_argument("A character in the string is not a number.");
    }
  }
}

std::ostream& operator<<(std::ostream& os, const BigInt& b) {
  for (auto it = b.digits.rbegin(); it != b.digits.rend(); it++) {
    os << static_cast<int>(*it);
  }

  return os;
}
