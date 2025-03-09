#include "util/common.h"

int main() {
  s64 n, s, t;
  cin >> n >> s >> t;
  struct line {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
  };
  vector<line> lines(n);
  for (s64 i{0}; i < n; ++i)
    cin >> lines[i].a >> lines[i].b >> lines[i].c >> lines[i].d;

  vector<s64> idxs(n);
  for (s64 i{0}; i < n; ++i) idxs[i] = i;

  double min_time{numeric_limits<double>::max()};
  do {
    for (s64 dir_bit{0}; dir_bit <= (1 << n) - 1; ++dir_bit) {
      double time{0.0};
      pair<s64, s64> pos = make_pair(0, 0);
      for (auto idx : idxs) {
        const pair<s64, s64> from = (dir_bit & (1 << idx)) > 0
                                        ? make_pair(lines[idx].a, lines[idx].b)
                                        : make_pair(lines[idx].c, lines[idx].d);
        const pair<s64, s64> to = (dir_bit & (1 << idx)) > 0
                                      ? make_pair(lines[idx].c, lines[idx].d)
                                      : make_pair(lines[idx].a, lines[idx].b);
        time += sqrt((pos.first - from.first) * (pos.first - from.first) +
                     (pos.second - from.second) * (pos.second - from.second)) /
                s;
        time += sqrt((from.first - to.first) * (from.first - to.first) +
                     (from.second - to.second) * (from.second - to.second)) /
                t;
        pos = to;
      }
      min_time = min(min_time, time);
    }
  } while (next_permutation(idxs.begin(), idxs.end()));

  cout << fixed << setprecision(15) << min_time << endl;
}