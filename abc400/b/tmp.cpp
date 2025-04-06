#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
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
  s64 x{0};
  s64 mul{1};
  for (s64 i{0}; i <= m; ++i) {
    x += mul;
    mul *= n;
    if (x > 1000000000) {
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << x << endl;
}
