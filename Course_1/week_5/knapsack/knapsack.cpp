#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int knapSack(int W, const vector<int> &w)
{

  int w_size = w.size();
  //int K[W+1][w_size+1];
  vector< vector<int> > K(W+1, vector<int>(w_size+1, 0));

  //for(int i = 0; i <= W; i++)
  //  K[i][0] = 0;

  //for(int i = 0; i <= w_size; i++)
  //  K[0][i] = 0;

  for(int item = 1; item <= w_size; item++)
  {
    for(int weight = 1; weight <= W; weight++)
    {
      if(w.at(item-1) > weight)
        K[weight][item] = K[weight][item-1];
      else
      {
        int newVal = K[weight - w.at(item-1)][item-1] + w.at(item-1);
        if(newVal > K[weight][item-1])
          K[weight][item] = newVal;
        else
          K[weight][item] = K[weight][item-1];
      }
    }
  }
  return K[W][w_size];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << knapSack(W, w) << '\n';
}
