#include "util/common.h"
#include "util/rerooting_dp.h"

/*
危険な頂点Diについて一番近い安全な頂点S0とその次に近いS1を求める。
Diに直接Sjがつながっている場合は簡単。
DiにDjがつながっている場合はどうするか。木DP?

各ノードに、最も近い安全な頂点とその距離を持った木を考える
*/
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> uvs(m);
  util::cin(uvs);
  string s;
  cin >> s;

  constexpr s64 inf = numeric_limits<s64>::max();

  vector<vector<s64>> g(n);
  for (auto [u, v] : uvs) {
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  constexpr s64 idx_invalid = -1;
  constexpr s64 dist_invalid = -1;

  struct log_t {
    s64 dist{dist_invalid};
    s64 idx{idx_invalid};
  };
  vector<pair<log_t, log_t>> logs(n);

  queue<pair<s64, log_t>> que;
  for (s64 i = 0; i < n; ++i) {
    if (s[i] == 'S') {
      que.push(make_pair(i, log_t{0, i}));
    }
  }

  while (!que.empty()) {
    const auto [cur, log] = que.front();
    que.pop();

    if (logs[cur].second.idx != idx_invalid) continue;
    if (logs[cur].first.idx == idx_invalid) {
      logs[cur].first = log;
    } else {
      if (logs[cur].first.idx == log.idx) continue;
      logs[cur].second = log;
    }

    for (s64 nxt : g[cur]) {
      if (logs[nxt].second.idx != idx_invalid) continue;
      que.push(make_pair(nxt, log_t{log.dist + 1, log.idx}));
    }
  }

  for (s64 i = 0; i < n; ++i) {
    if (s[i] == 'D') {
      cout << logs[i].first.dist + logs[i].second.dist << endl;
    }
  }
}