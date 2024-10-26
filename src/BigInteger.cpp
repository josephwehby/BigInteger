#include "BigInteger.hpp"

BigInt::BigInt() {
  size = 1;
  isNegative = false;
  digits.resize(1, 0);
}

BigInt::BigInt(int n) {
  if (n < 0) {
    isNegative = true;
    n *= -1;
  } else {
    isNegative = false;
  }
  
  size = 0;

  if (n == 0) {
    size++;
    digits.push_back(n);
  } else {
    while (n > 0) {
      int digit = n%10;
      digits.push_back(digit);
      n = n/10;
      size++;
    }
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

BigInt BigInt::operator+(const BigInt& b) const {
  BigInt result;

  if (isNegative == b.isNegative) {
    result = AddAbsolute(b);
    result.isNegative = isNegative;
    return result;
  }

  int compare = CompareAbsolute(b);
  bool sign = false;
  bool a_bigger = true;

  switch(compare) {
    case -1:
      sign = b.isNegative;
      a_bigger = false; 
      break;
    case 0:
      sign = false;
      break;
    case 1:
      sign = isNegative;
      break;
  }

  result = SubtractAbsolute(b, a_bigger);
  result.isNegative = sign;
  return result;
}

BigInt BigInt::operator-(const BigInt& b) const {
  BigInt result;
  if (!isNegative && !b.isNegative) {
    result = SubtractAbsolute(b, true);
    result.isNegative = (*this >= b) ? false : true;
  } 

  return result;
}

bool BigInt::operator<(const BigInt& b) const {
  if (isNegative && !b.isNegative) return true;
  if (!isNegative && b.isNegative) return false;

  if (size != b.size) {
    return isNegative ? (size > b.size) : (size < b.size);
  }

  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] != b.digits[i]) {
      return isNegative ? (digits[i] > b.digits[i]) : (digits[i] < b.digits[i]);
    }
  }

  return false;
}


bool BigInt::operator>(const BigInt& b) const {
  if (isNegative && !b.isNegative) return false;
  if (!isNegative && b.isNegative) return true;

  if (size != b.size) {
    return isNegative ? (size < b.size) : (size > b.size);
  }
  
  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] != b.digits[i]) {
      return isNegative ? (digits[i] < b.digits[i]) : (digits[i] > b.digits[i]);
    }
  }

  return false;
}

bool BigInt::operator>=(const BigInt& b) const {
  return (*this > b) || (*this == b);
}

bool BigInt::operator<=(const BigInt& b) const {
  return (*this < b) || (*this == b);
}

bool BigInt::operator==(const BigInt& b) const {
  if (size != b.size) return false;
  if(isNegative != b.isNegative) return false;

  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] != b.digits[i]) return false;
  }

  return true;
}

bool BigInt::operator!=(const BigInt& b) const {
  if (size != b.size) return true;
  if (isNegative != b.isNegative) return true;

  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] != b.digits[i]) return true;
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

// private methods

BigInt BigInt::BigIntInit(unsigned int size) {
  BigInt bigint;
  bigint.size = size;
  bigint.digits.resize(size, 0);
  bigint.isNegative = false;
  return bigint;
}

void BigInt::Cleanup() {
  while (size > 1 && digits.back() == 0) {
    digits.pop_back();
    size--;
  }
}

BigInt BigInt::AddAbsolute(const BigInt& b) const {
  const BigInt* min;
  const BigInt* max;

  if (size < b.size) {
    min = this;
    max = &b;
  } else {
    min = &b;
    max = this;
  }

  BigInt result = BigInt::BigIntInit(max->size);

  uint8_t carry = 0;
  uint8_t sum = 0;

  for (unsigned int i = 0; i < max->size; i++) {
    uint8_t min_digit = (i < min->size) ? min->digits[i] : 0;
    uint8_t max_digit = max->digits[i];

    sum = min_digit + max_digit + carry;
    result.digits[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry > 0) {
    result.digits.push_back(carry);
    result.size++;
  }

  result.Cleanup();
  return result;
}

BigInt BigInt::SubtractAbsolute(const BigInt& b, bool a_bigger) const {
  const BigInt* min;
  const BigInt* max;
  
  if (a_bigger) {
    max = this;
    min = &b;
  } else {
    max = &b;
    min = this;
  }

  BigInt result = BigInt::BigIntInit(max->size);

  int borrow = 0;
  int difference = 0;

  for (unsigned int i = 0; i < max->size; i++) {
    uint8_t min_digit = (i < min->size) ? min->digits[i] : 0;
    uint8_t max_digit = max->digits[i];

    difference = max_digit - min_digit - borrow;
    if (difference < 0) {
      difference += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }

    result.digits[i] = static_cast<uint8_t>(difference);
  }

  result.Cleanup();

  return result;
}

int BigInt::CompareAbsolute(const BigInt& b) const {
  if (size > b.size) return 1;
  if (b.size < size) return -1;

  // they are equal size so check digits
  for (int i = static_cast<int>(size)-1; i >= 0; i--) {
    if (digits[i] > b.digits[i]) return 1;
    if (digits[i] < b.digits[i]) return -1;
  }

  return 0;
}
