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
  std::cout << "A % B = " << a%b << std::endl;
 
  BigInt result = a >> 1;
  std::cout << "A >> 1 = " << result << std::endl;
  std::cout << "A ^ B = " << BigInt::Pow(a, b) << std::endl; 

  std::cout << "A^B mod C  = " << BigInt::ModPow(a, b, c) << std::endl;
  
  // convert byte array to bigint
  std::string message = "43110 W0r1D!!";
  std::vector<uint8_t> bytes; 
  for (char c : message) bytes.push_back(static_cast<uint8_t>(c));
  BigInt B = BigInt(bytes); 
  std::cout << message << ": " << B << std::endl;

  // convert bigint to bytes
  std::cout << B << ": ";
  std::vector<uint8_t> B_bytes = B.ToBytes();
  for (uint8_t byte : B_bytes) std::cout << static_cast<char>(byte);
  std::cout << std::endl;
  return 0;
}
