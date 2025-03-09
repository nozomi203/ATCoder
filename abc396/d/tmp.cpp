#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

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
