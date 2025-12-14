#include "util/cartesian_tree.h"
#include "util/common.h"
#include "util/sparse_table.h"

/*
k回操作を行った後の猫の位置をiとする。
iから移動可能な範囲を[l,r]とすると、p[i]はp[l...r]の中で最高峰になっている
この繰り返し
*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> ps(n);
  util::cin(ps);
#if 0
  vector<s64> idxs(n + 1, -1);
  for (s64 i = 0; i < n; ++i) idxs[ps[i]] = i;

  util::sparse_table<s64, [](s64 l, s64 r) { return max(l, r); }> st(ps);

  vector<s64> dp(n);

  // ls[i] =
  // ps[j...i]がすべてps[i]以下となる最小のjを選んだ時、ps[j...i-1]の最大値
  vector<s64> ls(n, -1), rs(n, -1);
  for (s64 i = 1; i < n; ++i) {
    if (st.query(0, i - 1) < ps[i]) {
      ls[i] = st.query(0, i - 1);
      continue;
    }
    if (ps[i - 1] > ps[i]) {
      ls[i] = -1;
      continue;
    }

    s64 ll = 0;
    s64 lr = i - 1;
    while (lr - ll > 1) {
      s64 lm = (ll + lr) / 2;
      if (st.query(lm, i - 1) > ps[i]) {
        ll = lm;
      } else {
        lr = lm;
      }
    }
    ls[i] = st.query(lr, i - 1);
  }
  for (s64 i = n - 2; i >= 0; --i) {
    if (st.query(i + 1, n - 1) < ps[i]) {
      rs[i] = st.query(i + 1, n - 1);
      continue;
    }
    if (ps[i + 1] > ps[i]) {
      rs[i] = -1;
      continue;
    }

    s64 ll = i + 1;
    s64 lr = n - 1;
    while (lr - ll > 1) {
      s64 lm = (ll + lr) / 2;
      if (st.query(i + 1, lm) > ps[i]) {
        lr = lm;
      } else {
        ll = lm;
      }
    }
    rs[i] = st.query(i + 1, ll);
  }

  for (s64 i = 1; i <= n; ++i) {
    const s64 idx = idxs[i];
    const s64 l = ls[idx];
    const s64 r = rs[idx];

    dp[idx] = 0;
    if (l >= 0) dp[idx] = max(dp[idx], dp[idxs[l]] + (idx - idxs[l]));
    if (r >= 0) dp[idx] = max(dp[idx], dp[idxs[r]] + (idxs[r] - idx));
  }

  cout << dp[idxs[n]] << endl;
#endif

  util::cartesian_tree<s64, [](s64 l, s64 r) -> bool { return (l < r); }> ct(
      ps);

  const auto get = [&](auto& self, s64 idx) -> s64 {
    s64 ret = 0;
    if (ct.get_l(idx) != -1) {
      const s64 idxl = ct.get_l(idx);
      ret = max(ret, self(self, idxl) + (idx - idxl));
    }
    if (ct.get_r(idx) != -1) {
      const s64 idxr = ct.get_r(idx);
      ret = max(ret, self(self, idxr) + (idxr - idx));
    }
    return ret;
  };

  cout << get(get, ct.get_root()) << endl;
}