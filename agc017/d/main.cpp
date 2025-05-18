#include "util/common.h"

using graph = vector<vector<s64>>;
u64 get_grundy(const graph& g, s64 cur) {
  u64 ret{0};
  for (auto nxt : g[cur]) {
    ret ^= 1 + get_grundy(g, nxt);
  }
  return ret;
}

int main() {
  s64 n;
  cin >> n;
  graph g(n);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  {
    queue<pair<s64, s64>> q;
    q.push(make_pair(-1, 0));
    while (!q.empty()) {
      auto [prv, cur] = q.front();
      q.pop();
      for (auto it = g[cur].begin(); it != g[cur].end();) {
        if (*it == prv) {
          it = g[cur].erase(it);
        } else {
          q.push(make_pair(cur, *it));
          ++it;
        }
      }
    }
  }

  u64 grundy{get_grundy(g, 0)};
  if (grundy == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}