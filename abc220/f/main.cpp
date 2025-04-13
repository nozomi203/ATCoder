#include "util/common.h"

int main() {
  s64 n;
  cin >> n;

  struct edge {
    s64 to;
  };

  struct node {
    s64 cnt;
    s64 sum_depth;
    vector<edge> edges;
  };

  vector<node> g(n);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 u, v;
    cin >> u >> v;
    g[u - 1].edges.push_back(edge{v - 1});
    g[v - 1].edges.push_back(edge{u - 1});
  }

  {
    vector<bool> open(n);
    stack<pair<s64, s64>> s;
    s.push(make_pair(-1, 0));
    while (!s.empty()) {
      auto [prv, cur] = s.top();
      if (open[cur]) {
        s.pop();
        if (prv >= 0) {
          g[prv].cnt += g[cur].cnt;
          g[prv].sum_depth += g[cur].sum_depth + g[cur].cnt;
        }
      } else {
        g[cur].cnt = 1;
        g[cur].sum_depth = 0;
        open[cur] = true;
        for (const auto& e : g[cur].edges) {
          if (e.to == prv) continue;
          s.push(make_pair(cur, e.to));
        }
      }
    }
  }
  queue<pair<s64, s64>> q;
  q.push(make_pair(-1, 0));
  while (!q.empty()) {
    const auto [prv, cur] = q.front();
    q.pop();
    if (prv >= 0) {
      g[cur].sum_depth +=
          (g[prv].sum_depth - g[cur].sum_depth) + g[prv].cnt - 2 * g[cur].cnt;
      g[cur].cnt += (g[prv].cnt - g[cur].cnt);
    }
    for (const auto& edge : g[cur].edges) {
      if (edge.to == prv) continue;
      q.push(make_pair(cur, edge.to));
    }
  }

  for (s64 i{0}; i < n; ++i) {
    cout << g[i].sum_depth << endl;
  }
}