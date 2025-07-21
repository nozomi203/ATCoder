#include "util/common.h"

int main() {
  s32 h, w;
  cin >> h >> w;
  vector<vector<s32>> ass(h, vector<s32>(w));
  util::cin(ass);

  const pair<s32, s32> dijs[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  constexpr auto inf = numeric_limits<s32>::max();
  vector<vector<vector<s32>>> dp(
      h, vector<vector<s32>>(w, vector<s32>(h * w, inf)));
  dp[0][0][0] = 0;

  vector<vector<bool>> opened(h, vector<bool>(w));
  stack<tuple<s32, s32, s32>> s;
  s.push(make_tuple(0, 0, 0));
  while (!s.empty()) {
    auto [d, i, j] = s.top();
    if (opened[i][j]) {
      opened[i][j] = false;
      s.pop();
    } else {
      opened[i][j] = true;

      if (d + 1 >= h * w) continue;
      if (i == h - 1 && j == w - 1) continue;
      for (const auto [di, dj] : dijs) {
        const auto ni = i + di;
        const auto nj = j + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (opened[ni][nj]) continue;
        const auto t = dp[i][j][d] + ass[ni][nj] * (d * 2 + 1);
        if (t >= dp[ni][nj][d + 1]) continue;
        dp[ni][nj][d + 1] = t;
        s.push(make_tuple(d + 1, ni, nj));
      }
    }
  }

  cout << *min_element(dp[h - 1][w - 1].begin(), dp[h - 1][w - 1].end())
       << endl;
}