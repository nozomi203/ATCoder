#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xys(n + 2);
  for (s64 i{1}; i <= n; ++i) cin >> xys[i].first >> xys[i].second;
  double ans{0.0};
  for (s64 i{1}; i <= n + 1; ++i) {
    s64 dx = xys[i].first - xys[i - 1].first;
    s64 dy = xys[i].second - xys[i - 1].second;
    ans += sqrt(dx * dx + dy * dy);
  }
  cout << fixed << setprecision(15) << ans << endl;
}
