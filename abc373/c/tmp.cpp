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
  vector<s64> a(n), b(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  for (s64 i{0}; i < n; ++i) cin >> b[i];
  cout << *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end())
       << endl;
}
