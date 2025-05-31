#include <atcoder/maxflow.hpp>

#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  s64 cnt{0};
  s64 is, it;
  vector<vector<s64>> a(h, vector<s64>(w, -1));
  for (s64 i{0}; i < h; ++i) {
    string s;
    cin >> s;
    for (s64 j{0}; j < w; ++j) {
      if (s[j] == 'o') {
        a[i][j] = cnt++;
      } else if (s[j] == 'S') {
        a[i][j] = cnt++;
        is = a[i][j];
      } else if (s[j] == 'T') {
        a[i][j] = cnt++;
        it = a[i][j];
      }
    }
  }
  atcoder::mf_graph<s64> mfg(2 * cnt);

  constexpr s64 inf = 1000000;
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (a[i][j] < 0) continue;
      for (s64 k{0}; k < w; ++k) {
        if (a[i][k] < 0) continue;
        if (j == k) continue;
        const s64 cost = (a[i][j] == is && a[i][k] == it) ? inf : 1;
        mfg.add_edge(a[i][j], a[i][k] + cnt, cost);
      }
      for (s64 k{0}; k < h; ++k) {
        if (a[k][j] < 0) continue;
        if (i == k) continue;
        const s64 cost = (a[i][j] == is && a[k][j] == it) ? inf : 1;
        mfg.add_edge(a[i][j], a[k][j] + cnt, cost);
      }
    }
  }

  for (s64 i{0}; i < cnt; ++i) {
    const s64 cost = (i == is || i == it) ? inf : 1;
    mfg.add_edge(i + cnt, i, cost);
  }

  const auto f = mfg.flow(is + cnt, it);
  cout << (f >= inf ? -1 : f) << endl;
}