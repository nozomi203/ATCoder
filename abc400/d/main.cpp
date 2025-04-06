#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<vector<char>> f(h + 1, vector<char>(w + 1));
  for (s64 i{1}; i <= h; ++i) {
    string s;
    cin >> s;
    for (s64 j{1}; j <= w; ++j) {
      f[i][j] = s[j - 1];
    }
  }

  pair<s64, s64> s, g;
  cin >> s.first >> s.second >> g.first >> g.second;
  vector<vector<s64>> dists(h + 1,
                            vector<s64>(w + 1, numeric_limits<s64>::max()));
  dists[s.first][s.second] = 0;
  deque<pair<s64, pair<s64, s64>>> q;
  q.push_back(make_pair(0, s));
  while (!q.empty()) {
    auto [d, pos] = q.front();
    q.pop_front();

    const pair<s64, s64> diffs[] = {
        make_pair(0, 1),
        make_pair(0, -1),
        make_pair(1, 0),
        make_pair(-1, 0),
    };
    for (const auto& diff : diffs) {
      bool wall{false};
      const auto func = [&](s64 next_h, s64 next_w) {
        if (next_h <= 0 || h < next_h || next_w <= 0 || w < next_w) return;
        wall = wall || (f[next_h][next_w] == '#');
        auto next_d = d + (wall ? 1 : 0);
        if (next_d >= dists[next_h][next_w]) return;
        dists[next_h][next_w] = next_d;
        if (wall) {
          q.push_back(make_pair(next_d, make_pair(next_h, next_w)));
        } else {
          q.push_front(make_pair(next_d, make_pair(next_h, next_w)));
        }
      };

      func(pos.first + diff.first, pos.second + diff.second);
      func(pos.first + diff.first * 2, pos.second + diff.second * 2);
    }
  }

  cout << dists[g.first][g.second] << endl;
}