#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);
  sort(abs.begin(), abs.end(),
       [](const auto& l, const auto& r) { return l.second > r.second; });

  vector<pair<s64, s64>> minsums(
      n, make_pair(numeric_limits<s64>::max(), numeric_limits<s64>::max()));
  minsums[0].first = abs[0].first + abs[0].second;
  for (s64 i = 1; i < n; ++i) {
    s64 sum = abs[i].first + abs[i].second;
    if (sum <= minsums[i - 1].first) {
      minsums[i].first = sum;
      minsums[i].second = minsums[i - 1].first;
    } else {
      minsums[i].first = minsums[i - 1].first;
      minsums[i].second = min(minsums[i - 1].second, sum);
    }
  }

  s64 ans = numeric_limits<s64>::max();
  for (s64 i = 2; i < n; ++i) {
    s64 time = minsums[i - 1].first + minsums[i - 1].second + abs[i].first;
    ans = min(ans, time);
  }
  cout << ans << endl;
}