#include "all.h"

using namespace std;

// n がナルシスト数か調べる
auto is_narcissistic(int n)
{
    double sum = 0.0f;
    int exp = log10(n) + 1; // n の桁数
    int cur = 1; // どの桁を計算しているかを示す

    while (n / cur > 0) {
        int digit = (n / cur) % 10;
        sum += pow(digit, exp);
        cur *= 10;
    }

    return static_cast<int>(sum) == n;
}

int main(int argc, const char *argv[])
{
    assert(is_narcissistic(1));
    assert(is_narcissistic(7));
    assert(is_narcissistic(153));
    assert(is_narcissistic(407));
    assert(is_narcissistic(1634));

    assert(!is_narcissistic(13));
    assert(!is_narcissistic(556));
    assert(!is_narcissistic(9999));

    for (int i = 100; i < 1000; i++) {
        if (is_narcissistic(i)) {
            cout << i << endl;
        }
    }
}
