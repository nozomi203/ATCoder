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
  vector<vector<s64>> a(n, vector<s64>(m));
  for (s64 i{0}; i < n; ++i) {
    for (s64 j{0}; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  s64 ans{0};
  for (s64 i{0}; i < m; ++i) {
    for (s64 j{0}; j < m; ++j) {
      s64 score{0};
      for (s64 k{0}; k < n; ++k) {
        score += max(a[k][i], a[k][j]);
      }
      ans = max(ans, score);
    }
  }
  cout << ans << endl;
}
