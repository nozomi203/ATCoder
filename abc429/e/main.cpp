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

  queue<pair<s64, s64>> que;
  for (s64 i = 0; i < n; ++i) {
    if (s[i] == 'S') {
      logs[i].first.dist = 0;
      logs[i].first.idx = i;
      que.push(make_pair(i, i));
    }
  }

  while (!que.empty()) {
    const auto [cur, from] = que.front();
    que.pop();

    const log_t& cur_log = logs[cur].second.idx == idx_invalid
                               ? logs[cur].first
                               : logs[cur].second;

    for (s64 nxt : g[cur]) {
      if (logs[nxt].second.idx != idx_invalid) continue;
      if (logs[nxt].first.idx == cur) continue;
      log_t& nxt_log = logs[nxt].first.idx == idx_invalid ? logs[nxt].first
                                                          : logs[nxt].second;
      nxt_log.dist = cur_log.dist + 1;
      nxt_log.idx = from;
      que.push(make_pair(nxt, from));
    }
  }

  for (s64 i = 0; i < n; ++i) {
    if (s[i] == 'D') {
      cout << logs[i].first.dist + logs[i].second.dist << endl;
    }
  }
}