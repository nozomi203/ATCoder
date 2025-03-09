#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, Q;
  cin >> N >> Q;

  s64 ans{0};
  s64 pl{1}, pr{2};
  for (s64 i{0}; i < Q; ++i) {
    char H;
    s64 T;
    cin >> H >> T;
    auto& ps = H == 'L' ? pl : pr;
    auto& po = H == 'L' ? pr : pl;
    if (ps < T) {
      ans += (ps < po && po < T) ? N - (T - ps) : T - ps;
    } else if (ps > T) {
      ans += (T < po && po < ps) ? N - (ps - T) : ps - T;
    }
    ps = T;
  }
  cout << ans << endl;
}
