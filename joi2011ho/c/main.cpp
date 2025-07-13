#include "util/common.h"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<tuple<s64, s64, s64>> abls(m);
  util::cin(abls);
  vector<s64> ss(k);
  util::cin(ss);

  vector<vector<pair<s64, s64>>> g(n);
  for (auto& [a, b, l] : abls) {
    --a;
    --b;
    g[a].push_back(make_pair(l, b));
    g[b].push_back(make_pair(l, a));
  }

  vector<s64> ds(n, numeric_limits<s64>::max());
  using elem_t = pair<s64, s64>;
  priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
  for (auto s : ss) pq.push(make_pair(0, s - 1));
  while (!pq.empty()) {
    auto [d, idx] = pq.top();
    pq.pop();
    if (d >= ds[idx]) continue;
    ds[idx] = d;

    for (auto [nxtl, nxti] : g[idx]) {
      if (d + nxtl >= ds[nxti]) continue;
      pq.push(make_pair(d + nxtl, nxti));
    }
  }

  s64 dmax = 0;
  for (auto [a, b, l] : abls) {
    auto d = (ds[a] + ds[b] + l + 1) / 2;
    dmax = max(dmax, d);
  }
  cout << dmax << endl;
}