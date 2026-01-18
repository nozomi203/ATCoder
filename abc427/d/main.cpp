#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, s64, string, vector<pair<s64, s64>>>> cases(t);
  for (auto& [n, m, k, s, uvs] : cases) {
    cin >> n >> m >> k;
    cin >> s;
    uvs.resize(m);
    util::cin(uvs);
  }

  for (const auto& [n, m, k, s, uvs] : cases) {
    // dp[i][j] = あとi回操作可能で頂点jにいるときAが勝つか
    vector<vector<bool>> dp(2 * k + 1, vector<bool>(n));
    vector<vector<s64>> g(n);
    for (auto [u, v] : uvs) {
      g[u - 1].push_back(v - 1);
    }
    for (s64 j = 0; j < n; ++j) {
      dp[0][j] = s[j] == 'A';
    }
    for (s64 i = 1; i <= 2 * k; ++i) {
      const bool isa = i % 2 == 0;
      for (s64 j = 0; j < n; ++j) {
        if (isa) {
          bool wina = false;
          for (s64 nxt : g[j]) {
            if (dp[i - 1][nxt]) {
              wina = true;
              break;
            }
          }
          dp[i][j] = wina;
        } else {
          bool wina = true;
          for (s64 nxt : g[j]) {
            if (!dp[i - 1][nxt]) {
              wina = false;
              break;
            }
          }
          dp[i][j] = wina;
        }
      }
    }

    cout << (dp[2 * k][0] ? "Alice" : "Bob") << endl;
  }
}