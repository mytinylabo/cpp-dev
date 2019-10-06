#include "all.h"

int64_t test_reduce()
{
    // 数列を生成
    std::vector<int> nums;
    nums.resize(10000000);
    std::iota(nums.begin(), nums.end(), 0);

    auto start = std::chrono::system_clock::now();

    // 合計を畳み込みで計算（オーバーフローするけど気にしない）
    auto sum = std::reduce(std::execution::par, nums.begin(), nums.end(), 0, [](int acc, int i) {
        return acc + i;
    });

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << sum << std::endl;

    return elapsed;
}

int64_t test_transform()
{
    // 数列を生成
    std::vector<int> nums;
    nums.resize(10000000);
    std::iota(nums.begin(), nums.end(), 0);

    // 結果の格納先
    std::vector<int> result;
    result.resize(10000000);

    auto start = std::chrono::system_clock::now();

    // 各要素をインクリメントする
    std::transform(std::execution::par, nums.begin(), nums.end(), result.begin(), [](int i) {
        return i + 1;
    });

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return elapsed;
}

int main(int argc, const char *argv[])
{
    std::array<int64_t, 10> results;

    for (auto &r : results) {
        r = test_reduce();
    }

    auto avr = std::accumulate(results.begin(), results.end(), 0, [](auto acc, auto d) { return acc + d; }) / results.size();
    std::cout << avr << std::endl;
}
