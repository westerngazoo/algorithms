# Benchmarks using Google Benchmark

include(FetchContent)
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
# Require pthreads for benchmark on Linux
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googlebenchmark)

file(GLOB BENCH_SOURCES "*.cpp")
add_executable(run_benchmarks ${BENCH_SOURCES})

# Link goose library and benchmark
find_package(Threads REQUIRED)

target_link_libraries(run_benchmarks PRIVATE Goose::goose benchmark::benchmark Threads::Threads)

# Provide a custom target for easy invocation via `cmake --build . --target bench`
add_custom_target(bench COMMAND run_benchmarks DEPENDS run_benchmarks)
