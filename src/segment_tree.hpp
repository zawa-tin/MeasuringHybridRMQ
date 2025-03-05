#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

template <class T>
class segment_tree {
public:

    using S = typename T::S;

    segment_tree() = default;

    explicit segment_tree(int size) : n{size}, dat(size << 1, T::e()) {}

    explicit segment_tree(const std::vector<S>& d) : n{(int)d.size()}, dat(d.size() << 1) {
        std::copy(d.begin(), d.end(), dat.begin() + n);
        for (int i = n - 1 ; i >= 1 ; i--) dat[i] = T::op(dat[i << 1 | 0], dat[i << 1 | 1]);
    }

    S product(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        int L = T::e(), R = T::e();
        for (l += n, r += n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) L = T::op(L, dat[l++]);
            if (r & 1) R = T::op(R, dat[--r]);
        }
        return T::op(L, R);
    }

private:

    int n;

    std::vector<S> dat;
    
};
