#include "util/common.h"

/*
ノードが2^n個あるグラフだと考える
*/

int main() {
  s64 t;
  cin >> t;
  vector<pair<s64, string>> cases(t);
  for (auto& [n, s] : cases) {
    cin >> n;
    cin >> s;
  }

  for (const auto& [n, s] : cases) {
    const auto check = [&]() -> bool {
      vector<vector<size_t>> g(1 << n);
      for (size_t mask = 0; mask < (1 << n); ++mask) {
        for (size_t i = 0; i < n; ++i) {
          if (mask & (1 << i)) continue;
          const size_t nxt = mask | (1 << i);
          if (s[nxt - 1] == '1') continue;
          g[mask].push_back(nxt);
        }
      }

      vector<bool> visited(1 << n, false);
      stack<size_t> s;
      s.push(0);
      while (!s.empty()) {
        auto mask = s.top();
        s.pop();

        for (auto nxt : g[mask]) {
          if (visited[nxt]) continue;
          visited[nxt] = true;
          s.push(nxt);
        }
      }

      return visited[(1 << n) - 1];
    };
    cout << (check() ? "Yes" : "No") << endl;
  }
}