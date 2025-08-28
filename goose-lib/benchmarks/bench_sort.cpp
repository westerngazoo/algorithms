#include <benchmark/benchmark.h>
#include <vector>
#include <random>
#include <algorithm>
import goose.algorithm; // bubble_sort

static std::vector<int> make_data(std::size_t n) {
    std::vector<int> v(n);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1'000'000);
    for (auto &x : v) x = dist(rng);
    return v;
}

static void BM_BubbleSort_Vector_Int(benchmark::State& state) {
    auto size = static_cast<std::size_t>(state.range(0));
    for (auto _ : state) {
        auto data = make_data(size);
        goose::algorithm::bubble_sort(data);
        benchmark::DoNotOptimize(data);
    }
    state.SetComplexityN(size);
}

BENCHMARK(BM_BubbleSort_Vector_Int)
    ->RangeMultiplier(2)
    ->Range(1<<5, 1<<10)
    ->Complexity();

BENCHMARK_MAIN();
