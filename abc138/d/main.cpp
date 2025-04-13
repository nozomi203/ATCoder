#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<vector<s64>> graph(n + 1);
  vector<s64> xs(n + 1);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (s64 i{0}; i < q; ++i) {
    s64 p, x;
    cin >> p >> x;
    xs[p] += x;
  }

  vector<s64> cnts(n + 1, 0);

  vector<bool> open(n + 1, false);
  stack<pair<s64, s64>> s;
  s.push(make_pair(-1, 1));

  s64 sum_x{0};
  while (!s.empty()) {
    auto [prv, cur] = s.top();
    if (open[cur]) {
      s.pop();
      sum_x -= xs[cur];
      continue;
    }

    open[cur] = true;
    sum_x += xs[cur];
    cnts[cur] += sum_x;

    for (auto nxt : graph[cur]) {
      if (nxt == prv) continue;
      s.push(make_pair(cur, nxt));
    }
  }

  for (s64 i{1}; i <= n; ++i) {
    cout << cnts[i];
    if (i < n) cout << " ";
  }
  cout << endl;
}