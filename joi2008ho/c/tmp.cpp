#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> p(n + 1);
  for (s64 i{1}; i <= n; ++i) cin >> p[i];
  vector<s64> p2;
  p2.reserve((n + 1) * (n + 1));
  for (s64 i{0}; i <= n; ++i) {
    for (s64 j{0}; j <= n; ++j) {
      p2.push_back(p[i] + p[j]);
    }
  }
  sort(p2.begin(), p2.end());

  s64 ans{0};
  for (s64 i{0}; i < p2.size(); ++i) {
    const auto a{p2[i]};
    auto it = lower_bound(p2.begin(), p2.end(), m - a + 1);
    if (it == p2.begin()) continue;
    const auto b{*prev(it)};
    ans = max(ans, a + b);
  }
  cout << ans << endl;
}
