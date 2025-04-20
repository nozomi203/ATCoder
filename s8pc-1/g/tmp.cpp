#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  struct node {
    s64 to;
    s64 d;
    s64 time;
  };
  vector<vector<node>> nodes(n);
  for (s64 i{0}; i < m; ++i) {
    s64 s, t, d, time;
    nodes[s - 1].push_back(node{t - 1, d, time});
    nodes[t - 1].push_back(node{s - 1, d, time});
  }
  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<s64>> dp((1 << n), vector<s64>(n + 1, inf));
  dp[1][0] = 0;
  for (s64 i{2}; i < (1 << n); ++i) {
    for (s64 j{0}; j < n; ++j) {
      if (!(i & (1 << j))) continue;
      for (const auto& node : nodes[j]) {
        if (!(i & (1 << node.to))) continue;
        const auto time = dp[i & ~(1 << j)][node.to] + node.d;
        if (time > node.time) continue;
        dp[i][j] = min(dp[i][j], time);
      }
    }
  }

  cout << dp[(1 << n) - 1][]
}
