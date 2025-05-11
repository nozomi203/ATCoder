
#include "util/common.h"
#include "util/sparse_table.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  for (s64 i{0}; i < m; ++i) cin >> abs[i].first >> abs[i].second;
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> cds(q);
  for (s64 i{0}; i < q; ++i) cin >> cds[i].first >> cds[i].second;

  vector<s64> imos(2 * n + 1);
  for (auto [a, b] : abs) {
    ++imos[a];
    --imos[b];
  }
  for (s64 i{0}; i < 2 * n; ++i) {
    imos[i + 1] += imos[i];
  }
  util::sparse_table<s64, [](s64 v0, s64 v1) { return min(v0, v1); }> st(imos);
  for (auto [c, d] : cds) {
    const s64 v0{st.query(c, c)};
    const s64 v1{st.query(d, d)};
    const s64 vmin{st.query(c, d)};
    cout << v0 + v1 - 2 * vmin << endl;
  }
}