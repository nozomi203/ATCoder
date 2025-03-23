#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

// memo
// there is x possible operations at first.
// if x is odd, first player wins.
// if x is even, second player wins.

int main() {
  s64 n;
  cin >> n;
  vector<vector<bool>> connected(n, vector<bool>(n, false));
  vector<vector<s64>> g(n);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    connected[u][v] = connected[v][u] = true;
  }

  vector<bool> flags(n, false);
  queue<pair<s64, s64>> q;
  q.push(make_pair(-1, 0));
  while (!q.empty()) {
    auto [prv_idx, cur_idx] = q.front();
    q.pop();
    for (auto it = g[cur_idx].begin(); it != g[cur_idx].end();) {
      if (*it == prv_idx) {
        it = g[cur_idx].erase(it);
      } else {
        q.push(make_pair(cur_idx, *it));
        flags[*it] = !flags[cur_idx];
        ++it;
      }
    }
  }

  set<pair<s64, s64>> ops;
  for (s64 i{0}; i < n - 1; ++i) {
    for (s64 j{i + 1}; j < n; ++j) {
      if (connected[i][j]) continue;

      if (flags[i] != flags[j]) ops.emplace(make_pair(i, j));
    }
  }
  bool my_turn = ops.size() % 2 > 0;
  cout << (my_turn ? "First" : "Second") << endl;
  while (true) {
    if (my_turn) {
      auto op = *ops.begin();
      ops.erase(op);
      cout << op.first + 1 << " " << op.second + 1 << endl;
    } else {
      pair<s64, s64> op;
      cin >> op.first >> op.second;
      if (op.first == -1 && op.second == -1) {
        break;
      }
      --op.first;
      --op.second;
      ops.erase(op);
    }
    my_turn = !my_turn;
  }
}
