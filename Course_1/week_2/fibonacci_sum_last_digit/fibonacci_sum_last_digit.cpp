#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int fibonacci_sum(long long n)
{
    std::vector<int> mods;

    bool first = true;
    int previous = 0;
    int current = 1;
    int m = 10;
    int sum = 0;

    while((current != 1 || previous != 0) || first)
    {
        mods.push_back(previous);

        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + previous) % m;

        first = false;
    } 

    //for(int i =0; i < mods.size(); i++)
    //    std::cout << mods[i] << " ";
    //std::cout << "size: " << mods.size() << "\n";

    int n_new = n % mods.size();

    for(int i = 0; i <= n_new; i++)
        sum += mods[i];

    return sum % 10;

}



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
