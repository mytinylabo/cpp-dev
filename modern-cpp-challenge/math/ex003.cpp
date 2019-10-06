#include "all.h"

using namespace std;

// 最大公約数を求める
int my_gcd(int a, int b)
{
    // ユークリッドの互除法
    int m = a >= b ? a : b;
    int n = a >= b ? b : a;

    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }

    return m;
}

// 最小公倍数を求める
int my_lcm(int a, int b)
{
    // lcm = (a * b) / gcd(a, b)
    // オーバーフロー対策で先に割り算する
    return (a / my_gcd(a, b)) * b;
}

void test_gcd(int a, int b, int expected)
{
    int actual = my_gcd(a, b);
    cout << "gcd(" << a << ", " << b << ") ";
    cout << "expected(" << expected << ") ";
    cout << "actual(" << my_gcd(a, b) << ") ";
    cout << (actual == expected ? "PASSED" : "FAILED") << endl;
}

void test_lcm(int a, int b, int expected)
{
    int actual = my_lcm(a, b);
    cout << "gcd(" << a << ", " << b << ") ";
    cout << "expected(" << expected << ") ";
    cout << "actual(" << my_lcm(a, b) << ") ";
    cout << (actual == expected ? "PASSED" : "FAILED") << endl;
}

int main(int argc, const char *argv[])
{
    test_gcd(390, 273, 39);
    test_gcd(871, 793, 13);

    test_lcm(18, 24, 72);
}
