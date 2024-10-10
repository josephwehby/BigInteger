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
    bigint.digits.resize(size, 0);
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
    int difference = 0;

    for (unsigned int i = 0; i < a.size; i++) {
      uint8_t min_digit = (i < b.size) ? b.digits[i] : 0;
      uint8_t max_digit = a.digits[i];
      
      difference = max_digit - min_digit - borrow;
      if (difference < 0) {
        difference += 10; 
        borrow = 1;
      } else {
        borrow = 0;
      }
      result.digits[i] = static_cast<uint8_t>(difference);
    }
    
    while (result.size > 1 && result.digits.back() == 0) {
      result.digits.pop_back();
      result.size--;
    }

    return result;
  }

  int CompareAbsolute(const BigInt& a, const BigInt& b) {
    std::cout << a << " " << b << std::endl;
    std::cout << a.size <<  " " << b.size << std::endl; 
    if (a.size > b.size) return 1;
    if (a.size < b.size) return -1;
    
    for (int i = static_cast<int>(a.size)-1; i >= 0; i--) {
      if (a.digits[i] > b.digits[i]) return 1;
      if (a.digits[i] < b.digits[i]) return -1;
    }

    return 0;
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

// returns 1 if a is greater and -1 if b is
int bigintmath::Compare(const BigInt& a, const BigInt& b) {
  if (a.isNegative && !b.isNegative) return -1;
  if (!a.isNegative && b.isNegative) return 1;

  if (a.size != b.size) return (a.size > b.size) ? 1 : -1;
  
  int sign = (a.isNegative == false) ? 1 : -1;
  for (int i = static_cast<int>(a.size)-1; i >= 0; i--) {
    if (a.digits[i] > b.digits[i]) return 1*sign;
    if (a.digits[i] < b.digits[i]) return -1*sign;
  }

  return 0;
}

bool bigintmath::isZero(const BigInt& a) {
  if (a.size > 1) return false;
  if (a.digits[0] != 0) return false;

  return true;
}

bool bigintmath::isEven(const BigInt& a) {
  BigInt two = BigIntFromInt(2);
  BigInt mod = Mod(a, two);
  return isZero(mod);
}

bool bigintmath::gtZero(const BigInt& a) {
  if (a.isNegative) return false;
  if(a.size > 1) return true;
  if (a.digits[0] == 0) return false; 

  return true;
}

BigInt bigintmath::Add(const BigInt& a, const BigInt& b) {
  BigInt result;
  if (a.isNegative == b.isNegative) {
    result = AddAbsolute(a, b);
    result.isNegative = a.isNegative;
    return result;
  }
  
  // adding bigger positive with smaller negative - subtraction
  int compare = CompareAbsolute(a, b);
  
  if (compare == 1) {
    // a is bigger than b
    result = SubtractAbsolute(a, b);
    result.isNegative = a.isNegative;
  } else if (compare == -1) {
    result = SubtractAbsolute(b, a);
    result.isNegative = b.isNegative;
  } else {
    result = Subtract(a, b);
    result.isNegative = false;
  }

  return result;
}

// a - b
BigInt bigintmath::Subtract(const BigInt& a, const BigInt& b) {
  BigInt result;

  if (!a.isNegative && !b.isNegative) {
    int compare = CompareAbsolute(a, b);
    if (compare == 1 || compare == 0) {
      result = SubtractAbsolute(a, b);
      result.isNegative = false;
    } else {
      result = SubtractAbsolute(b, a);
      result.isNegative = true;
    }
  } else if (a.isNegative && b.isNegative) {
    int compare = CompareAbsolute(a, b);
    if (compare == 1) {
      result = SubtractAbsolute(a, b);
      result.isNegative = true;
    } else {
      result = SubtractAbsolute(b, a);
      result.isNegative = false;
    }
  } else {
    if (a.isNegative && !b.isNegative) {
      result = AddAbsolute(a, b);
      result.isNegative = true;
    } else {
      result = AddAbsolute(a, b);
      result.isNegative = false;
    }
  }
  return result;
}

BigInt bigintmath::Multiply(const BigInt& a, const BigInt& b) {
 
  BigInt result = BigIntInit(a.size + b.size);
  

  bool sign = a.isNegative ^ b.isNegative;
  result.isNegative = sign;
  
  const BigInt* max;
  const BigInt* min;

  if (CompareAbsolute(a, b) == 1) {
    max = &a;
    min = &b;
  } else {
    max = &b;
    min = &a;
  }
  
  for (unsigned int i = 0; i < min->size; i++) {
    uint8_t carry = 0;
    for (unsigned int j = 0; j < max->size; j++) { 
      uint16_t product = (min->digits[i] * max->digits[j]) + carry + result.digits[i+j];
      carry = product / 10;
      result.digits[i+j] = product % 10;
    }
    result.digits[i+max->size] += carry;  
  }
  
  while (result.size > 1 && result.digits.back() == 0) {
    result.digits.pop_back();
    result.size--;
  }

  return result;
}

// integer division
BigInt bigintmath::Divide(const BigInt& a, const BigInt& b) {
  
  if (b.size == 1 && b.digits[0] == 0) {
    throw std::invalid_argument("Cannot divide by 0");
  }

  BigInt result;
  int compare = CompareAbsolute(a, b); 
  bool sign = a.isNegative ^ b.isNegative;

  switch (compare) {
    case 0:
      result = BigIntInit(1);
      result.digits[0] = 1;
      result.isNegative = sign;
      return result;
    case -1:
      std::cout << "here" << std::endl;
      result = BigIntInit(1);
      result.isNegative = sign;
      return result;
    default:
      break;
  }
  
  BigInt d = a;
  int r = 0;

  while (CompareAbsolute(d, b) >= 0) {
    d = SubtractAbsolute(d, b);
    r++;
  }
  std::cout << "DIVIDE " << r << std::endl;
  result = BigIntFromInt(r);
  result.isNegative = sign;
  return result;
}

BigInt bigintmath::Mod(const BigInt& a, const BigInt& b){
  BigInt result;
  if (b.isNegative || a.isNegative) {
    throw std::invalid_argument("Negative mods not currently supported");
  }
  if (b.size == 1 && b.digits[0] == 0) {
    throw std::invalid_argument("Cannot divide by 0");
  }

  if (a.size == 1 && a.digits[0] == 0) {
    result = a;
    return result;
  }

  int compare = CompareAbsolute(a, b);
  switch(compare) {
    case 0:
      result = BigIntInit(1);
      result.digits[0] = 0;
      return result;
    case -1:
      result = a;
      return a;
    default:
      break;
  }

  // division but only care about remainder
  BigInt d = a;
   
  while (CompareAbsolute(d, b) >= 0) {
    d = SubtractAbsolute(d, b);
  }

  result = d;
  return result;
}

// possibly use std::vairant so we can take an unsigned int or BigInt as the power
BigInt bigintmath::Pow(const BigInt& a, unsigned int power) {
  BigInt result;
  bool sign = false;
  
  if (power == 0) {
    result = BigIntInit(1);
    result.digits[0] = 1;
    result.isNegative = a.isNegative;
    return result;
  }
  
  if (power == 1) {
    result = a;
    return result;
  }

  if (power%2 != 0 && a.isNegative) {
    sign = true;
  }

  unsigned int round = 1;
  result = a;

  while (round < power) {
    result = Multiply(result, a);
    round++;
  }
  
  result.isNegative = sign;
  return result;
}

// a^b mod c
BigInt bigintmath::ModPow(const BigInt& a, const BigInt& b, const BigInt& c) {
  BigInt result = BigIntInit(1);
  result.digits[0] = 1;

  BigInt two = BigIntFromInt(2);
  BigInt base = a;
  BigInt power = b;
  BigInt mod = c;

  
  base = Mod(base, mod);
  while (gtZero(power)) {
    std::cout << "Base: " << base << ", Power: " << power << ", Result: " << result << std::endl;
    if (!isEven(power)) {
      result = Mod(Multiply(result, base), mod);
    }

    std::cout << power << std::endl;
    power = Divide(power, two);
    std::cout << "Power " << power << std::endl;
    base = Mod(Pow(base, 2), mod);
    std::cout << "Base after squaring " << base << std::endl;
  }

  return result;
}
