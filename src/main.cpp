#include <iostream>
#include "BigInteger.hpp"

int main() {
  BigInt a = bigintmath::BigIntFromString("123456789");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("9087654321190063");
  std::cout << "INT TO BIGINT " << b << std::endl;
  
  std::cout << bigintmath::Add(a, b) << std::endl;
  return 0;
}
