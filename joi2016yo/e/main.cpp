#include "util/common.h"

int main() {
  s64 n, m, k, s;
  cin >> n >> m >> k >> s;
  s64 p, q;
  cin >> p >> q;
  vector<s64> c(k);
  for (s64 i{0}; i < k; ++i) cin >> c[i];
  vector<vector<s64>> g(n + 1);
  for (s64 i{0}; i < m; ++i) {
    s64 a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<s64> d(n + 1, numeric_limits<s64>::max());
  for (s64 i{0}; i < k; ++i) {
    d[c[i]] = 0;
    queue<s64> q;
    q.push(c[i]);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto nxt : g[cur]) {
        if (d[nxt] <= d[cur] + 1) continue;
        d[nxt] = d[cur] + 1;
        q.push(nxt);
      }
    }
  }

  vector<s64> min_cst(n + 1, numeric_limits<s64>::max());
  priority_queue<pair<s64, s64>, vector<pair<s64, s64>>,
                 greater<pair<s64, s64>>>
      pq;
  pq.push(make_pair(0, 1));
  while (!pq.empty()) {
    auto [cst, cur] = pq.top();
    pq.pop();
    if (cst >= min_cst[cur]) continue;
    min_cst[cur] = cst;
    for (auto nxt : g[cur]) {
      if (d[nxt] == 0) continue;
      auto cst_nxt = min_cst[cur] + (d[nxt] > s ? p : q);
      if (cst_nxt >= min_cst[nxt]) continue;
      pq.push(make_pair(cst_nxt, nxt));
    }
  }

  cout << min_cst[n] - (d[n] > s ? p : q) << endl;
}