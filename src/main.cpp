#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("10000000");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("999999");
  std::cout << "STRING TO BIGINT " << b << std::endl;
  
  std::cout << bigintmath::Subtract(a, b) << std::endl;
  return 0;
}
