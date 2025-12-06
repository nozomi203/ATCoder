#include "util/common.h"

/*
行iの最大値はX[i]
列iの最大値はY[i]

最大値は絶対XYのどちらにも表れる
XYどちらにもある→座標確定
XYどちらかにある→行or列確定
確定していないほうは、
*/

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, vector<s64>, vector<s64>>> cases(t);
  for (auto& [n, m, xs, ys] : cases) {
    cin >> n >> m;
    xs.resize(n);
    ys.resize(m);
    util::cin(xs);
    util::cin(ys);
  }

  const auto solve = [](s64 n, s64 m, vector<s64> xs, vector<s64> ys) {
    set<s64> sx, sy;
    for (auto x : xs) {
      if (sx.contains(x)) {
        cout << "No" << endl;
        return;
      }
      sx.emplace(x);
    }
    for (auto y : ys) {
      if (sy.contains(y)) {
        cout << "No" << endl;
        return;
      }
      sy.emplace(y);
    }

    map<s64, map<s64, pair<s64, s64>>> mmp;
    for (s64 i = 0; i < n; ++i) {
      for (s64 j = 0; j < m; ++j) {
        mmp[xs[i]][ys[j]] = make_pair(i, j);
      }
    }

    vector<vector<s64>> ret(n, vector<s64>(m));

    for (s64 i = n * m; i >= 1; --i) {
      auto itx = mmp.lower_bound(i);
      if (itx == mmp.end()) {
        cout << "No" << endl;
        return;
      }
      auto& mp = itx->second;
      auto ity = mp.lower_bound(i);
      if (ity == mp.end()) {
        cout << "No" << endl;
        return;
      }
      auto [x, y] = ity->second;
      assert(ret[x][y] == 0);
      ret[x][y] = i;
      mp.erase(ity);
      if (mp.empty()) mmp.erase(itx);
    }

    cout << "Yes" << endl;
    for (s64 i = 0; i < n; ++i) {
      for (s64 j = 0; j < m; ++j) {
        cout << ret[i][j];
        if (j < m - 1) cout << " ";
      }
      cout << endl;
    }
  };

  for (auto& [n, m, xs, ys] : cases) {
    solve(n, m, xs, ys);
  }
}