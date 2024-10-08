#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("123456789");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("1234567891234567");
  std::cout << "STRING TO BIGINT " << b << std::endl;
  
  std::cout << "A*B = " << bigintmath::Multiply(a, b) << std::endl;
 
  return 0;
}
