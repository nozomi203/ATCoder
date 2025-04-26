#line 1 "main.cpp"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<s64> c(n), r(n);
  for (s64 i{0}; i < n; ++i) cin >> c[i] >> r[i];
  vector<vector<s64>> g(n);
  for (s64 i{0}; i < k; ++i) {
    s64 a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<map<s64, s64>> g2(n);

  for (s64 i{0}; i < n; ++i) {
    vector<bool> opn(n);
    stack<pair<s64, s64>> s;
    s.push(make_pair(i, 0));
    while (!s.empty()) {
      auto [cur, d] = s.top();
      s.pop();
      opn[cur] = true;
      if (d >= r[i]) continue;
      for (s64 nxt : g[cur]) {
        if (opn[nxt]) continue;
        s.push(make_pair(nxt, d + 1));
        if (g2[i].count(nxt)) {
          g2[i][nxt] = max(g2[i][nxt], c[i]);
        } else {
          g2[i][nxt] = c[i];
        }
      }
    }
  }

  vector<s64> dists(n, numeric_limits<s64>::max());
  priority_queue<pair<s64, s64>, vector<pair<s64, s64>>,
                 greater<pair<s64, s64>>>
      pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (d >= dists[cur]) continue;
    dists[cur] = d;
    for (auto nxt : g2[cur]) {
      auto d_nxt = d + nxt.second;
      if (d_nxt >= dists[nxt.first]) continue;
      pq.push(make_pair(d_nxt, nxt.first));
    }
  }

  cout << dists[n - 1] << endl;
}
