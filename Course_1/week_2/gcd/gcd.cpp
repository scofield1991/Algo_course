#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int euclidian_gcd(int a, int b)
{
  if(b == 0)
    return a;

  int temp_a = a % b;

  return euclidian_gcd(b, temp_a);


}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << euclidian_gcd(a, b) << std::endl;
  return 0;
}
