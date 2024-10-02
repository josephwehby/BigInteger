#include "BigInteger.hpp"

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


// anonymous namespace functions
namespace {
  
  BigInt BigIntInit(unsigned int size) {
    BigInt bigint;
    bigint.digits.resize(size);
    bigint.isNegative = false;
    bigint.size = static_cast<uint32_t>(size);
    return bigint;
  }

  BigInt AddAbsolute(const BigInt& a, const BigInt& b) {
    const BigInt* min;
    const BigInt* max;

    if (a.size < b.size) {
      min = &a;
      max = &b;
    } else {
      min = &b;
      max = &a;
    }

    BigInt result = BigIntInit(max->size);

    uint8_t carry = 0;
    uint8_t sum = 0;  

    for (unsigned int i = 0; i < max->size; i++) {
      uint8_t min_digit = (i < min->size) ? min->digits[i] : 0;
      uint8_t max_digit = max->digits[i];
      sum = min_digit + max_digit + carry;
      result.digits[i] = sum % 10;
      carry = sum / 10;
    }

    if (carry > 0) result.digits.push_back(carry);

    return result;
  }

  BigInt SubtractAbsolute(const BigInt& a, const BigInt& b) {
    BigInt result = BigIntInit(a.size);

    uint8_t borrow = 0;
    int minuend = 0;

    for (unsigned int i = 0; i < a.size; i++) {
      uint8_t min_digit = (i < b.size) ? b.digits[i] : 0;
      uint8_t max_digit = a.digits[i];
      
      minuend = max_digit - min_digit - borrow;
      if (minuend < 0) {
        minuend += 10; 
        borrow = 1;
      } else {
        borrow = 0;
      }
      result.digits[i] = static_cast<uint8_t>(minuend);
    }
    
    while (result.size > 1 && result.digits.back() == 0) {
      result.digits.pop_back();
      result.size--;
    }

    return result;
  }

}

// all the bigintmath namespace functions
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
  if (a.isNegative == b.isNegative) {
    BigInt result = AddAbsolute(a, b);
    result.isNegative = a.isNegative;
    return result;
  }

  BigInt r;
  return r;

}

// a - b
BigInt bigintmath::Subtract(const BigInt& a, const BigInt& b) {
  BigInt r = SubtractAbsolute(a, b);
  return r;
}
