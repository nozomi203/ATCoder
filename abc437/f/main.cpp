#include <atcoder/segtree>

#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> xys(n);
  vector<tuple<s64, s64, s64, s64, s64>> queries(q);
  util::cin(xys);
  for (auto& [q0, q1, q2, q3, q4] : queries) {
    cin >> q0;
    if (q0 == 1) {
      cin >> q1 >> q2 >> q3;
    } else {
      cin >> q1 >> q2 >> q3 >> q4;
    }
  }

  using elem_t = pair<s64, s64>;

  atcoder::segtree<elem_t,
                   [](elem_t s0, elem_t s1) -> elem_t {
                     return (s0.first + s0.second > s1.first + s1.second) ? s0
                                                                          : s1;
                   },
                   []() -> elem_t {
                     return elem_t(-100000000000, -100000000000);
                   }>
      lst0(xys);
  atcoder::segtree<elem_t,
                   [](elem_t s0, elem_t s1) -> elem_t {
                     return (s0.first - s0.second > s1.first - s1.second) ? s0
                                                                          : s1;
                   },
                   []() -> elem_t {
                     return elem_t(-100000000000, 100000000000);
                   }>
      lst1(xys);
  atcoder::segtree<elem_t,
                   [](elem_t s0, elem_t s1) -> elem_t {
                     return (s0.first + s0.second < s1.first + s1.second) ? s0
                                                                          : s1;
                   },
                   []() -> elem_t {
                     return elem_t(100000000000, 100000000000);
                   }>
      lst2(xys);
  atcoder::segtree<elem_t,
                   [](elem_t s0, elem_t s1) -> elem_t {
                     return (s0.first - s0.second < s1.first - s1.second) ? s0
                                                                          : s1;
                   },
                   []() -> elem_t {
                     return elem_t(100000000000, -100000000000);
                   }>
      lst3(xys);

  for (auto [q0, q1, q2, q3, q4] : queries) {
    if (q0 == 1) {
      lst0.set(q1 - 1, elem_t(q2, q3));
      lst1.set(q1 - 1, elem_t(q2, q3));
      lst2.set(q1 - 1, elem_t(q2, q3));
      lst3.set(q1 - 1, elem_t(q2, q3));
    } else {
      auto p0 = lst0.prod(q1 - 1, q2);
      auto p1 = lst1.prod(q1 - 1, q2);
      auto p2 = lst2.prod(q1 - 1, q2);
      auto p3 = lst3.prod(q1 - 1, q2);
      s64 d = abs(q3 + q4 - p0.first - p0.second);
      d = max(d, abs(q3 + q4 - p2.first - p2.second));
      d = max(d, abs(q3 - q4 - p1.first + p1.second));
      d = max(d, abs(q3 - q4 - p3.first + p3.second));
      cout << d << endl;
    }
  }
}