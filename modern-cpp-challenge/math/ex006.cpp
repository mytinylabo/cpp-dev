#include "all.h"

using namespace std;

// nの約数のリストを昇順で作成する
// （問題を解くだけなら直接総和を出す方が効率的）
auto get_divisors(int n)
{
    // 再配置のコストがひどいなら reserve しておく？（ひとまずやらない）
    vector<int> small_divs, big_divs;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            small_divs.push_back(i);
            if (i != sqrt(n)) {
                // i が約数なら n/i も約数
                // 降順で見つかるので昇順になるよう前に詰める
                big_divs.insert(big_divs.begin(), n / i);
            }
        }
    }

    copy(big_divs.begin(), big_divs.end(), back_inserter(small_divs));

    return small_divs;
}

// n 以下の過剰数のリストを作成する
auto get_abundants(int n)
{
    vector<int> abuns;

    for (int i = 1; i <= n; i++) {
        auto divs = get_divisors(i);
        if (i * 2 < accumulate(divs.begin(), divs.end(), 0)) {
            abuns.push_back(i);
        }
    }

    return abuns;
}

int main(int argc, const char *argv[])
{
    assert(get_divisors(1)  == (vector<int> {1}));
    assert(get_divisors(7)  == (vector<int> {1, 7}));
    assert(get_divisors(60) == (vector<int> {1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60}));

    int n;
    cin >> n;

    for (auto d : get_abundants(n)) {
        cout << d << " ";
    }
    cout << endl;
}
