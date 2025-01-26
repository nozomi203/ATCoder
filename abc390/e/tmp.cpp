#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, X;
  cin >> N >> X;
  vector<vector<vector<s32>>> dp(N + 1,
                                 vector<vector<s32>>(X + 1, vector<s32>(3, 0)));
  for (s64 i = 1; i <= N; ++i) {
    s32 V, A, C;
    cin >> V >> A >> C;
    --V;

    for (s64 j = 1; j <= X; ++j) {
      for (s64 k = 0; k < 3; ++k) {
        if (k != V || j < C) {
          dp[i][j][k] = dp[i - 1][j][k];
          continue;
        }
        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - C][k] + A);
      }
    }
  }
  // dp2[i][j] = 栄養jを合計カロリーiいないで摂取した時の摂取量
  //   vector<vector<s32>> dp2(X + 1, vector<s32>(3, 0));
  //   for (s64 i = 1; i <= X; ++i) {
  //     for (s64 j = 0; j < 3; ++j) {
  //       dp2[i][j] = max(dp2[i - 1][j], dp[N][i][j]);
  //     }
  //   }

  vector<pair<s32, s32>> ac(3, {0, 0});  // 各栄養の摂取量とカロリー
  while (ac[0].second + ac[1].second + ac[2].second < X) {
    // index of minimum amount nutrition
    const u64 min_idx = distance(
        ac.begin(),
        min_element(ac.begin(), ac.end(), [](const auto& l, const auto& r) {
          return l.first < r.first;
        }));

    ++ac[min_idx].second;
    ac[min_idx].first = dp[N][ac[min_idx].second][min_idx];
  }

  cout << (min_element(
               ac.begin(), ac.end(),
               [](const auto& l, const auto& r) { return l.first < r.first; })
               ->first)
       << endl;
}
