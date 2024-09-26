#include <iostream>
#include "BigInteger.hpp"

int main() {
  BigInt a("12345678910");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  

  BigInt b(12345678);
  std::cout << "INT TO BIGINT " << b << std::endl;
  return 0;
}
