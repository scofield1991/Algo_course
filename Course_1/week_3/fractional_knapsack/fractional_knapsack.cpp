#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();

  for(int i = 0; i < n; i++)
  {
    if(capacity == 0)
      return value;

    double max = 0;
    int max_index = -1;
    for(int j = 0; j < n; j++)
    {
      if((double)values[j] / weights[j] > max && weights[j] > 0)
      {
        max = (double)values[j] / weights[j];
        max_index = j;
      } 
    }

    int a = std::min(weights[max_index], capacity);
    value += a * max;
    weights[max_index] -= a;
    capacity -= a;
  }

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
