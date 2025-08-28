// Factorial partition of the goose.algorithm module.
export module goose.algorithm:factorial;

// Best practice: place symbols in a normal namespace and export individual
// declarations instead of exporting the whole namespace.
namespace goose::algorithm {
    export [[nodiscard]] constexpr long long factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }
}