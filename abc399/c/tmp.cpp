#line 1 "main.cpp"
#include <atcoder/dsu>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;

  s64 ans{0};

  atcoder::dsu dsu(n + 1);
  for (s64 i{0}; i < m; ++i) {
    s64 u, v;
    cin >> u >> v;
    if (dsu.leader(u) == dsu.leader(v)) {
      ++ans;
    } else {
      dsu.merge(u, v);
    }
  }

  cout << ans << endl;
}
