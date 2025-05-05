#include "util/common.h"

int main() {
  s64 m;
  cin >> m;
  vector<pair<s64, s64>> dcs(m);
  for (s64 i{0}; i < m; ++i) cin >> dcs[i].first >> dcs[i].second;
  // dbl[i][j][k] iにjを2^k回作用させた時の操作数と最終的な値のペア
  vector<vector<vector<pair<s64, s64>>>> dbl(
      10, vector<vector<pair<s64, s64>>>(10, vector<pair<s64, s64>>(64)));
  for (s64 i{0}; i < 10; ++i) {
    for (s64 j{0}; j < 10; ++j) {
      s64 sum{i + j};
      s64 num{1};
      if (sum > 9) {
        sum = sum / 10 + sum % 10;
        ++num;
      }
      dbl[i][j][0] = make_pair(num, sum);
    }
  }

  for (s64 k{1}; k < 64; ++k) {
    for (s64 i{0}; i < 10; ++i) {
      for (s64 j{0}; j < 10; ++j) {
        auto [num, sum] = dbl[i][j][k - 1];
        auto [num2, sum2] = dbl[sum][j][k - 1];
        dbl[i][j][k] = make_pair(num + num2, sum2);
      }
    }
  }

  s64 sum{dcs.back().first};
  if (--dcs.back().second == 0) dcs.pop_back();

  s64 num{0};
  for (s64 i{m - 1}; i >= 0; --i) {
    for (s64 j{0}; j < 64; ++j) {
      if (dcs[i].second & (1ll << j)) {
        auto [num2, sum2] = dbl[sum][dcs[i].first][j];

        sum = sum2;
        num += num2;
      }
    }
  }
  cout << num << endl;
}