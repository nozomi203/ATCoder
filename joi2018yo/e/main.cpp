#include "util/common.h"

int main() {
  s32 h, w;
  cin >> h >> w;
  vector<vector<s64>> ass(h, vector<s64>(w));
  util::cin(ass);

  const pair<s64, s64> dijs[] = {
      make_pair(0, 1),
      make_pair(0, -1),
      make_pair(1, 0),
      make_pair(-1, 0),
  };

  constexpr auto inf = numeric_limits<s64>::max();
  vector<vector<vector<s64>>> dp(
      h, vector<vector<s64>>(w, vector<s64>(h * w, inf)));

  using elem_t = tuple<s64, s64, s64, s64>;
  priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
  pq.push(make_tuple(0, 0, 0, 0));
  while (!pq.empty()) {
    const auto [t, i, j, d] = pq.top();
    pq.pop();
    if (t >= dp[i][j][d]) continue;

    dp[i][j][d] = t;

    if (d + 1 >= h * w) continue;

    for (const auto [di, dj] : dijs) {
      const auto ni = i + di;
      const auto nj = j + dj;
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      const auto nt = dp[i][j][d] + (2 * d + 1) * ass[ni][nj];
      if (nt >= dp[ni][nj][d + 1]) continue;
      pq.push(make_tuple(nt, ni, nj, d + 1));
    }
  }

  cout << *min_element(dp[h - 1][w - 1].begin(), dp[h - 1][w - 1].end())
       << endl;
}