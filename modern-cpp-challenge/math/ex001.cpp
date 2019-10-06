#include "all.h"

// nまでの3と5の倍数の総和を求める
int sum_fizzbuzz(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i % 3 == 0 || i % 5 == 0 ? i : 0;
    }

    return sum;
}

// nまでの3と5の倍数の総和を求める（畳み込み練習版）
int sum_fizzbuzz_reduce(int n)
{
    std::vector<int> nums;
    nums.resize(n);
    std::iota(nums.begin(), nums.end(), 1);

    return std::reduce(std::execution::par, nums.begin(), nums.end(), 0, [](int prev, int cur) {
        return prev + (cur % 3 == 0 || cur % 5 == 0 ? cur : 0);
    });
}

int main(int argc, const char *argv[])
{
    int n;
    std::cin >> n;

    std::cout << sum_fizzbuzz(n) << std::endl;
    // std::cout << sum_fizzbuzz2(n) << std::endl;
}
