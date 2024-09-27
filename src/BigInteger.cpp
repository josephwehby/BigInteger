#include "BigInteger.hpp"

std::ostream& operator<<(std::ostream& os, const BigInt& a) {
  if (a.isNegative) {
    os << '-';
  }

  for (auto it = a.digits.rbegin(); it != a.digits.rend(); it++) {
    os << static_cast<char>(*it+'0');
  }

  return os;
}

BigInt bigintmath::BigIntFromInt(int n) {
  BigInt bigint;

  if (n < 0) {
    bigint.isNegative = true;
  } else {
    bigint.isNegative = false;
  }
   
  while (n > 0) {
    int digit = n%10;
    bigint.digits.push_back(digit);
    n = n/10;
    bigint.size++;
  }

  return bigint;
}

BigInt bigintmath::BigIntFromString(const std::string& n) {
  BigInt bigint;

  if (n[0] == '-') {
    bigint.isNegative = true;
  } else {
    bigint.isNegative = false;
  }
  
  if (bigint.isNegative) {
    bigint.digits.resize(n.length() - 1);
  } else {
    bigint.digits.resize(n.length());
  }
  
  bigint.size = bigint.digits.size();

  for (unsigned int i = 0; i < n.length(); i++) {
    char digit = n[i];

    if (digit == '-') continue;
    
    if (isdigit(digit)) {
      bigint.digits[n.length()-i-1] = (static_cast<uint8_t>(digit - '0'));
    } else {
      throw std::invalid_argument("A character in the string is not a number.");
    }
  }

  return bigint;
}


BigInt bigintmath::Add(const BigInt& a, const BigInt& b) {
  BigInt result;
  const BigInt* min;
  const BigInt* max;

  if (a.size < b.size) {
    min = &a;
    max = &b;
  } else {
    min = &b;
    max = &a;
  }

  result.digits.resize(max->size, 0);
  
  uint8_t carry = 0;
  uint8_t sum = 0;  

  for (unsigned int i = 0; i < min->size; i++) {
    sum = min->digits[i] + max->digits[i] + carry;
    result.digits[i] = sum % 10;
    carry = sum / 10;
  }

  for (unsigned int j = min->size; j < max->size; j++) {
    sum = max->digits[j] + carry;
    result.digits[j] = sum % 10;
    carry = sum / 10; 
  }

  if (carry > 0) result.digits.push_back(carry);

  return result;
}
