#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<pair<s64, s64>> conns(n * k - 1);
  for (s64 i{0}; i < n * k - 1; ++i) cin >> conns[i].first >> conns[i].second;

  struct node {
    s64 p_idx{-1};
    vector<s64> c_idxs;
    bool open{false};
    s64 sum_cnt{0};
    s64 c_cnt{0};
  };
  vector<node> nodes(n * k + 1);
  for (auto conn : conns) {
    nodes[conn.first].c_idxs.push_back(conn.second);
    nodes[conn.second].c_idxs.push_back(conn.first);
  }

  const auto check = [&]() -> bool {
    stack<s64> s;
    s.push(1);
    while (!s.empty()) {
      auto idx = s.top();

      if (nodes[idx].open) {
        s.pop();
        nodes[idx].sum_cnt += 1;
        if (nodes[idx].c_cnt < 2) {
          nodes[idx].sum_cnt = nodes[idx].sum_cnt % k;
        } else if (nodes[idx].c_cnt == 2) {
          if (nodes[idx].sum_cnt != k) return false;
          nodes[idx].sum_cnt = 0;
        } else {
          return false;
        }

        if (nodes[idx].p_idx > 0) {
          if (nodes[idx].sum_cnt) ++nodes[nodes[idx].p_idx].c_cnt;
          nodes[nodes[idx].p_idx].sum_cnt += nodes[idx].sum_cnt;
        }
      } else {
        nodes[idx].open = true;
        for (auto c_idx : nodes[idx].c_idxs) {
          if (c_idx == nodes[idx].p_idx) continue;
          nodes[c_idx].p_idx = idx;
          s.push(c_idx);
        }
      }
    }

    return nodes[1].sum_cnt == 0;
  };

  cout << (check() ? "Yes" : "No") << endl;
}