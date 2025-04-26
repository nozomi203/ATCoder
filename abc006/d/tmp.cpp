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
  vector<s64> c(n);
  for (s64 i{0}; i < n; ++i) cin >> c[i];
  constexpr auto ninf = numeric_limits<s64>::lowest();
  s64 cnt{0};
  vector<s64> dp;
  for (s64 i{0}; i < n; ++i) {
    const auto v = c[i];
    if (dp.empty() || dp.back() < v) {
      dp.push_back(v);
    } else {
      const auto it = lower_bound(dp.begin(), dp.end(), v);
      if (*it > v) *it = v;
    }
  }
 cout << n - dp.size() << endl; 
}
