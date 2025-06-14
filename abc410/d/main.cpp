#include "util/common.h"
/*
W<2^10なので10ビットしか考えなくていい。全探索
*/
int main() {
  size_t n, m;
  cin >> n >> m;
  vector<tuple<size_t, size_t, size_t>> abws(m);
  for (size_t i{0}; i < m; ++i) cin_tuple(abws[i]);

  constexpr size_t xormax = 1ULL << 10;
  vector<vector<bool>> possible(n + 1, vector<bool>(xormax, false));

  vector<vector<pair<size_t, size_t>>> g(n + 1);
  for (auto [a, b, w] : abws) g[a].push_back(make_pair(b, w));
  possible[1][0] = true;
  using work = pair<size_t, size_t>;
  queue<work> q;
  q.push(make_pair(1, 0));
  while (!q.empty()) {
    auto [cur, val] = q.front();
    q.pop();
    for (auto [bnxt, wnxt] : g[cur]) {
      if (possible[bnxt][wnxt ^ val]) continue;
      possible[bnxt][wnxt ^ val] = true;
      q.push(make_pair(bnxt, wnxt ^ val));
    }
  }

  for (size_t i{0}; i < xormax; ++i) {
    if (possible[n][i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
