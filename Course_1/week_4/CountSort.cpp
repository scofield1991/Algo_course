#include <iostream>
#include <vector>

using namespace std;

vector<int> countSort(vector<int> &a)
{	
	int N = a.size();
	int M = 10;
	vector<int> count(M, 0);
	vector<int> answer(N, 0);
	

	for(int i = 0; i < N; i++)
		count[a[i]]++ ;

	for(int i = 0; i < M; i++)
		cout << count[i] << " ";
	cout << "\n";

	for(int i = 1; i < M; i++)
		count[i] += count[i - 1];

   //decrease 1 at each index because indexing beggin from 0
	for(int i = 0; i < M; i++)
		cout << count[i]-- << " ";
	cout << "\n";

	for(int i = 0; i < N; i++)
	{
		answer[count[a[i]]--] = a[i];
	}

	for(int i = 0; i < N; i++)
		cout << answer[i] << " ";
	cout << "\n";

	return answer;
}

int main(int argc, char** argv)
{
	int n;

	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	countSort(a); 
}