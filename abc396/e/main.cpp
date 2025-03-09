#include <atcoder/all>

#include "util/common.h"

int main() {
  u64 n, m;
  cin >> n >> m;

  struct node {
    u64 to;
    u64 z;
  };
  vector<vector<node>> nodes(n + 1);
  atcoder::dsu dsu(n + 1);
  for (s64 i{0}; i < m; ++i) {
    u64 x, y, z;
    cin >> x >> y >> z;
    nodes[x].push_back(node{y, z});
    nodes[y].push_back(node{x, z});
    dsu.merge(x, y);
  }

  vector<s64> roots;
  {
    vector<bool> checked(n + 1, false);
    for (const auto group : dsu.groups()) {
      roots.push_back(group.front());
      queue<pair<s64, s64>> q;
      q.push({-1, group.front()});
      while (!q.empty()) {
        const auto [pidx, cidx] = q.front();
        q.pop();
        checked[cidx] = true;
        for (auto it = nodes[cidx].begin(); it != nodes[cidx].end();) {
          if (it->to == pidx) {
            it = nodes[cidx].erase(it);
          } else {
            if (!checked[it->to]) {
              q.push({cidx, it->to});
            }
            ++it;
          }
        }
      }
    }
  }
}