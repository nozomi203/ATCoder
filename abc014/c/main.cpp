#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n;
  cin >> n;
  vector<s64> cnts(1000002);
  for (s64 i{0}; i < n; ++i) {
    s64 a, b;
    cin >> a >> b;
    ++cnts[a];
    --cnts[b + 1];
  }
  s64 ans{0};
  s64 val{0};
  for (s64 i{0}; i < 1000001; ++i) {
    val += cnts[i];
    ans = max(ans, val);
  }
  cout << ans << endl;
}