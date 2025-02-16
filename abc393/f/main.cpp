#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];
  struct query {
    s64 r;
    s64 x;
    s64 idx;
  };
  vector<query> q(Q);
  for (s64 i = 0; i < Q; ++i) {
    cin >> q[i].r >> q[i].x;
    --q[i].r;
    q[i].idx = i;
  }
  sort(q.begin(), q.end(),
       [](const auto& l, const auto& r) { return l.r < r.r; });

  vector<s64> answers(Q);

  vector<s64> dp;
  size_t q_idx{0};
  for (s64 i = 0; i < N; ++i) {
    const auto [ok, ng] = util::binary_search<s64>(-1, dp.size(), [&](s64 val) {
      if (val < 0) return true;
      if (val >= dp.size()) return false;
      return dp[val] < A[i];
    });

    if (ng >= dp.size()) {
      dp.push_back(A[i]);
    } else {
      dp[ng] = A[i];
    }

    while (q_idx < q.size() && q[q_idx].r == i) {
      const auto [ok, ng] =
          util::binary_search<s64>(-1, dp.size(), [&](s64 val) {
            if (val < 0) return true;
            if (val >= dp.size()) return false;
            return dp[val] <= q[q_idx].x;
          });

      answers[q[q_idx].idx] = ng;
      ++q_idx;
    }
  }

  for (auto ans : answers) {
    cout << ans << endl;
  }
}