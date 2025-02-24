#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string S;
  cin >> S;
  for (auto itr = S.begin(); itr != S.end();) {
    if (*itr != '2') {
      itr = S.erase(itr);
    } else {
      ++itr;
    }
  }

  cout << S << endl;
}
