#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> x(n);
  for (s64 i{0}; i < n; ++i) cin >> x[i];
  s64 l, q;
  cin >> l >> q;
  vector<pair<s64, s64>> abs(q);
  for (s64 i{0}; i < q; ++i) {
    cin >> abs[i].first >> abs[i].second;
    --abs[i].first;
    --abs[i].second;
  }

  // dbl[i][j] = iから2^j日移動したときに到達できる最大のホテル
  vector<vector<s64>> dbl(n, vector<s64>(32));
  for (s64 i{0}; i < n; ++i) {
    const auto it = lower_bound(x.begin(), x.end(), x[i] + l + 1);
    dbl[i][0] = distance(x.begin(), prev(it));
  }
  for (s64 i{1}; i < 32; ++i) {
    for (s64 j{0}; j < n; ++j) {
      dbl[j][i] = dbl[dbl[j][i - 1]][i - 1];
    }
  }

  for (auto [a, b] : abs) {
    if (a > b) swap(a, b);
    s64 sum_day{0};
    s64 loc{a};
    while (loc < b) {
      s64 pow{0};
      while (dbl[loc][pow + 1] < b) ++pow;
      sum_day += (1 << pow);
      loc = dbl[loc][pow];
    }
    cout << sum_day << endl;
  }
}