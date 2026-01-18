#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> pvs(n);
  util::cin(pvs);

  vector<vector<s64>> dp(n, vector<s64>(m + 1));
  vector<vector<u64>> dp2(n, vector<u64>(m + 1));
  for (s64 j = 0; j <= m; ++j) {
    dp[0][j] = pvs[0].first <= j ? pvs[0].second : 0;
    dp2[0][j] = pvs[0].first <= j ? 2 : 1;
  }
  for (s64 i = 1; i < n; ++i) {
    for (s64 j = 0; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      dp2[i][j] = 1;
      if (j >= pvs[i].first) {
        const s64 val = dp[i - 1][j - pvs[i].first] + pvs[i].second;
        if (dp[i][j] == val) {
          dp[i][j] = val;
          dp2[i][j] = 3;
        } else if (dp[i][j] < val) {
          dp[i][j] = val;
          dp2[i][j] = 2;
        }
      }
    }
  }
  vector<vector<bool>> visited(n, vector<bool>(m + 1));
  vector<u64> ans(n);
  queue<pair<s64, s64>> q;
  q.push(make_pair(n - 1, m));
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (visited[i][j]) continue;
    visited[i][j] = true;
    ans[i] |= dp2[i][j];
    if (i == 0) continue;
    if (dp2[i][j] & 1) {
      q.push(make_pair(i - 1, j));
    }
    if (dp2[i][j] & 2) {
      q.push(make_pair(i - 1, j - pvs[i].first));
    }
  }

  for (u64 a : ans) {
    if (a == 1) {
      cout << 'C';
    } else if (a == 2) {
      cout << 'A';
    } else if (a == 3) {
      cout << 'B';
    } else {
      assert(false);
    }
  }
  cout << endl;
}