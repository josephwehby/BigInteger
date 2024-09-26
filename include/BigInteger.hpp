#pragma once

#include <vector>
#include <cstdint>

struct BigInt {
  // each element will hold 
  std::vector<uint8_t> digits;
  bool isNegative;
  uint32_t size;
};

namespace BigIntegerMath {

}
