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
  vector<vector<s64>> ss(m);
  for (s64 i{0}; i < m; ++i) {
    s64 k;
    cin >> k;
    ss[i].resize(k);
    for (s64 j{0}; j < k; ++j) cin >> ss[i][j];
  }
  vector<s64> p(m);
  for (s64 i{0}; i < m; ++i) cin >> p[i];

  s64 ans{0};
  for (s64 b{0}; b < (1 << n); ++b) {
    bool cnt{false};
    for (s64 i{0}; i < m; ++i) {
      s64 on{0};
      for (s64 s : ss[i]) {
        if (b & (1 << (s - 1))) ++on;
      }
      if (on % 2 != p[i]) {
        cnt = true;
        break;
      }
    }
    if (cnt) continue;
    ++ans;
  }
  cout << ans << endl;
}
