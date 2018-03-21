#include <iostream>
#include <vector>

using namespace std;

int ladder(int i)
{
	vector<int> steps(i+1);
	steps[0] = 1;
	steps[1] = 1;

	for(int j = 2; j <= i; j++)
	{
		steps[j] = steps[j-1] + steps[j-2];
	}
	return steps[i];

}

int main()
{
	int i = 5;
	std::cout << ladder(i) << "\n";

}