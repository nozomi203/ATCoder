#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 ans{0};
  for (s64 i{1}; i <= 12; ++i) {
    string s;
    cin >> s;
    if (s.size() == i) ++ans;
  }
  cout << ans << endl;
}
