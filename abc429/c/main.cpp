#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  map<s64, s64> m;
  for (auto a : as) ++m[a];

  s64 ans = 0;
  for (auto [v, cnt] : m) {
    ans += (n - cnt) * cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
}