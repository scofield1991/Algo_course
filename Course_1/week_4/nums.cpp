#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> findNums(std::vector<int> &numbers, int n, int k);
//int Partition(std::vector<int> &numbers, int l, int r, int &k);

int main(int argc, char** argv)
{
	int n;
	int k;
	int m;

	std::cin >> n;
	std::cin >> k;
	std::cin >> m;
	std::vector<int> numbers(m);
	
	for(int i = 0; i < m; i++)
		std::cin >> numbers[i];

	std::vector<int>answer = findNums(numbers, n, k);

	for(int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << " ";
	}
}

std::vector<int> findNums(std::vector<int> &numbers, int n, int k)
{
	std::vector<int> answers;

	std::sort (numbers.begin(), numbers.end(),  std::less<int>());

	for(int j = 0; j < numbers.size(); j++)
	{
		std::cout << numbers[j] << " ";
	}
	std::cout << "\n";

	double median = n / double(k);

	int i = 0;
	int i_right = 0;
	int i_left = 1;
	int sum = 0;
	
	while(median > numbers[i])
		i++;
	std::cout << "i: " << i << "\n";

	while(answers.size() < k)
	{
		if(numbers[i+i_right] + sum < n)
		{
			answers.push_back(numbers[i+i_right]);
			sum += numbers[i+i_right];
			i_right++;
		}
		else
		{
			answers.push_back(numbers[i-i_left]);
			sum += numbers[i-i_left];
			i_left++;
		}
		
	}
	return answers;
}

/*
std::vector<int> findNums(std::vector<int> &numbers, int n, int k)
{
	std::vector<int> answers;
	int numsSize = numbers.size();
	std::vector<std::vector<int> > A(numsSize+1, std::vector<int>(numsSize+1));
	
	A[0][0] = 0;
	for(int i = 1; i <= numsSize; i++)
	{
		A[i][0] = numbers[i-1];
		A[0][i] = numbers[i-1];
	}

	int i, j;
	for(i = 1; i < k; i++)
	{
		for(j = 1; j <= numsSize; j++)
		{
			if(j==i)
				A[i][j] = A[i-1][j];
			else
			{
				A[i][j] = A[i][0] + A[i-1][j];
			}
			if(i==k-1 && A[i][j] == n)
				break;
		}
		if(i==k-1)
			break;
	}


	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j <= numsSize; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "i,j: " << i << " " << j << "\n"; 

	return answers;

}
*/
