#include "all.h"

using namespace std;

// 素因数分解を行う（試し割り法）
auto prime_factors(uint64_t n)
{
    vector<uint64_t> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    while (n % 3 == 0) {
        factors.push_back(3);
        n /= 3;
    }

    auto const root = static_cast<uint64_t>(sqrt(n));

    // ex004.cpp の is_prime() と同じ要領でループ数を減らす
    for (uint64_t i = 5; i <= root; i += 6) {
        while (n % i == 0) {
            // ここでの i は必ず素数。
            // ここまでの処理で n は i 未満の自然数で割り切れない数になっている。
            // つまり x < i ならば n % x != 0 といえるが、i が素数じゃないなら
            // x < i かつ n % x == 0 になるような x が存在するため矛盾となる。
            factors.push_back(i);
            n /= i;
        }

        auto j = i + 2;
        while (n % j == 0) {
            // 上記と同じ理由でここでの j は必ず素数である。
            factors.push_back(j);
            n /= j;
        }
    }

    // この時点で n は root 以下の素数では割り切れない数字になっている。
    // では root より大きい素数で割り切れるか？
    // 割り切れる場合 n == rootより大きい素数 * rootより小さい数 となるが
    // この「rootより小さい数」は root 以下の素数で割り切れてはいけないので 1 しかありえない。
    // すると「rootより大きい素数」は n 自身しかありえない。
    // 逆に root より大きい素数で割り切れない場合は、root 以下の素数でも割り切れないのだから
    // どんな素数でも割り切れない、すなわち n == 1 であると結論できる。

    // 以上の話を逆に考えると、この時点で n == 1 なら素因数分解は完了していて、
    // n > 1 なら n が最後の素因数なのでリストに追加すればよい。
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int main(int argc, const char *argv[])
{
    uint64_t n;
    cin >> n;

    vector<uint64_t> factors;
    cout << benchmark([&]() { factors = prime_factors(n); }, 10) << "ms" << endl;

    for (auto f : factors) {
        cout << f << " ";
    }
    cout << endl;
}
