#include <atcoder/segtree>

#include "util/common.h"

/*
各英子文字毎にその文字の数をBITで管理
*/

int main() {
  size_t n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<tuple<size_t, size_t, variant<char, size_t>>> queries(q);
  for (auto& [q0, q1, q2] : queries) {
    cin >> q0 >> q1;
    if (q0 == 1) {
      char x;
      cin >> x;
      q2 = x;
    } else {
      size_t r;
      cin >> r;
      q2 = r;
    }
  }

  const auto toidx = [](char c) -> size_t { return c - 'a'; };

  struct elem_t {
    u32 nl{0};
    u32 nr{0};
    u32 nmax{0};
    u32 range{0};
  };

  using segtree =
      atcoder::segtree<elem_t,
                       [](const elem_t& l, const elem_t& r) -> elem_t {
                         const u32 nl = l.nl == l.range ? l.nl + r.nl : l.nl;
                         const u32 nr = r.nr == r.range ? r.nr + l.nr : r.nr;
                         return elem_t{
                             nl, nr,
                             std::max({l.nmax, r.nmax, l.nr + r.nl, nl, nr}),
                             l.range + r.range};
                       },
                       []() -> elem_t { return elem_t{}; }>;

  vector<segtree> sts;
  sts.reserve(26);
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<elem_t> v;
    v.reserve(n);
    for (size_t i = 0; i < n; ++i) {
      u32 cnt = (s[i] == c) ? 1 : 0;
      v.push_back({cnt, cnt, cnt, 1});
    }
    sts.emplace_back(segtree(v));
  }

  for (const auto& [q0, q1, q2] : queries) {
    if (q0 == 1) {
      const size_t i = q1 - 1;
      const char x = get<0>(q2);
      sts[toidx(s[i])].set(i, elem_t{0, 0, 0, 1});
      s[i] = x;
      sts[toidx(s[i])].set(i, elem_t{1, 1, 1, 1});
    } else {
      // range [l,r)
      const size_t l = q1 - 1;
      const size_t r = get<1>(q2);

      u32 ans = 0;
      for (char c = 'a'; c <= 'z'; ++c) {
        const auto e = sts[toidx(c)].prod(l, r);
        if (e.nmax == 0) continue;
        ans = max(ans, e.nmax);
      }
      cout << ans << endl;
    }
  }
}