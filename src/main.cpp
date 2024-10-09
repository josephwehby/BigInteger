#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("2");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("5");
  std::cout << "STRING TO BIGINT " << b << std::endl;
  
  std::cout << "A*B = " << bigintmath::Multiply(a, b) << std::endl;
  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
  std::cout << "A^4 = " << bigintmath::Pow(a, 32) << std::endl;
 
  return 0;
}
