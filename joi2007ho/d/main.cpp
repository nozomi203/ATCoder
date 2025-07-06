#include "util/common.h"
#include "util/topological_sort.h"

int main() {
  s64 n;
  cin >> n;
  s64 m;
  cin >> m;
  vector<pair<s64, s64>> xys(m);
  util::cin(xys);
  vector<vector<size_t>> g(n + 1), g_inv(n + 1);
  for (auto [x, y] : xys) {
    g[x].push_back(y);
    g_inv[y].push_back(x);
  }

  auto [success, vec] = util::topological_sort(g);
  vector<s64> idxs(n + 1, -1);
  for (auto v : vec) {
    for (auto o : g_inv[v]) {
      idxs[v] = max(idxs[v], idxs[o] + 1);
    }
  }

  map<s64, vector<s64>> mp;
  for (s64 i = 1; i <= n; ++i) {
    mp[idxs[i]].push_back(i);
  }
  bool b = false;
  for (const auto& [val, vec] : mp) {
    if (vec.size() > 1) b = true;
    for (auto v : vec) cout << v << endl;
  }
  cout << (b ? 1 : 0) << endl;
}