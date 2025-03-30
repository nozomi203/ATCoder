#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> us(m);
  vector<vector<pair<s64, s64>>> graph(n + 1);
  for (s64 i{0}; i < m; ++i) {
    s64 u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, -w));
    us[i] = u;
  }

  vector<s64> xs(n + 1, 0);
  vector<bool> opened(n + 1, false);
  for (auto u : us) {
    queue<s64> q;
    q.push(u);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (!opened[node]) {
        opened[node] = true;
        for (auto [nxt_node, w] : graph[node]) {
          if (opened[nxt_node]) continue;
          q.push(nxt_node);
          xs[nxt_node] = xs[node] + w;
        }
      }
    }
  }

  for (s64 i{1}; i <= n; ++i) {
    cout << xs[i];
    if (i < n) cout << " ";
  }
  cout << endl;
}