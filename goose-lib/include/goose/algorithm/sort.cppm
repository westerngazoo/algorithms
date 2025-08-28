// Primary interface unit for goose.algorithm.
// Global module fragment keeps standard headers out of the named module BMI to placate current GCC modules-ts.
module;
#include <vector>
#include <utility>
#include <concepts>
#include <functional>
#include <iterator>

export module goose.algorithm;
export import :factorial; // Re-export partition(s)

namespace goose::algorithm {
    // Generic iterator-based bubble_sort (educational). Exported declaration.
    export template <std::random_access_iterator Iter, class Compare = std::less<>>
        requires std::sortable<Iter, Compare>
    void bubble_sort(Iter first, Iter last, Compare comp = {}) noexcept;

    // Convenience overload for std::vector<int> to preserve previous API.
    export void bubble_sort(std::vector<int>& arr) noexcept;
}

namespace goose::algorithm {
    template <std::random_access_iterator Iter, class Compare>
        requires std::sortable<Iter, Compare>
    void bubble_sort(Iter first, Iter last, Compare comp) noexcept {
        auto n = std::distance(first, last);
        if (n < 2) return;//guard

        // Classic bubble sort; stable; O(n^2).
        for (decltype(n) pass = 0; pass < n - 1; ++pass) {
            bool swapped = false;
            for (decltype(n) j = 0; j < n - pass - 1; ++j) {
                Iter a = first + j;
                Iter b = a + 1;
                if (comp(*b, *a)) { // if *b should come before *a
                    std::iter_swap(a, b);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    inline void bubble_sort(std::vector<int>& arr) noexcept {
        bubble_sort(arr.begin(), arr.end(), std::less<>{});
    }
}