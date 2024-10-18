#include "BigInteger.hpp"
#include <chrono>
#include <random>
#include <iostream>
#include <vector>

std::vector<uint8_t> generate_bytes(int length) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(97, 122);
  
  std::vector<uint8_t> letters;

  for (int i = 0; i < length; i++) {
    letters.push_back(static_cast<uint8_t>(dist(gen)));
  }

  return letters;
}

std::pair<std::string,std::string> generate_digits(int length) {
  std::string n1 = "";
  std::string n2 = "";
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 9);
  
  n1 += std::to_string(dist(gen)%9 + 1);
  for (int i = 0; i < length; i++) n1 += std::to_string(dist(gen));

  n2 += std::to_string(dist(gen)%9 + 1);
  n2 += std::to_string(dist(gen)%9);
  n2 += std::to_string(dist(gen)%9);

  return {n1, n2};
}

long long benchmark(int l) {
  
  /*
  auto nums = generate_digits(l);
  BigInt a = bigintmath::BigIntFromString(nums.first);
  BigInt b = bigintmath::BigIntFromString(nums.second);
  */

  auto letters = generate_bytes(l);

  auto start = std::chrono::high_resolution_clock::now();
  
  //BigInt result = bigintmath::Divide(a, b);

  BigInt number = bigintmath::BigIntFromBytes(letters);
  
  auto stop = std::chrono::high_resolution_clock::now();
  
  auto duration = duration_cast<std::chrono::milliseconds>(stop-start);

  return duration.count();
}

int main() {
  
  int digits = 1000;
  
  while (digits <= 3000) {
    long long average = 0;
    

    for (int i = 0; i < 10; i++) {
      average += benchmark(digits);
    }

    std::cout << digits << " " << average / 10 << std::endl;
    digits += 50;
  }

}
