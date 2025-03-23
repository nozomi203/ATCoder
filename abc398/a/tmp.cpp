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
  if (n % 2) {
    for (s64 i{0}; i < n / 2; ++i) cout << '-';
    cout << '=';
    for (s64 i{0}; i < n / 2; ++i) cout << '-';
  } else {
    for (s64 i{0}; i < n / 2 - 1; ++i) cout << '-';
    cout << "==";
    for (s64 i{0}; i < n / 2 - 1; ++i) cout << '-';
  }
  cout << endl;
}
