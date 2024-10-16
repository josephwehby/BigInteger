#include <iostream>
#include <vector>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("1234567899999999999190323423423434324234111");
  std::cout << "A: " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("12345678901234567890932498745734893475983475");
  std::cout << "B: " << b << std::endl;

  BigInt c = bigintmath::BigIntFromString("78956432345234523");
  std::cout << "C: " << c << std::endl;
  
  std::vector<uint8_t> hello;
  std::string text = "hello";
  for (char c : text) hello.push_back(static_cast<uint8_t>(c));
  
  BigInt byte_to_num = bigintmath::BigIntFromBytes(hello);
  std::cout << text << " : " << byte_to_num << std::endl;

  std::cout << "A+B = " << bigintmath::Add(a, b) << std::endl;
  std::cout << "A-B = " << bigintmath::Subtract(a, b) << std::endl;
  std::cout << "A/B = " << bigintmath::Divide(a, b) << std::endl;
  std::cout << "A%B = " << bigintmath::Mod(a, b) << std::endl;
  std::cout << "A^B mod C  = " << bigintmath::ModPow(a, b, c) << std::endl;
  return 0;
}
