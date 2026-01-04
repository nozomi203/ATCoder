#include "util/common.h"

/*
dp[i] =
Bの最大値がi以下になるようにタコを揚げたときの人数の最大値と、その時最も右側のAの最小値
*/

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);
  sort(abs.begin(), abs.end(),
       [](pair<s64, s64> abl, pair<s64, s64> abr) -> bool {
         if (abl.first < abr.first) {
           return true;
         } else if (abl.first == abr.first) {
           return abl.second > abr.second;
         } else {
           return false;
         }
       });

  vector<s64> dp;
  dp.reserve(n);
  dp.push_back(abs[0].second);
  for (s64 i = 1; i < n; ++i) {
    auto [a, b] = abs[i];
    if (dp.back() < b) {
      dp.push_back(b);
    } else {
      auto it = lower_bound(dp.begin(), dp.end(), b);
      *it = b;
    }
  }
  cout << dp.size() << endl;
}
