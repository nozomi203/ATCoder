#include "util/common.h"

int main() {
  u64 n, m;
  cin >> n >> m;
  struct conn {
    u64 to_idx;
    u64 w;
  };
  vector<vector<conn>> conns(n + 1);
  for (s64 i{0}; i < m; ++i) {
    u64 u, v, w;
    cin >> u >> v >> w;
    conns[u].push_back(conn{v, w});
    conns[v].push_back(conn{u, w});
  }

  struct work {
    u64 idx;
    u64 val;
    u64 visited;
  };

  u64 ans{numeric_limits<u64>::max()};
  stack<work> works;
  works.push(work{1, 0, 1 << 1});
  while (!works.empty()) {
    const auto w = works.top();
    works.pop();
    if (w.idx == n) {
      ans = min(ans, w.val);
      continue;
    }
    for (const auto& conn : conns[w.idx]) {
      if ((w.visited & (1 << conn.to_idx)) == 0) {
        works.push(
            work{conn.to_idx, w.val ^ conn.w, w.visited | (1 << conn.to_idx)});
      }
    }
  }

  cout << ans << endl;
}