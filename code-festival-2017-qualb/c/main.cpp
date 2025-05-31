#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(m), b(m);
  for (s64 i{0}; i < m; ++i) cin >> a[i] >> b[i];
  vector<vector<s64>> g(n);
  for (s64 i{0}; i < m; ++i) {
    g[a[i] - 1].push_back(b[i] - 1);
    g[b[i] - 1].push_back(a[i] - 1);
  }

  vector<s64> idxs0, idxs1;
  vector<s64> l(n, -1);
  {
    queue<s64> q;
    q.push(0);
    while (!q.empty()) {
      auto cur{q.front()};
      q.pop();

      for (auto nxt : g[cur]) {
            }
    }
  }
}