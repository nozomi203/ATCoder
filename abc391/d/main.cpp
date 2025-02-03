#include "util/common.h"

int main() {
  // input
  u64 N, W;
  cin >> N >> W;
  vector<pair<s64, s64>> blk_positions(
      N + 1);  // positions[i] = position of block i
  for (s64 i = 1; i <= N; ++i) {
    cin >> blk_positions[i].first >> blk_positions[i].second;
  }
  s64 Q;
  cin >> Q;
  vector<pair<s64, s64>> queries(Q);
  for (s64 i = 0; i < Q; ++i) {
    cin >> queries[i].first >> queries[i].second;
  }

  vector<vector<s64>> blk_idxs_per_col(
      W + 1);  // blocks[i][j] = <j>th block from bottom in <i>th column
  for (u64 i = 1; i <= N; ++i) {
    blk_idxs_per_col[blk_positions[i].first].push_back(i);
  }
  size_t del_cnt{N};
  for (s64 i = 1; i <= W; ++i) {
    sort(blk_idxs_per_col[i].begin(), blk_idxs_per_col[i].end(),
         [&](s64 blk_idx_l, s64 blk_idx_r) {
           return blk_positions[blk_idx_l].second <
                  blk_positions[blk_idx_r].second;
         });
    del_cnt = min(del_cnt, blk_idxs_per_col[i].size());
  }

  vector<u64> ttd(N + 1, numeric_limits<u64>::max());  // time to delete
  vector<u64> ttr(N + 1, numeric_limits<u64>::max());  // time to reach bottom

  if (del_cnt > 0) {
    u64 ttr_max{0};
    for (s64 i = 1; i <= W; ++i) {
      const auto blk_idx = blk_idxs_per_col[i].front();
      ttr[blk_idx] = blk_positions[blk_idx].second - 1;
      ttr_max = max(ttr_max, ttr[blk_idx]);
    }
    for (s64 i = 1; i <= W; ++i) {
      const auto blk_idx = blk_idxs_per_col[i].front();
      ttd[blk_idx] = ttr_max + 1;
    }
  }

  for (s64 row_idx = 1; row_idx < del_cnt; ++row_idx) {
    u64 ttr_max{0};
    for (s64 i = 1; i <= W; ++i) {
      const auto blk_idx = blk_idxs_per_col[i][row_idx];
      const auto blk_idx_prv = blk_idxs_per_col[i][row_idx - 1];
      ttr[blk_idx] = blk_positions[blk_idx].second - 1 >
                             ttd[blk_idx_prv] + blk_positions[blk_idx].second -
                                 blk_positions[blk_idx_prv].second
                         ? ttd[blk_idx_prv]
                         : blk_positions[blk_idx].second - 1;
      ttr_max = max(ttr_max, ttr[blk_idx]);
    }
    for (s64 i = 1; i <= W; ++i) {
      const auto blk_idx = blk_idxs_per_col[i][row_idx];
      ttd[blk_idx] = ttr_max + 1;
    }
  }

  // output
  for (const auto& [T, A] : queries) {
    cout << (ttd[A] <= T ? "No" : "Yes") << endl;
  }
}