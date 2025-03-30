#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
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
  vector<s64> abs(n * 2);
  for (s64 i{0}; i < n; ++i) cin >> abs[i * 2] >> abs[i * 2 + 1];

  s64 ans{numeric_limits<s64>::max()};
  for (s64 si{0}; si < n * 2; ++si) {
    for (s64 gi{0}; gi < n * 2; ++gi) {
      s64 s{abs[si]};
      s64 g{abs[gi]};
      if (s > g) continue;
      s64 val{0};
      for (s64 i{0}; i < n; ++i) {
        s64 a{abs[i * 2]};
        s64 b{abs[i * 2 + 1]};
        val += std::abs(s - a) + (b - a) + std::abs(b - g);
      }
      ans = min(ans, val);
    }
  }
  cout << ans << endl;
}
