#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> DOptimatSequence(int n)
{

  std::vector<int> minSteps(n+1);
  std::vector<int> optSequence(n+1);
  minSteps[0] = 0;
  minSteps[1] = 0;
  optSequence[0] = 0;
  optSequence[1] = 1;


  for(int i = 2; i <= n; i++)
  {
    int min_steps = 2 * n; 
    int op = 0;
    if(i % 3 == 0)
    {
      int num_steps = minSteps[i / 3] + 1;
      if(num_steps < min_steps){
        min_steps = num_steps;
        op = 3;
      }
    }
    if(i % 2 == 0)
    {
      int num_steps = minSteps[i / 2] + 1;
      if(num_steps < min_steps){
        min_steps = num_steps;
        op = 2;
      }
    }
    int num_steps = minSteps[i - 1] + 1;
      if(num_steps < min_steps){
        min_steps = num_steps;
        op = 1;
      }

    minSteps[i] = min_steps;
    optSequence[i] = op;
  }
  std::vector<int> seq;
  int i = n;

  do
  {
    seq.push_back(i);
    if(optSequence[i] == 2 || optSequence[i] == 3)
      i /= optSequence[i];
    else
      i--;
  }
  while(i >= 1);

  reverse(seq.begin(), seq.end());
  
  return seq;
}

int main() {
  int n;
  std::cin >> n;
  //std::cout << DOptimatSequence(n) << "\n";
  vector<int> sequence = DOptimatSequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
