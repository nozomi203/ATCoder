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

    for (const auto [di, dj] : dijs) {
      const auto ni = i + di;
      const auto nj = j + dj;
      if (i < 0 || i >= h || j < 0 || j >= w) continue;
    }
  }
}