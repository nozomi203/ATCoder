#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

using graph = vector<vector<pair<s64, s64>>>;

s64 djikstra(const graph& g, s64 from, s64 to) {
  constexpr auto inf = numeric_limits<s64>::max();
  vector<s64> dists(g.size(), inf);
  priority_queue<s64, vector<s64>, greater<s64>> q;
  q.push(from);
  dists[from] = 0;
  while (!q.empty()) {
    auto cur = q.top();
    q.pop();
    for (auto [nxt_d, nxt] : g[cur]) {
      if (dists[cur] + nxt_d < dists[nxt]) {
        dists[nxt] = dists[cur] + nxt_d;
        q.push(nxt);
      }
    }
  }

  return dists[to] == inf ? -1 : dists[to];
}

int main() {
  s64 n, k;
  cin >> n >> k;

  graph g(n + 1);

  vector<s64> ans;

  for (s64 i{0}; i < k; ++i) {
    s64 q;
    cin >> q;
    if (q == 0) {
      s64 a, b;
      cin >> a >> b;
      ans.push_back(djikstra(g, a, b));
    } else {
      s64 c, d, e;
      cin >> c >> d >> e;
      g[c].push_back(make_pair(e, d));
      g[d].push_back(make_pair(e, c));
    }
  }

  for (auto a : ans) cout << a << endl;
}
