#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> merge(vector<int> &a, vector<int> &b);
vector<int> merge_sort(vector<int> &a);

int get_majority_element(vector<int> &a, int left, int right) {
  vector<int> b = merge_sort(a);
  int index = b.size() / 2;
  int count = 0;
  for(int i = 0; i < b.size(); i++)
  {
    if (b[i] == b[index])
      count++;
  }
  //std::cout << "index: " << index << "\n";
  if (count > index)
    return 1;
  else
    return 0;

  //if (left == right) return a.at(left);
  //else
  //  merge()
  //if (left + 1 == right) return a[left];

  //write your code here
  //return -1;
}

vector<int> merge_sort(vector<int> &a)
{
  if(a.size() == 1)
   return a;
  else
  {
    int half_size = a.size() / 2;
    vector<int> b(a.begin(), a.begin() + half_size);
    vector<int> c(a.begin() + half_size, a.end());

    vector<int> new_b = merge_sort(b);
    vector<int> new_c = merge_sort(c);

    return merge(new_b, new_c);
  }
}

vector<int> merge(vector<int> &a, vector<int> &b)
{
  int N = a.size() + b.size();
  int j = 0;
  int k = 0;
  vector<int> c;
  
  while( j < a.size() && k < b.size())
  {
    if(a[j] <= b[k])
    {
      c.push_back(a[j]);
      j++;
    }
    else
    {
      c.push_back(b[k]);
      k++;
    }
  }

  for(; j < a.size(); j++)
    c.push_back(a[j]);

  for(; k < b.size(); k++)
    c.push_back(b[k]);

  return c;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  vector<int> c(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
    c[i] = a[i];
  }
  //vector<int> b = merge_sort(a);
  //for(int i = 0; i < b.size(); i++)
  //  std::cout << b[i] << " ";
  //  std::cout << "\n";
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
