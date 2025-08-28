# algorithms

Modern C++23 algorithms & examples (modules, concepts, tests).  
Primary module: `goose.algorithm` (bubble_sort, factorial, etc.).

## Prerequisites

- GCC 14 (or newer) with C++23 modules-ts support (tested with GCC 14).
  - Clang 18+ should work (modules are still evolving).
- CMake ≥ 3.29
- Ninja (recommended; required for reliable module builds)
- Git

Check versions:
```bash
g++-14 --version
cmake --version
ninja --version
```

## Clone

```bash
git clone https://github.com/westerngazoo/algorithms.git
cd algorithms
```

## Configure & Build

```bash
cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=g++-14
cmake --build build
```

If multiple GCC versions are installed, ensure `g++-14` is on PATH or pass its full path.

## Run Tests

```bash
ctest --test-dir build --output-on-failure
```

## Run Examples

```bash
./build/examples/sort_demo
./build/examples/example_usage
```

## Using the Module (example)

```cpp
import goose.algorithm;
#include <vector>
int main() {
    std::vector<int> v{5,2,4,1};
    goose::algorithm::bubble_sort(v.begin(), v.end());
}
```

Compile (stand‑alone snippet) with GCC 14:
```bash
g++-14 -std=c++23 -fmodules-ts -I goose-lib/include -c your.cpp
```

Prefer linking against the built library via CMake instead of manual compile for multi-unit usage.

## Project Layout (abridged)

```
include/goose/algorithm/
  sort.cppm            (primary module)
  factorial.cppm       (partition)
tests/
  test_sort.cpp
  test_sort_generic.cpp
examples/
  sort_demo.cpp
  example_usage.cpp
```

## Notes / Restrictions

- Requires GCC 14+ (earlier GCC releases lack needed module stability).
- Uses C++23 (not C++26; dialed back for broader compiler availability).
- Ninja generator strongly recommended; Makefiles generator does not support modules scanning here.
- Comparators passed to `bubble_sort` must provide a strict weak ordering and be `noexcept` to honor the function’s contract.

## Contributing

1. Fork & branch.
2. Add tests (GTest) for new algorithms.
3. Run `ctest` before PR.
4. Keep public API in `goose.algorithm` clean; non-exported helpers stay un-exported inside the namespace.

## License

(Add a LICENSE file; e.g. MIT or Apache-2.0.)

---
Built with GCC 14+; behavior with earlier compilers is