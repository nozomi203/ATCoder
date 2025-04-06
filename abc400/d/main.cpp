#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> f(h);
  for (s64 i{0}; i < h; ++i) cin >> f[i];

  pair<s64, s64> s, g;
  cin >> s.first >> s.second >> g.first >> g.second;
  vector<vector<s64>> dists(h, vector<s64>(w, numeric_limits<s64>::max()));
  dists[s.first][s.second] = 0;
  priority_queue<pair<s64, pair<s64, s64>>> q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    auto [d, pos] = q.top();
    q.pop();
    const pair<s64, s64> diffs[] = {
        make_pair(0, 1),
        make_pair(0, -1),
        make_pair(1, 0),
        make_pair(-1, 0),
    };
    for (const auto& diff : diffs) {
      const auto next_h = pos.first + diff.first;
      const auto next_w = pos.second + diff.second;
    }
  }
}