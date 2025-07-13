#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, vector<pair<s64, s64>>>> cases(t);
  for (auto& [n, k, uvs] : cases) {
    cin >> n >> k;
    uvs.resize(n - 1);
    util::cin(uvs);
  }

  for (auto& [n, k, uvs] : cases) {
    // cnts[i][j] = count of visit i with jth step
    vector<vector<pair<s64, size_t>>> g(n);
    for (size_t i = 0; i < n - 1; ++i) {
      auto& [u, v] = uvs[i];
      --u;
      --v;
      g[u].push_back(make_pair(v, 2 * i));
      g[v].push_back(make_pair(u, 2 * i + 1));
    }

    constexpr auto inf = numeric_limits<s64>::max();
    vector<s64> answers(n, inf);
    vector<vector<s64>> cnts(n, vector<s64>(k));

    vector<vector<s64>> dp(2 * (n - 1), vector<s64>(k, inf));
    deque<tuple<s64, s64, size_t>> dq;
    dq.push_back(make_tuple(0, 0, numeric_limits<size_t>::max()));
    while (!dq.empty()) {
      const auto [d, v, e] = dq.front();
      dq.pop_front();

      if (d % k == 0 && answers[v] == inf) {
        answers[v] = d / k;
      }

      if (cnts[v][d % k] == 2) continue;

      ++cnts[v][d % k];

      for (auto [vnxt, enxt] : g[v]) {
        if ((e ^ enxt) == 1 && d % k != 0) continue;
        if (dp[enxt][(d + 1) % k] != inf) continue;
        dq.push_back(make_tuple(d + 1, vnxt, enxt));
        dp[enxt][(d + 1) % k] = d + 1;
      }
    }

    for (s64 i = 1; i < n; ++i) {
      cout << (answers[i] == inf ? -1 : answers[i]);
      if (i < n - 1) cout << " ";
    }
    cout << endl;
  }
}