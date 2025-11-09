#include <atcoder/lazysegtree>

#include "util/common.h"

using lazysegtree = atcoder::lazy_segtree<
    s64, [](s64 s0, s64 s1) { return s0 + s1; }, []() { return 0; }, s64,
    [](s64 f, s64 s) { return f + s; }, [](s64 f0, s64 f1) { return f0 + f1; },
    []() { return 0; }>;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n + 1);
  util::cin(as.begin() + 1, as.end());
  vector<pair<s64, s64>> lrs(m);
  util::cin(lrs);
  vector<vector<s64>> rss(n + 1);
  for (auto [l, r] : lrs) {
    rss[l].push_back(r);
  }
  /*
  i以降の整数列がすでに広義単調増加であると仮定した場合に、
  広義単調増加である状態を崩さずiの大きさをj大きくするための最小の操作回数
  */
  constexpr auto inf = numeric_limits<s64>::max();
  const auto get = [&](auto self, s64 i, s64 j) -> pair<s64, s64> {
    if (rss[i].empty()) return {inf, -1};
    s64 ret = inf;
    s64 retr = -1;
    for (auto r : rss[i]) {
      if (r == n || as[r] + j <= as[r + 1]) {
        ret = 0;
        retr = r;
        break;
      }
      const auto [v, tmpr] = self(self, r + 1, as[r] + j - as[r + 1]);
      if (v < ret) {
        ret = v;
        retr = tmpr;
      }
    }

    if (ret == inf) return {inf, -1};

    return {ret + j, retr};
  };

  const auto get_ans = [&]() -> s64 {
    s64 ans = 0;
    for (s64 i = n; i >= 1; --i) {
      if (as[i] < as[i - 1]) {
        const auto [v, r] = get(get, i, as[i - 1] - as[i]);
        if (v == inf) return -1;
        ans += v;
        for (s64 j = i; j <= r; ++j) as[j] = as[i - 1];
      }
    }

    return ans;
  };

  cout << get_ans() << endl;
}