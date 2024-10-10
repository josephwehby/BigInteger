#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("10");
  std::cout << "A: " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("23");
  std::cout << "B: " << b << std::endl;

  BigInt c = bigintmath::BigIntFromString("7");
  std::cout << "C: " << c << std::endl;
  

  std::cout << "A*B = " << bigintmath::Multiply(a, b) << std::endl;
  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
  std::cout << "A^2 = " << bigintmath::Pow(a, 2) << std::endl;
  std::cout << "A%B = " << bigintmath::Mod(a, b) << std::endl;
  std::cout << "A^B mod C = " << bigintmath::ModPow(a, b, c) << std::endl;
 
  return 0;
}
