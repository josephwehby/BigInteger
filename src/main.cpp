#include <iostream>
#include "BigInteger.hpp"

int main() {
  
  BigInt a = bigintmath::BigIntFromString("123456789");
  std::cout << "STRING TO BIGINT " << a << std::endl;
  
  BigInt b = bigintmath::BigIntFromString("123456782");
  std::cout << "STRING TO BIGINT " << b << std::endl;
  
  std::cout << "A-B = " << bigintmath::Subtract(a, b) << std::endl;
 
  int compare = bigintmath::Compare(a,b);
  std::cout << "Is a greater than b: " << compare << std::endl;
  

  return 0;
}
