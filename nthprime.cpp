#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>

// checks if a given integer is prime, returns true if prime and false if not prime

bool isPrime(int num) {
  if (num % 2 == 0 or num % 3 == 0) {
    return (num == 2 || num == 3);
  }
  for (int i = 6; i < pow(num, 0.5) + 2; i += 6) {
    if ((num % (i - 1) == 0) || (num % (i + 1) == 0)) {
      return false;
    }
  }
  return true;
}

int main() {
  using namespace std::chrono;
  int n;
  int found = 2;
  int testing = 0;
  std::cin >> n; // takes user input to get the integer n, to find the nth prime number
  std::cout << "\n";
  system_clock::time_point start = system_clock::now(); // starts the timer

  // the main loop, where the code runs through odd numbers, and counts up when it finds a prime

  while (found < n) {
    testing += 6;
    found += (isPrime(testing - 1) + isPrime(testing + 1));
  }

  int result = testing + (2 * (found == n && isPrime(testing + 1))) - 1;

  system_clock::time_point end = system_clock::now(); // ends the timer
  duration<double, std::micro> mis = end - start; // creates a variable that stores the total time in microseconds
  std::cout << result << "\n\n"; // prints the nth prime
  if (mis < milliseconds(1)) {
    std::cout << mis.count() << " microseconds\n";
  }
  else if (mis < seconds(1)) {
    duration<double, std::milli> ms = mis; // converts to milliseconds if the total time is between 1 millisecond and 1 second
    std::cout << ms.count() << " milliseconds\n";
  }
  else {
    duration<double> s = mis; // converts to seconds if the total time is at least 1 second
    std::cout << s.count() << " seconds\n";
  }
}
