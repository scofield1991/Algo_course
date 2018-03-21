#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum(long long from, long long to)
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

    int from_new = from % mods.size();
    int to_new = to % mods.size();

    for(int i = from_new; i <= to_new; i++)
        sum += mods[i];

    return sum % 10;

}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_sum(from, to) << '\n';
}
