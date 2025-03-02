#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  map<s64, pair<s64 /* last appear */, s64 /* min value */>> m;
  s64 ans{-1};
  for (s64 i = 0; i < N; ++i) {
    s64 A;
    cin >> A;
    if (m.count(A) == 0) {
      m[A] = make_pair(i, numeric_limits<s64>::max());
    } else {
      m[A].second = min(m[A].second, i - m[A].first + 1);
      m[A].first = i;
      ans = ans < 0 ? m[A].second : min(ans, m[A].second);
    }
  }

  cout << ans << endl;
}
