#include <atcoder/fenwicktree>

#include "util/common.h"

using graph = vector<vector<s64>>;
void calc_ccnts(const graph& g, vector<s64>& ccnts, s64 idx) {
  ccnts[idx] = 1;
  for (auto cidx : g[idx]) {
    calc_ccnts(g, ccnts, cidx);
    ccnts[idx] += ccnts[cidx];
  }
}

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> uvs(n);
  for (s64 i{0}; i < n - 1; ++i) cin_pair(uvs[i]);

  s64 q;
  cin >> q;
  vector<tuple<s64, s64, s64>> queries(q);
  for (s64 i{0}; i < q; ++i) {
    auto& [t, x, w] = queries[i];
    cin >> t;
    if (t == 1) {
      cin >> x >> w;
    } else {
      cin >> x;
    }
  }

  vector<vector<s64>> g(n + 1);
  for (auto [u, v] : uvs) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<s64> idxs(n + 1);
  vector<s64> seq;
  seq.reserve(n);
  {
    stack<pair<s64, s64>> s;
    s.push(make_pair(-1, 1));
    while (!s.empty()) {
      auto [prv, cur] = s.top();
      s.pop();

      idxs[cur] = seq.size();
      seq.push_back(cur);

      for (auto it = g[cur].begin(); it != g[cur].end();) {
        if (*it == prv) {
          it = g[cur].erase(it);
        } else {
          s.push(make_pair(cur, *it));
          ++it;
        }
      }
    }
  }

  vector<s64> ccnts(n + 1);
  calc_ccnts(g, ccnts, 1);

  atcoder::fenwick_tree<s64> ft(n);
  for (s64 i{0}; i < n; ++i) ft.add(i, 1);

  for (auto [t, x, w] : queries) {
    if (t == 1) {
      ft.add(idxs[x], w);
    } else {
      auto [u, v] = uvs[x - 1];
      if (idxs[u] > idxs[v]) swap(u, v);
      const size_t l{idxs[v]}, r{idxs[v] + ccnts[v]};
      const s64 csum = ft.sum(l, r);
      const s64 sum = ft.sum(0, n);
      const s64 ans = abs(sum - 2 * csum);
      cout << ans << endl;
    }
  }
}