#include <atcoder/lazysegtree>

#include "util/common.h"

int main() {
  size_t m, n, k;
  cin >> m >> n >> k;
  vector<tuple<size_t, size_t, size_t, size_t>> abcds(k);
  for (size_t i{0}; i < k; ++i) cin_tuple(abcds[i]);

  // coordinate compression
  vector<pair<size_t, size_t>> xcc, ycc;
  {
    xcc.emplace_back(make_pair(1, 0));
    xcc.emplace_back(make_pair(m + 1, 0));
    ycc.emplace_back(make_pair(1, 0));
    ycc.emplace_back(make_pair(n + 1, 0));
    for (auto& [a, b, c, d] : abcds) {
      ++b;
      ++d;
      xcc.emplace_back(make_pair(a, 0));
      xcc.emplace_back(make_pair(b, 0));
      ycc.emplace_back(make_pair(c, 0));
      ycc.emplace_back(make_pair(d, 0));
    }
    sort(xcc.begin(), xcc.end());
    sort(ycc.begin(), ycc.end());
    xcc.erase(unique(xcc.begin(), xcc.end()), xcc.end());
    ycc.erase(unique(ycc.begin(), ycc.end()), ycc.end());
    for (size_t i{0}; i < xcc.size(); ++i) xcc[i].second = i;
    for (size_t i{0}; i < ycc.size(); ++i) ycc[i].second = i;

    const auto update = [](const vector<pair<size_t, size_t>>& cc, size_t& v) {
      auto it = lower_bound(
          cc.begin(), cc.end(), v,
          [](const pair<size_t, size_t>& e, size_t v) { return e.first < v; });
      v = it->second;
    };

    for (auto& [a, b, c, d] : abcds) {
      update(xcc, a);
      update(xcc, b);
      update(ycc, c);
      update(ycc, d);
    }
  }

  vector<map<size_t, int64_t>> imos(xcc.size());
  for (auto [a, b, c, d] : abcds) {
    ++imos[a][c];
    --imos[a][d];
    --imos[b][c];
    ++imos[b][d];
  }

  using fbpair = pair<size_t, size_t>;
  vector<fbpair> fbpairs(ycc.size());
  for (size_t i{0}; i < ycc.size(); ++i) {
    fbpairs[i].first = i + 1 < ycc.size() ? ycc[i + 1].first - ycc[i].first : 0;
  }

  atcoder::lazy_segtree<fbpair,
                        [](const fbpair& s0, const fbpair& s1) -> fbpair {
                          return make_pair(s0.first + s1.first,
                                           s0.second + s1.second);
                        },
                        []() -> fbpair { return make_pair(0, 0); }, int64_t,
                        [](int64_t f, const fbpair& s) -> fbpair {
                          return f % 2 ? make_pair(s.second, s.first) : s;
                        },
                        [](int64_t f0, int64_t f1) -> int64_t {
                          return f0 + f1;
                        },
                        []() -> int64_t { return 0; }>
      lst(fbpairs);

  int64_t ans{0};
  for (size_t i{0}; i < imos.size() - 1; ++i) {
    if (!imos[i].empty()) {
      for (auto it = imos[i].begin(); it != prev(imos[i].end()); ++it) {
        next(it)->second += it->second;
        lst.apply(it->first, next(it)->first, it->second);
      }
    }
    auto [f, b] = lst.all_prod();
    int64_t mul = (xcc[i + 1].first - xcc[i].first);
    ans += f * mul;
  }
  cout << ans << endl;
}