#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
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
  s64 ans{0};
  s64 cnt{0};
  while (cnt < S.size()) {
    if (cnt < S.size() - 1 && S[cnt] == '0' && S[cnt + 1] == '0') {
      cnt += 2;
      ++ans;
    } else {
      ++cnt;
      ++ans;
    }
  }

  cout << ans << endl;
}
