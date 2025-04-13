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
  set<pair<s64, s64>> uvs;
  for (s64 i{0}; i < m; ++i) {
    s64 u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    uvs.emplace(make_pair(u, v));
  }

  atcoder::dsu dsu(n + 1);
  map<s64, vector<s64>> rem;
  for (s64 i{1}; i <= n; ++i) {
    for (auto it = rem.begin(); it != rem.end();) {
      if (it->first <= i) {
        for (auto sec : it->second) {
          dsu.merge(it->first, sec);
        }
        it = rem.erase(it);
      } else {
        break;
      }
    }
    for (auto it = uvs.begin(); it != uvs.end();) {
      if (it->first <= i) {
        if (it->second <= i) {
          dsu.merge(it->first, it->second);
        } else {
          rem[it->second].push_back(it->first);
        }
        it = uvs.erase(it);

      } else {
        break;
      }
    }
    if (dsu.size(1) == i) {
      cout << rem.size() << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
