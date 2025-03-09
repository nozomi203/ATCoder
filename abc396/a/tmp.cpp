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
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  const auto check = [&]() -> bool {
    s64 cnt{0};
    s64 val{a[0]};
    for (s64 i{0}; i < n; ++i) {
      if (a[i] == val) {
        if (++cnt >= 3) return true;
      } else {
        cnt = 1;
        val = a[i];
      }
    }
    return false;
  };

  cout << (check() ? "Yes" : "No") << endl;
}
