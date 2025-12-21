#include <atcoder/segtree>

#include "util/common.h"

using S = pair<s64, s64>;
using F = s64;
using segtree = atcoder::segtree<S,
                                 [](S s0, S s1) -> S {
                                   return make_pair(min(s0.first, s1.first),
                                                    max(s0.second, s1.second));
                                 },
                                 []() -> S {
                                   return pair(numeric_limits<s64>::max(),
                                               numeric_limits<s64>::min());
                                 }>;
int main() {
  s64 n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> abs(q);
  util::cin(abs);

  segtree st(n + 1);
  for (auto [a, b] : abs) {
    const S q = st.prod(a, b + 1);
    const bool p = q.first > a && q.second < b;
    cout << (p ? "Yes" : "No") << endl;
    if (p) {
      st.set(a, make_pair(numeric_limits<s64>::max(), b));
      st.set(b, make_pair(a, numeric_limits<s64>::min()));
    }
  }
}