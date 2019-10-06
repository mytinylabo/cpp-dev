#include "all.h"

using namespace std;

// nが素数かどうか調べる
bool is_prime(int n)
{
    if (n < 2) {
        // 0と1は素数じゃない
        return false;
    }
    else if (n <= 3) {
        // 2と3は素数
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0) {
        // 2と3の倍数は先行して非素数と判定
        return false;
    }
    else {
        // 5以上はコツコツ判定
        for (int i = 5; i <= sqrt(n); i += 6) {
            // i     : 判定する
            // i + 1 : 偶数なので判定済み
            // i + 2 : 判定する
            // i + 3 : 偶数なので判定済み
            // i + 4 : 9, 15, 21, ... 必ず3の倍数なので判定済み
            // i + 5 : 偶数なので判定済み
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
    }

    return true;
}

int max_prime(int n)
{
    for (int i = n - 1; i > 1; i--) {
        if (is_prime(i)) {
            return i;
        }
    }
    assert(false); // 入力が自然数じゃない
    return 0;
}

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;

    cout << max_prime(n) << endl;
}
