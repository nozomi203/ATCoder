#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<vector<s64>> g(n + 1);
  for (s64 i{0}; i < m; ++i) {
    s64 a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  const auto check = [&]() -> bool {
    if (m != n) return false;
    for (s64 i{1}; i <= n; ++i) {
      if (g[i].size() != 2) return false;
    }

    vector<s64> visited(n + 1);
    stack<pair<s64, s64>> s;
    s.push(make_pair(g[1][0], 1));
    s64 cnt{0};
    while (!s.empty()) {
      auto [prv, cur] = s.top();
      s.pop();
      if (visited[cur]) {
        ++cnt;
      } else {
        visited[cur] = true;
        for (auto nxt : g[cur]) {
          if (nxt == prv) continue;
          s.push(make_pair(cur, nxt));
        }
      }
    }
    for (s64 i{1}; i <= n; ++i) {
      if (!visited[i]) return false;
    }
    return cnt == 1;
  };
  cout << (check() ? "Yes" : "No") << endl;
}