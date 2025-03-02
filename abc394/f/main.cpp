#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<vector<s64>> conns(N + 1);
  for (s64 i = 0; i < N - 1; ++i) {
    s64 A, B;
    cin >> A >> B;
    conns[A].push_back(B);
    conns[B].push_back(A);
  }

  const auto get_ans = [&]() -> s64 {
    vector<s64> dp(N + 1), alkan(N + 1);
    s64 root_idx = 1;
    struct work {
      s64 idx;
      s64 parent_idx;
      bool open;
    };
    stack<work> works;
    works.push(work{root_idx, -1, false});
    while (!works.empty()) {
      auto& w = works.top();
      if (w.open) {
        if (conns[w.idx].size() < 3) {
          dp[w.idx] = 1;
        } else {
          vector<s64> cands;
          for (auto conn_idx : conns[w.idx]) {
            cands.push_back(dp[conn_idx]);
          }
          sort(cands.begin(), cands.end(), greater());
          dp[w.idx] = 1 + cands[0] + cands[1] + cands[2];
          alkan[w.idx] = true;
        }
        works.pop();
      } else {
        w.open = true;
        for (auto it = conns[w.idx].begin(); it != conns[w.idx].end();) {
          if (*it == w.parent_idx) {
            it = conns[w.idx].erase(it);
          } else {
            works.push(work{*it, w.idx, false});
            ++it;
          }
        }
      }
    }

    s64 ans{0};
    for (s64 i = 1; i <= N; ++i) {
      if (conns[i].empty()) continue;
      vector<s64> cands;
      for (auto conn_idx : conns[i]) {
        cands.push_back(dp[conn_idx]);
      }
      sort(cands.begin(), cands.end(), greater());
      auto val = cands.size() < 4
                     ? 1 + cands[0]
                     : 1 + cands[0] + cands[1] + cands[2] + cands[3];
      ans = max(ans, val);
    }

    return ans > 2 ? ans : -1;
  };

  cout << get_ans() << endl;
}