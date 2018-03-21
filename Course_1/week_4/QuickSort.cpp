#include <iostream>
#include <vector>
#include <random>

void randomizedQuickSort(std::vector<int> &numbers, int l, int r);
int Partition(std::vector<int> &numbers, int l, int r, int &k);

int main(int argc, char** argv)
{
	int n;

	std::cin >> n;
	std::vector<int> numbers(n);
	
	for(int i = 0; i < n; i++)
		std::cin >> numbers[i];

	randomizedQuickSort(numbers, 0, n-1);

	for(int i = 0; i < n; i++)
	{
		std::cout << numbers[i] << " ";
	}
}

void randomizedQuickSort(std::vector<int> &numbers, int l, int r)
{
	if(l >= r)
		return;

	std::random_device randDev;
	std::mt19937 randNumEngine(randDev());
	std::uniform_int_distribution<int> uni(l, r);
	int randInt = uni(randNumEngine);

	int temp = numbers[l];
	numbers[l] = numbers[randInt];
	numbers[randInt] = temp;

	int k = 0;
	int m = Partition(numbers, l, r, k);

	randomizedQuickSort(numbers, l, k-1);
	randomizedQuickSort(numbers, m+1, r);

}

int Partition(std::vector<int> &numbers, int l, int r, int &k)
{
	int x = numbers[l];
	int j = l;

	//std::cout << "Pivot: " << x << "\n";

	for(int i = j+1; i <= r; i++)
	{
		if(numbers[i] <= x)
		{
			j++;
			int temp = numbers[j];
			numbers[j] = numbers[i];
			numbers[i] = temp;
		}
	}
	numbers[l] = numbers[j];
	numbers[j] = x;
	
	//std::cout << "j: " << j << "\n";
	
	k = j;

	for(int i = l; i < k; i++)
	{
		if(numbers[i] == x)
		{
			k--;
			int temp = numbers[k];
			numbers[k] = numbers[i];
			numbers[i] = temp;
		}
	}

	//std::cout << "k: " << k << "\n";
	
	return j;
}