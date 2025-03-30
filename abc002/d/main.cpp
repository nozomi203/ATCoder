#include "util/common.h"
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<vector<bool>> peer(n + 1, vector<bool>(n + 1));
  for (s64 i{0}; i < m; ++i) {
    s64 x, y;
    cin >> x >> y;
    peer[x][y] = peer[y][x] = true;
  }

  s64 ans{0};
  for (s64 b{0}; b < (1 << n); ++b) {
    vector<s64> members;
    for (s64 i{1}; i <= n; ++i) {
      if (b & (1 << (i - 1))) members.push_back(i);
    }
    if (members.empty()) continue;
    bool cnt{false};
    for (s64 i{0}; i < members.size() - 1; ++i) {
      for (s64 j{i + 1}; j < members.size(); ++j) {
        if (!peer[members[i]][members[j]]) {
          cnt = true;
          break;
        }
      }
      if (cnt) break;
    }
    if (cnt) continue;
    ans = max<s64>(ans, members.size());
  }
  cout << ans << endl;
}