#include <atcoder/lazysegtree>

#include "util/common.h"

/*
登場するすべての1,2のクエリに含まれるvの値をもとに座標圧縮する？
Wが昇順になっていることを利用できそう
現在ある区間の左右どちらかに合わせるという操作であることから、ある区間iがそれより大きい区間jの外側に出ることはない
連続する区間i,jがあったとき、2つの区間は左右どちらかでそろっている
このことから、タイプ3の答えがiであるとき、その答えに含まれる区間は[v[n-i], v[n]]
*/

struct S {
  s64 dl{0};
  s64 dr{0};
  s64 len{0};
};
using F = optional<bool>;
using lazysegtree =
    atcoder::lazy_segtree<S,
                          [](S s0, S s1) -> S {
                            return S(s0.dl + s1.dl, s0.dr + s1.dr,
                                     s0.len + s1.len);
                          },
                          []() -> S { return S{}; }, F,
                          [](F f, S s) -> S {
                            S ret = s;
                            if (f) {
                              const bool b = *f;
                              if (b) {
                                ret.dl = ret.len;
                                ret.dr = 0;
                              } else {
                                ret.dl = 0;
                                ret.dr = -ret.len;
                              }
                            }
                            return ret;
                          },
                          [](F f0, F f1) -> F { return f0 ? f0 : f1; },
                          []() -> F { return nullopt; }>;

int main() {
  s64 n;
  cin >> n;
  vector<s64> ws(n);
  util::cin(ws);
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> queries(q);
  util::cin(queries);

  vector<S> ss(n);
  for (s64 i = 0; i < n; ++i) {
    const s64 d = i < n - 1 ? ws[i + 1] - ws[i] : 0;
    ss[i] = S{0, -d, d};
  }
  // 区間の変化量
  lazysegtree lst(ss);

  for (auto [q0, q1] : queries) {
    if (q0 == 1) {
      lst.apply(0, q1 - 1, false);
    } else if (q0 == 2) {
      lst.apply(0, q1 - 1, true);
    } else {
      const auto get = [&]() -> s64 {
        if (auto prd = lst.prod(0, n); q1 >= prd.dl && q1 < ws.back() + prd.dr)
          return n;
        if (q1 >= ws.back()) return 0;

        s64 ll = 0;
        s64 lr = n - 1;
        while (lr - ll > 1) {
          s64 lm = (ll + lr) / 2;
          S prd = lst.prod(lm, n);
          if (q1 >= prd.dl && q1 < ws.back() + prd.dr) {
            lr = lm;
          } else {
            ll = lm;
          }
        }
        return n - lr;
      };

      cout << get() << endl;
    }
  }
}