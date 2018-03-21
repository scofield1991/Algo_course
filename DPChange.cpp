#include <iostream>
#include <vector>

using namespace std;

int DPChange(int money, vector<int> coins);

int main()
{
	int n = 16;
	vector<int> coins = {1, 5 ,12, 25};

	cout << DPChange(16, coins) << "\n";

}

int DPChange(int money, vector<int> coins)
{
	int numCoins = 0;

	vector<int> minNumCoins(money+1);
	minNumCoins[0] = 0;

	for(int m = 1; m <= money; m++)
	{
		minNumCoins[m] = 2 * money;

		for(vector<int>::iterator it = coins.begin(); it != coins.end(); it++)
		{
			if(m >= (*it))
			{
				numCoins = minNumCoins[m-(*it)] + 1;

				cout << numCoins << "\n";
			
				if (numCoins < minNumCoins[m])
					minNumCoins[m] = numCoins;	
			}
			
		}

	}
	return minNumCoins[money];

}