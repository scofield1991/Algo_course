#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) 
{
  //write your code here
  int str_1_size = str1.size();
  int str_2_size = str2.size();
  vector< vector<int> > D(str_1_size+1, vector<int>(str_2_size+1, 0));

  //vector< vector<int> > K(W+1, vector<int>(w_size+1, 0));
  
  for(int i = 0; i <= str_1_size; i++)
  	D[i][0] = i;

  for(int i = 0; i <= str_2_size; i++)
  	D[0][i] = i;

  for(int i = 1; i <= str_1_size; i++)
  {
  	for(int j = 1; j <= str_2_size; j++)
  	{
  		int insertion = D[i][j-1] + 1;
  		int deletion = D[i-1][j] + 1;
  		int misMatch = D[i-1][j-1] + 1;
  		int match = D[i-1][j-1];
  		
  		if(str1[i-1] == str2[j-1])
  		{
  			D[i][j] = std::min(std::min(insertion, deletion), match);
  		}
  		else
  		{
  			D[i][j] = std::min(std::min(insertion, deletion), misMatch);
  		}

  	}

  }
  return D[str_1_size][str_2_size];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
