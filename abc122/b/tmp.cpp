#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
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
  size_t ans{0};
  size_t r{0};
  for (size_t l{0}; l < s.size(); ++l) {
    r = max(r, l);
    while (r < s.size() &&
           (s[r] == 'A' || s[r] == 'C' || s[r] == 'G' || s[r] == 'T'))
      ++r;
    ans = max(ans, r - l);
  }

  cout << ans << endl;
}
