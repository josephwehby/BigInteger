#include <iostream>
#include <vector>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = BigInt(1234567);
  std::cout << "A: " << a << std::endl;
  
  BigInt b = BigInt("12");
  std::cout << "B: " << b << std::endl;

  BigInt c = BigInt("78956432");
  std::cout << "C: " << c << std::endl;
  
  /*
  std::vector<uint8_t> hello;
  std::string text = "hello";
  for (char c : text) hello.push_back(static_cast<uint8_t>(c));
  
  BigInt byte_to_num = BigInt(hello);
  std::cout << text << " : " << byte_to_num << std::endl;
  
  std::cout << "A+B = " << bigintmath::Add(a, b) << std::endl;
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
