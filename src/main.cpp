#include <iostream>
#include <vector>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = BigInt(-1111111);
  std::cout << "A: " << a << std::endl;
  
  BigInt b = BigInt("-1111111");
  std::cout << "B: " << b << std::endl;

  BigInt c = BigInt("78956432");
  std::cout << "C: " << c << std::endl;

  if (a > b) {
    std::cout << "A is greater than B" << std::endl;
  } else {
    std::cout << "A is less than B" << std::endl;
  }

  if (a == b) {
    std::cout << "A is equal to B" << std::endl;
  } else {
    std::cout << "A is not equal to B" << std::endl;
  }
  
  /*
  std::cout << "A-B = " << bigintmath::Subtract(a, b) << std::endl;
  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
  std::cout << "A%B = " << bigintmath::Mod(a, b) << std::endl;
  std::cout << "A^B mod C  = " << bigintmath::ModPow(a, b, c) << std::endl;
  std::cout << "A << 1  = " << bigintmath::LeftShift(a) << std::endl;
  std::cout << "A >> 1  = " << bigintmath::RightShift(a) << std::endl;
  std::cout << "A ^ B  = " << bigintmath::Pow(a, b) << std::endl;
  */

  return 0;
}
