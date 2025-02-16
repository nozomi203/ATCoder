#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, M;
  cin >> N >> M;
  size_t ans{0};
  set<pair<s64, s64>> e;
  for (s64 i = 0; i < M; ++i) {
    s64 v1, v2;
    cin >> v1 >> v2;
    if (v1 > v2) swap(v1, v2);
    if (v1 == v2 || e.contains(make_pair(v1, v2))) {
      ++ans;
    } else {
      e.emplace(make_pair(v1, v2));
    }
  }

  cout << ans << endl;
}
