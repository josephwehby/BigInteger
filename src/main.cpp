#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("1234567899999999999190323423423434324234111");
  std::cout << "A: " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("12345678901234567890");
  //BigInt b = bigintmath::BigIntFromString("100");
  std::cout << "B: " << b << std::endl;

  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
  //std::cout << "A%B = " << bigintmath::Mod(a, b) << std::endl;
  //std::cout << "A^B mod C = " << bigintmath::ModPow(a, b, c) << std::endl;
  return 0;
}
