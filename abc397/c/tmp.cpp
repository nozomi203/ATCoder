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

  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  map<s64, s64> l, r;
  l[a[0]]++;
  for (s64 i{1}; i < n; ++i) r[a[i]]++;

  s64 ans{l.size() + r.size()};
  for (s64 i{1}; i < n - 1; ++i) {
    r[a[i]]--;
    if (r[a[i]] == 0) r.erase(a[i]);
    l[a[i]]++;
    ans = max<s64>(ans, l.size() + r.size());
  }

  cout << ans << endl;
}
