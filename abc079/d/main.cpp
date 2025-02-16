#include "util/common.h"

int main() {
  size_t H, W;
  cin >> H >> W;
  vector<vector<size_t>> c(10, vector<size_t>(10));
  for (size_t i = 0; i <= 9; ++i) {
    for (size_t j = 0; j <= 9; ++j) {
      cin >> c[i][j];
    }
  }

  const auto dijkstra = [&](size_t s, size_t g) {
    vector<size_t> dists(10, 100000);
    struct node {
      size_t idx;
      size_t dist;
    };
    struct comp {
      bool operator()(const node& l, const node& r) { return l.dist < r.dist; }
    };
    priority_queue<node, vector<node>, comp> q;
    q.push(node{s, 0});
    dists[s] = 0;
    while (!q.empty()) {
      node n = q.top();
      q.pop();
      for (size_t i = 0; i <= 9; ++i) {
        if (c[n.idx][i] < 0) continue;
        if (dists[i] > n.dist + c[n.idx][i]) {
          dists[i] = n.dist + c[n.idx][i];
          q.push(node{i, dists[i]});
        }
      }
    }
    return dists[g];
  };

  size_t ans{0};
  for (size_t i = 0; i < H; ++i) {
    for (size_t j = 0; j < W; ++j) {
      s32 a;
      cin >> a;
      if (a >= 0) ans += dijkstra(a, 1);
    }
  }

  cout << ans << endl;
}