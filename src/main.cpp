#include <iostream>
#include "BigInteger.hpp"

int main() {
  BigInt a = bigintmath::BigIntFromString("1000000");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("9000000");
  std::cout << "INT TO BIGINT " << b << std::endl;
  
  std::cout << bigintmath::Add(a, b) << std::endl;
  return 0;
}
