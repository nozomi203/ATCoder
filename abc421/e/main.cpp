#include <atcoder/math>

#include "util/common.h"

/*
dp[i][j] =
あとi回サイコロを振れるとき、キープしているサイコロの目の集合がjであるときの期待値の最大値
*/
int main() {
  map<s64, s64> m;
  for (s64 i = 0; i < 6; ++i) {
    s64 a;
    cin >> a;
    ++m[a];
  }
  vector<pair<s64, s64>> as(m.size());
  {
    s64 i = 0;
    for (auto [v, n] : m) as[i++] = make_pair(v, n);
  }

  vector<map<multiset<s64>, float>> dp(3);
  for (s64 i = 0; i < 3; ++i) {
    const s64 bmax = atcoder::pow_mod(as.size() + 1, 5, 100000000);
    for (s64 b = 0; b < bmax; ++b) {
      multiset<s64> s;
      {
        s64 tmp = b;
        for (s64 j = 0; j < 5; ++j) {
          const s64 rem = tmp % (as.size() + 1);
          tmp /= as.size() + 1;
          if (rem > 0) {
            s.emplace(rem - 1);
          }
        }
      }
      if (dp[i].count(s)) continue;
      float& e = dp[i][s];
        }
  }
}