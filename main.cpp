#include <iostream>
#include <chrono>
#include "header.hpp"

int main() {
  int n;
  int found = 2;
  int testing = 0;
  std::cin >> n; // takes user input to get the integer n, to find the nth prime number
  std::cout << "\n";
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // starts the timer

  // the main loop, where the code runs through odd numbers, and counts up when it finds a prime

  int result = mainSearch(n, found, testing);

  std::chrono::system_clock::time_point end = std::chrono::system_clock::now(); // ends the timer
  std::cout << result << "\n\n"; // prints the nth prime
  std::chrono::duration<double> total = end - start; // creates a variable that stores the total time in microseconds
  double ftotal = total.count();
  std::cout << printTime(ftotal);
}
