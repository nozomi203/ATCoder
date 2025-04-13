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
  s64 cnt{0};
  bool login{false};
  for (s64 i{0}; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "login") {
      login = true;
    } else if (s == "logout") {
      login = false;
    } else if (s == "public") {
    } else {
      if (!login) ++cnt;
    }
  }
  cout << cnt << endl;
}
