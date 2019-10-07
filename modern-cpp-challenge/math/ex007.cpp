#include "all.h"

using namespace std;

// n の約数の総和を求める（ n は除く）
auto sum_divisors(int n)
{
    if (n <= 1) { return 0; }

    int sum = 1;
    int root = sqrt(n); // -O2 で最適化がかかるが、明示的にキャッシュした方がやや速い

    for (int i = 2; i <= root; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != root) {
                sum += n / i;
            }
        }
    }

    return sum;
}

// n 以下の友愛数のリストを作成する
auto get_amicables(int n)
{
    vector<tuple<int, int>> pairs;
    vector<int> sums(n + 1, -1); // 高速化のため約数の和はキャッシュする

    for (int i = 1; i < n; i++) {
        // すでに約数の和が計算されているなら、友愛数もチェック済み
        if (sums[i] < 0) {
            sums[i] = sum_divisors(i);

            // 完全数 または ペアが範囲外
            if (i == sums[i] || sums[i] > n) { continue; }

            if (sums[sums[i]] < 0) {
                // キャッシュがない場合のみ新たに計算する
                sums[sums[i]] = sum_divisors(sums[i]);
            }

            if (i == sums[sums[i]]) {
                // 友愛数の条件が成立
                pairs.push_back({i, sums[i]});
            }
        }
    }

    return pairs;
}

int main(int argc, const char *argv[])
{
    assert(sum_divisors(1) == 0);
    assert(sum_divisors(7) == 1);
    assert(sum_divisors(60) == 108);
    assert(sum_divisors(220) == 284);
    assert(sum_divisors(284) == 220);

    auto start = chrono::system_clock::now();

    auto amicables = get_amicables(1000000);

    auto end = chrono::system_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << elapsed << "ms" << endl;

    for (auto pair : amicables) {
        cout << get<0>(pair) << "," << get<1>(pair) << endl;
    }
}
