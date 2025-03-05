#include "sparse_table.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

struct rmq {
    using S = int;
    static S op(const S& L, const S& R) {
        return std::min(L, R);
    }
};
int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    sparse_table<rmq> spt{A};
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << spt.product(l, r) << '\n';
    }
}
