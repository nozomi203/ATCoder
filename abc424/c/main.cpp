#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);

  vector<bool> bs(n + 1);

  vector<vector<s64>> g(n + 1);
  queue<s64> q;
  for (s64 i = 0; i < n; ++i) {
    auto [a, b] = abs[i];
    if (a == 0 && b == 0) {
      q.push(i + 1);
      bs[i + 1] = true;
    } else {
      g[a].push_back(i + 1);
      g[b].push_back(i + 1);
    }
  }

  while (!q.empty()) {
    const s64 cur = q.front();
    q.pop();
    for (auto nxt : g[cur]) {
      if (bs[nxt]) continue;
      bs[nxt] = true;
      q.push(nxt);
    }
  }

  const s64 ans = std::count(bs.begin(), bs.end(), true);
  cout << ans << endl;
}