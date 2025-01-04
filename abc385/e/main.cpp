#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<vector<s64>> conns(N + 1);
  for (s64 i = 0; i < N - 1; ++i) {
    s64 u, v;
    cin >> u >> v;
    conns[u].push_back(v);
    conns[v].push_back(u);
  }

  for (auto& conn : conns) {
    std::sort(conn.begin(), conn.end(), [&conns](auto l, auto r) {
      return conns[l].size() > conns[r].size();
    });
  }
  s64 ans{std::numeric_limits<s64>::max()};
  for (s64 i = 1; i <= N; ++i) {
    for (s64 x = 1; x <= conns[i].size(); ++x) {
      s64 y = conns[conns[i][x - 1]].size() - 1;
      ans = std::min(ans, N - 1 - x - x * y);
    }
  }

  cout << ans << endl;
}