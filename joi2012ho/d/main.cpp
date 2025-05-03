#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(m), b(m), x(m);
  for (s64 i{0}; i < m; ++i) cin >> a[i] >> b[i] >> x[i];

  vector<vector<s32>> in_cnt(n + 1, vector<s32>(n + 1));
  vector<vector<s32>> r_cnt(n + 1, vector<s32>(n + 1));
  vector<vector<s32>> in_sub_cnt(n + 1, vector<s32>(n + 2));
  vector<vector<s32>> r_sub_cnt(n + 1, vector<s32>(n + 2));

  for (s64 i{0}; i < m; ++i) {
    ++in_cnt[a[i]][b[i]];
    ++r_cnt[a[i]][b[i]];
    ++in_sub_cnt[a[i] + x[i]][b[i]];
    --in_sub_cnt[a[i] + x[i]][b[i] + x[i] + 1];
    ++r_sub_cnt[a[i] + x[i]][b[i] + x[i]];
  }

  for (s64 i{1}; i < n; ++i) {
    s64 in_sub_sum{0};
    for (s64 j{1}; j <= i; ++j) {
      in_sub_sum += in_sub_cnt[i][j];
      in_cnt[i + 1][j] += in_cnt[i][j] - in_sub_sum;
      in_cnt[i + 1][j + 1] += r_cnt[i][j] - r_sub_cnt[i][j];
      r_cnt[i + 1][j + 1] += r_cnt[i][j] - r_sub_cnt[i][j];
    }
  }

  s64 ans{0};
  for (s64 i{1}; i <= n; ++i) {
    for (s64 j{1}; j <= i; ++j) {
      if (in_cnt[i][j]) ++ans;
    }
  }
  cout << ans << endl;
}