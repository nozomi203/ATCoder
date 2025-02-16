#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
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
  s64 ans{0};
  s64 t_prv{0};
  for (s64 i = 0; i < N; ++i) {
    s64 T, V;
    cin >> T >> V;
    ans = max<s64>(0, ans - (T - t_prv));
    ans += V;
    t_prv = T;
  }
  cout << ans << endl;
}
