#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> s(n + 1);
  for (s64 i{1}; i <= n - 1; ++i) {
    cin >> s[i + 1];
    s[i + 1] += s[i];
  }
  s64 ans{0};
  s64 cur{1};
  for (s64 i{0}; i < m; ++i) {
    s64 a;
    cin >> a;
    ans += abs(s[cur + a] - s[cur]);
    ans = ans % 100000;
    cur += a;
  }
  cout << ans << endl;
}