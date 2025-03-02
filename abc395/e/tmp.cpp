#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, M, X;
  cin >> N >> M >> X;
  struct edge {
    s64 node_idx;
    s64 weight;
  };

  vector<vector<edge>> conns(2 * N + 1);
  for (s64 i = 0; i < M; ++i) {
    s64 u, v;
    cin >> u >> v;
    conns[u].push_back(edge{v, 1});
    conns[N + v].push_back(edge{N + u, 1});
  }
  for (s64 i = 1; i <= N; ++i) {
    conns[i].push_back(edge{N + i, X});
    conns[N + i].push_back(edge{i, X});
  }

  vector<s64> dists(2 * N + 1, numeric_limits<s64>::max());
  priority_queue<pair<s64, s64>, vector<pair<s64, s64>>,
                 greater<pair<s64, s64>>>
      pq;
  dists[1] = 0;
  pq.push(make_pair(0, 1));
  while (!pq.empty()) {
    const auto [dist, idx] = pq.top();
    pq.pop();
    if (dists[idx] < dist) continue;
    for (const auto& conn : conns[idx]) {
      if (dists[conn.node_idx] > dists[idx] + conn.weight) {
        dists[conn.node_idx] = dists[idx] + conn.weight;
        pq.push(make_pair(dists[conn.node_idx], conn.node_idx));
      }
    }
  }

  cout << min(dists[N], dists[2 * N]) << endl;
}
