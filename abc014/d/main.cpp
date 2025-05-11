#include "util/common.h"
#include "util/sparse_table.h"
int main() {
  s64 n;
  cin >> n;
  using graph = vector<vector<s64>>;
  graph g(n + 1);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> abs(q);
  for (s64 i{0}; i < q; ++i) cin >> abs[i].first >> abs[i].second;

  vector<s64> depth(n + 1, numeric_limits<s64>::max());
  {
    depth[1] = 0;
    stack<s64> s;
    s.push(1);
    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      for (auto it_nxt{g[cur].begin()}; it_nxt != g[cur].end();) {
        auto nxt = *it_nxt;
        if (depth[nxt] < depth[cur]) {
          it_nxt = g[cur].erase(it_nxt);
          continue;
        }
        depth[nxt] = depth[cur] + 1;
        s.push(nxt);
        ++it_nxt;
      }
    }
  }

  // euler tour
  vector<s64> f(n + 1, -1);
  vector<pair<s64, s64>> seq;
  stack<s64> s;
  s.push(1);
  while (!s.empty()) {
    auto cur = s.top();
    s.pop();
    if (f[cur] < 0) {
      f[cur] = seq.size();
      for (auto nxt : g[cur]) {
        s.push(cur);
        s.push(nxt);
      }
    }
    seq.push_back(make_pair(depth[cur], cur));
  }
  util::sparse_table<pair<s64, s64>,
                     [](const pair<s64, s64>& v0,
                        const pair<s64, s64>& v1) -> pair<s64, s64> {
                       return v0.first < v1.first ? v0 : v1;
                     }>
      st(seq);

  for (auto [a, b] : abs) {
    auto fa{f[a]}, fb{f[b]};
    if (fa > fb) swap(fa, fb);
    cout << depth[a] + depth[b] - 2 * st.query(fa, fb).first + 1 << endl;
  }
}