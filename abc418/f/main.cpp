#include <atcoder/modint>
#include <atcoder/segtree>

#include "util/common.h"

using mint = atcoder::modint998244353;

/*
0...紅茶
1...コーヒー
コーヒーが隣り合わないようにする
*/

struct elem {
  mint t00;
  mint t01;
  mint t10;
  mint t11;
};

using segtree = atcoder::segtree<
    optional<elem>,
    [](const optional<elem>& s0, const optional<elem>& s1) -> optional<elem> {
      if (!s0) return s1;
      if (!s1) return s0;
      elem ret;
      ret.t00 = s0->t00 * (s1->t00 + s1->t10) + s0->t01 * s1->t00;
      ret.t01 = s0->t00 * (s1->t01 + s1->t11) + s0->t01 * s1->t01;
      ret.t10 = s0->t10 * (s1->t00 + s1->t10) + s0->t11 * s1->t00;
      ret.t11 = s0->t10 * (s1->t01 + s1->t11) + s0->t11 * s1->t01;
      return ret;
    },
    []() { return nullopt; }>;

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> xys(q);

  segtree st(n);
  vector<s64> as(n, -1);
  set<s64> s;
  for (auto [x, y] : xys) {
    --x;
    if (as[x] == y) continue;

    auto it = s.lower_bound(x);

    if (y == -1) {
    } else {
      s.emplace(y);
    }

    s.erase(as[x]);
    as[x] = y;
  }
}