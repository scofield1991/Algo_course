#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fibonacci(long long n, long long m)
{
    std::vector<int> mods;

    bool first = true;
    int previous = 0;
    int current = 1;

    while((current != 1 || previous != 0) || first)
    {
        mods.push_back(previous);

        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + previous) % m;

        first = false;
    } 

    for(int i =0; i < mods.size(); i++)
        std::cout << mods[i] << " ";
    std::cout << "size: " << mods.size() << "\n";

    int index = n % mods.size();

    return mods[index];

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci(n, m) << " ";
}


