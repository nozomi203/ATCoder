#include "util/common.h"

int main() {
  s64 n, m, c;
  cin >> n >> m >> c;
  vector<tuple<s64, s64, s64>> abds(m);
  util::cin(abds);

  vector<vector<pair<s64, s64>>> g(n);
  for (auto& [a, b, d] : abds) {
    --a;
    --b;
    g[a].push_back(make_pair(d, b));
    g[b].push_back(make_pair(d, a));
  }

  constexpr auto dinf = numeric_limits<s64>::max();
  vector<s64> ds(n, dinf);
  {
    using elem_t = pair<s64, s64>;
    priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
      auto [d, idx] = pq.top();
      pq.pop();
      if (d >= ds[idx]) continue;
      ds[idx] = d;
      for (auto [nxtd, nxti] : g[idx]) {
        if (ds[nxti] <= d + nxtd) continue;
        pq.push(make_pair(d + nxtd, nxti));
      }
    }
  }

  vector<pair<s64, s64>> dis(n);
  for (s64 i = 0; i < n; ++i) dis[i] = make_pair(ds[i], i);
  sort(dis.begin(), dis.end());

  vector<size_t> itoi(n);
  for (size_t i = 0; i < n; ++i) itoi[dis[i].second] = i;

  s64 sumd = 0;
  for (auto [a, b, d] : abds) sumd += d;

  s64 ans = numeric_limits<s64>::max();
  for (size_t i = 0; i < n; ++i) {
    auto [d, idx] = dis[i];
    const s64 x = d;
    for (auto [d2, i2] : g[idx]) {
      if (itoi[i2] > i) continue;
      sumd -= d2;
    }

    s64 cost = x * c + sumd;
    ans = min(ans, cost);
  }

  cout << ans << endl;
}