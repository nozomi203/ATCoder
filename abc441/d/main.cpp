#include "util/common.h"

int main() {
  s64 n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;
  vector<tuple<s64, s64, s64>> uvcs(m);
  util::cin(uvcs);

  vector<vector<pair<s64, s64>>> g(n + 1);
  for (auto [u, v, c] : uvcs) {
    g[u].push_back(make_pair(v, c));
  }

  set<s64> ans;
  stack<tuple<s64, s64, s64>> stk;
  for (auto [nxt, c] : g[1]) {
    stk.push(tuple<s64, s64, s64>(nxt, 1, c));
  }
  while (!stk.empty()) {
    auto [cur, num, cst] = stk.top();
    stk.pop();
    if (num == l) {
      if (s <= cst && cst <= t) {
        ans.emplace(cur);
      }
    } else {
      for (auto [nxt, c] : g[cur]) {
        stk.push(make_tuple(nxt, num + 1, cst + c));
      }
    }
  }

  {
    s64 i = 0;
    for (auto a : ans) {
      cout << a;
      if (i < ans.size() - 1) cout << " ";
      ++i;
    }
  }
  cout << endl;
}