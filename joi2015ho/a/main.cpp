#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> p(m);
  for (s64 i{0}; i < m; ++i) cin >> p[i];
  vector<s64> a(n), b(n), c(n);
  for (s64 i{1}; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
}