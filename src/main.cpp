#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("123456789012345678901234567890");
  std::cout << "A: " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("2");
  std::cout << "B: " << b << std::endl;

  BigInt c = bigintmath::BigIntFromString("2");
  std::cout << "C: " << c << std::endl;
  
  std::cout << bigintmath::RightShift(a) << std::endl;
  std::cout << "A*B = " << bigintmath::Multiply(a, b) << std::endl;
  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
 
  return 0;
}
