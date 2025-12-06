#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;

  vector<pair<s64, s64>> abs(n);
  util::cin(abs);

  vector<pair<s64, s64>> numsizes(m + 1);
  for (auto [a, b] : abs) {
    numsizes[a].first++;
    numsizes[a].second += b;
  }

  for (s64 i = 1; i <= m; ++i) {
    auto [num, size] = numsizes[i];
    const double ave = size / (double)num;
    cout << fixed << setprecision(10) << ave << endl;
  }
}