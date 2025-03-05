#pragma once

#include <vector>
#include <cassert>
#include <ostream>

template <class T>
class sparse_table {
public:

    using S = typename T::S;

    sparse_table() : L{}, dat{} {}

    explicit sparse_table(const std::vector<S>& a) : L(a.size() + 1), dat{} {
        for (int i{1} ; i < (int)L.size() ; i++) {
            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));
        }
        dat.resize(L.back() + 1);
        dat[0] = a;
        for (int i = 1, len = 2, half = 1 ; i < (int)dat.size() ; i++, len <<= 1, half <<= 1) {
            dat[i] = dat[i - 1];
            for (int j = 0 ; j + len - 1 < (int)dat[i].size() ; j++) {
                dat[i][j] = T::op(dat[i - 1][j], dat[i - 1][j + half]);
            }
        }
    }

    S product(int l, int r) const {
        assert(l <= r);
        assert(l < dat[0].size());
        assert(r <= dat[0].size());
        int now = L[r - l];
        return T::op(dat[now][l], dat[now][r - (1 << now)]);
    }

private:

    std::vector<int> L;

    std::vector<std::vector<S>> dat;

};
