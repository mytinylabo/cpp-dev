#include <chrono>
#include <functional>

auto benchmark(std::function<void()> f, int iteration = 1)
{
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < iteration; i++) {
        f();
    }

    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
