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
