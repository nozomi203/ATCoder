#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  map<s64, s64> cnts;
  for (s64 i{0}; i < 7; ++i) {
    s64 a;
    cin >> a;
    ++cnts[a];
  }

  s64 num3{0}, num2{0};
  for (auto& [val, cnt] : cnts) {
    if (cnt >= 3) ++num3;
    if (cnt >= 2) ++num2;
  }

  cout << (num3 >= 1 && num2 >= 2 ? "Yes" : "No") << endl;
}
