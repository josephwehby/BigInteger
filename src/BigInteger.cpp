#include "BigInteger.hpp"

BigInt::BigInt(int n) {
  if (n < 0) {
    isNegative = true;
    n *= -1;
  } else {
    isNegative = false;
  }
  
  size = 0;
  while (n > 0) {
    int digit = n%10;
    digits.push_back(digit);
    n = n/10;
    size++;
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
  
  size = digits.size();

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

bool BigInt::operator>(const BigInt& b) const {
  if (isNegative && !b.isNegative) return false;
  if (!isNegative && b.isNegative) return true;

  if (size != b.size) return (size > b.size) ? true : false;
  
  bool neg = sign || b.sign;
  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] > b.digits[i]) return (true && neg);
  }

  return false;
}

// overload the << opertor to print the biginteger
std::ostream& operator<<(std::ostream& os, const BigInt& a) {
  if (a.isNegative) {
    os << '-';
  }
  
  for (auto it = a.digits.rbegin(); it != a.digits.rend(); it++) {
    os << static_cast<char>(*it+'0');
  }
  
  return os;
}
