#include <iostream>
#include <vector>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = BigInt(1234875204);
  std::cout << "A: " << a << std::endl;
  
  BigInt b = BigInt("1654");
  std::cout << "B: " << b << std::endl;

  BigInt c = BigInt("78956432");
  std::cout << "C: " << c << std::endl;
  
  std::cout << "A + B = " << a+b << std::endl;
  std::cout << "A - B = " << a-b << std::endl;
  std::cout << "A * B = " << a*b << std::endl;
  std::cout << "A / B = " << a/b << std::endl;
  std::cout << "A % B = " << a%b << std::endl;

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
