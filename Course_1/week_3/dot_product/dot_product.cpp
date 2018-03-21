#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  vector<int>::iterator max_el_a, max_el_b;

  while (a.size() > 0)
  {
    max_el_a = std::max_element(a.begin(), a.end());
    max_el_b = std::max_element(b.begin(), b.end());

    result += ((long long) *max_el_a) * (*max_el_b);

    a.erase(max_el_a);
    b.erase(max_el_b);
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
