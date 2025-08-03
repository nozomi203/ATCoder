#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  for (s64 i = 0; i < t; ++i) {
    s64 n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<s64, s64>> uvs(m);
    util::cin(uvs);

    vector<vector<s64>> g(n + 1);
    for (auto [u, v] : uvs) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (auto& nxts : g) sort(nxts.begin(), nxts.end(), greater());

    list<s64> path;
    vector<bool> visited(n + 1, false);
    stack<s64> s;
    s.push(x);
    while (!s.empty()) {
      auto cur = s.top();
      if (visited[cur]) {
        if (path.back() == cur) path.pop_back();
        s.pop();
      } else {
        path.push_back(cur);
        visited[cur] = true;

        if (cur == y) {
          for (auto e : path) {
            cout << e << " ";
          }
          cout << endl;
          break;
        }

        for (auto nxt : g[cur]) {
          if (visited[nxt]) continue;
          s.push(nxt);
        }
      }
    }
  }
}