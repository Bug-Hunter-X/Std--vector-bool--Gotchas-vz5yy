#include <iostream>
#include <vector>
#include <bitset>

int main() {
  // Demonstrating the issue with std::vector<bool>
  std::vector<bool> boolVector(10);
  boolVector[0] = true;

  // This will not compile as you expect:
  //std::cout << boolVector[0] << std::endl; //Incorrect due to optimization

  // Instead we need to use at():
  std::cout << boolVector.at(0) << std::endl; //Correct
  
  //A better alternative is to use a bitset or std::vector<char> for better performance and predictable behavior:
  std::bitset<10> bitsetVector;
  bitsetVector[0] = true;
  std::cout << bitsetVector[0] << std::endl; //Correct

  std::vector<char> charVector(10);
  charVector[0] = 1;
  std::cout << (charVector[0] != 0) << std::endl; //Correct

  return 0;
}
