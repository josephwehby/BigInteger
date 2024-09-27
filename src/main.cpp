#include <iostream>
#include "BigInteger.hpp"

int main() {
  BigInt a = bigintmath::BigIntFromString("1234567891012345678910");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromInt(123456789);
  std::cout << "INT TO BIGINT " << b << std::endl;
  
  return 0;
}
