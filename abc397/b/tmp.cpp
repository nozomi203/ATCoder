#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string s;
  cin >> s;
  s64 ans{0};
  bool i{true};
  for (char c : s) {
    if (i) {
      if (c != 'i') {
        ++ans;
      } else {
        i = !i;
      }
    } else {
      if (c != 'o') {
        ++ans;
      } else {
        i = !i;
      }
    }
  }
  if ((ans + s.size()) % 2) ++ans;
  cout << ans << endl;
}
