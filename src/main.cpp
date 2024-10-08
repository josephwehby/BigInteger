#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("123456789101112131415234857204987502938475");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("1234567891234567234523452345");
  std::cout << "STRING TO BIGINT " << b << std::endl;
  
  std::cout << "A*B = " << bigintmath::Multiply(a, b) << std::endl;
 
  return 0;
}
