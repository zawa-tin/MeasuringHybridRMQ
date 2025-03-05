#include "segment_tree.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

struct rmq {
    using S = int;
    static S op(const S& L, const S& R) {
        return std::min(L, R);
    }
    static S e() {
        return (int)1e9 + 1;
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
    segment_tree<rmq> seg{A};
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << seg.product(l, r) << '\n';
    }
}
