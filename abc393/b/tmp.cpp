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
  size_t ans{0};
  for (size_t i = 0; i < S.size(); ++i) {
    if (S[i] != 'A') continue;
    for (size_t w = 1; w < S.size(); ++w) {
      if (i + 2 * w >= S.size()) continue;
      if (S[i + w] == 'B' && S[i + 2 * w] == 'C') ++ans;
    }
  }

  cout << ans << endl;
}
