#include <iostream>
#include <cmath>

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

int mainSearch(int n, int found, int testing) {
  if (n == 1 || n == 2) {
    return n + 1;
  }
  while (found < n) {
    testing += 6;
    found += (isPrime(testing - 1) + isPrime(testing + 1));
  }
  return testing + (2 * (found == n && isPrime(testing + 1))) - 1;
}

std::string killZeroes(double num) {
  std::string string = std::to_string(num);
  int len = string.length();
  for (int i = len - 1; i > 0; i--) {
    if (string[i] == '0') {
      string.pop_back();
    }
    else {
      break;
    }
  }
  if (string[string.length() - 1] == '.') {
    string.pop_back();
  }
  return string;
}

std::string printTime(double duration) {
  std::string unit;
  if (duration < 0.001) {
    duration *= 1000000;
    unit = "microseconds";
  }
  else if (duration < 1) {
    duration *= 1000;
    unit = "milliseconds";
  }
  else {
    unit = "seconds";
  }
  std::string s_duration = killZeroes(duration);
  s_duration += " ";
  s_duration += unit;
  s_duration += "\n";
  return s_duration;
}
