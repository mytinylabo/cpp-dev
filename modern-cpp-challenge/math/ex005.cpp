#include "all.h"

using namespace std;

// エラトステネスのふるいでn以下の素数のリストを作成する（イテレータ練習）
auto get_primes(int n)
{
    // [2..n]のリストを作成
    vector<int> nums(n - 1);
    iota(nums.begin(), nums.end(), 2);

    int cur = 2;
    while (cur <= sqrt(n)) {
        // 種の倍数を削除
        auto removed = remove_if(nums.begin(), nums.end(), [=](int i) { return i != cur && i % cur == 0; });
        nums.erase(removed, nums.end());

        // 次の種を探す
        auto next = find_if(nums.begin(), nums.end(), [=](int i) { return i != cur && i > cur; });
        cur = *next;
    }
    return nums;
}

// エラトステネスのふるいでn以下の素数のリストを作成する（パフォーマンス重視）
// n=1000000で↑の10倍くらい速い
auto get_primes2(int n)
{
    vector<bool> prime_table(n + 1, true);

    int cur = 2;
    while (cur <= sqrt(n)) {
        // 種の倍数を非素数としてチェック
        for (int i = cur * 2; i <= n; i += cur) {
            prime_table[i] = false;
        }

        // 次の種を探す
        for (int i = cur + 1; i <= n; i++) {
            if (prime_table[i]) {
                cur = i;
                break;
            }
        }
    }

    // チェックリストから素数のリストを作成
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (prime_table[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// n以下のセクシー素数のリストを作成する
auto get_sexies(int n)
{
    vector<tuple<int, int>> sexies;

    auto primes = get_primes2(n);
    for (auto p = primes.begin(); next(p) != primes.end(); p++) {
        // 差が6以上になる素数を探す
        auto next_p = next(p);
        while (next_p != primes.end() && *next_p - *p < 6) {
            next_p++;
        }

        if (*next_p - *p == 6) {
            // 差がちょうど6ならリストに追加する
            sexies.push_back({ *p, *next_p });
        }
    }

    return sexies;
}

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;

    for (auto s : get_sexies(n)) {
        cout << get<0>(s) << ":" << get<1>(s) << " ";
    }
    cout << endl;
}
