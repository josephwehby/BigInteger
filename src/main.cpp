#include <iostream>
#include <vector>
#include "BigInteger.hpp"

int main() {
  BigInt a = BigInt(123234234);
  std::cout << "A: " << a << std::endl;
  
  BigInt b = BigInt("165");
  std::cout << "B: " << b << std::endl;

  BigInt c = BigInt("78956");
  std::cout << "C: " << c << std::endl;
  
  std::cout << "A + B = " << a+b << std::endl;
  std::cout << "A - B = " << a-b << std::endl;
  std::cout << "A * B = " << a*b << std::endl;
  std::cout << "A / B = " << a/b << std::endl;
  //std::cout << "A % B = " << a%b << std::endl;
 
  BigInt result = a >> 1;
  std::cout << "A >> 1 = " << result << std::endl;
  std::cout << "A ^ B = " << BigInt::Pow(a, b) << std::endl; 

  std::cout << "A^B mod C  = " << BigInt::ModPow(a, b, c) << std::endl;
  

  std::string message = "Hello World";
  std::vector<uint8_t> bytes;
  
  for (char c : message) {
    bytes.push_back(static_cast<uint8_t>(c));
  }

  std::cout << BigInt(bytes) << std::endl;
  return 0;
}
