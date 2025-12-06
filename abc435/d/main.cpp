#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> xys(m);
  util::cin(xys);
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> queries(q);
  util::cin(queries);

  vector<vector<s64>> g(n + 1);
  for (auto [x, y] : xys) {
    g[y].push_back(x);
  }

  vector<bool> bs(n + 1, false);

  for (auto [q0, q1] : queries) {
    if (q0 == 1) {
      stack<s64> s;
      s.push(q1);
      while (!s.empty()) {
        s64 cur = s.top();
        s.pop();
        if (bs[cur]) continue;
        bs[cur] = true;
        for (auto nxt : g[cur]) {
          if (bs[nxt]) continue;
          s.push(nxt);
        }
      }
    } else {
      cout << (bs[q1] ? "Yes" : "No") << endl;
    }
  }
}