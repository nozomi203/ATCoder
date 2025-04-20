#include <bits/stdc++.h>

#include <atcoder/fenwicktree>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, m;
  cin >> n >> m;

  atcoder::fenwick_tree<s64> ft(m);
  vector<s64> k(m);
  vector<vector<s64>> t(n + 1);
  for (s64 i{0}; i < m; ++i) {
    cin >> k[i];
    for (s64 j{0}; j < k[i]; ++j) {
      s64 a;
      cin >> a;
      t[a].push_back(i);
    }
    if (!k[i]) ft.add(i, 1);
  }

  vector<s64> answers(n);
  for (s64 i{0}; i < n; ++i) {
    s64 b;
    cin >> b;
    for (auto v : t[b]) {
      --k[v];
      if (!k[v]) ft.add(v, 1);
    }
    answers[i] = ft.sum(0, m);
  }

  for (auto ans : answers) cout << ans << endl;
}