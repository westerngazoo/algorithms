# 0 "/home/goose/projects/algorithms/goose-lib/include/goose/algorithm/factorial.cppm"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/goose/projects/algorithms/goose-lib/include/goose/algorithm/factorial.cppm"

export  module  goose.algorithm:factorial;



namespace goose::algorithm {
    export [[nodiscard]] constexpr long long factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }
}
