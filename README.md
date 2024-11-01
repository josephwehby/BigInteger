# BigInteger
Represents integers that are not able to be stored in the traditional data types

# Example Usage
```
BigInt a = BigInt(100) 
BigInt b = BigInt("12345") 
std::cout << a * b << std::endl;
std::cout << a + b << std::endl;
```
- The main file includes additional example usages 

# Build
- The repo contains a .so file in the `library` folder
- To build the project, including the benchmark and example main file, run: 
  - `cmake CMakeLists.txt`
  - `cmake --build .`
