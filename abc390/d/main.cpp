#include "util/common.h"

void check(unordered_set<s64>& s, vector<s64>& a, vector<s64>& group_sum,
           s64 idx, s64 max_group, s64 val) {
  for (s64 g = 0; g <= max_group; ++g) {
    val ^= group_sum[g];
    group_sum[g] += a[idx];
    val ^= group_sum[g];
    if (idx == a.size() - 1) {
      s.emplace(val);
    } else if (g < max_group) {
      check(s, a, group_sum, idx + 1, max_group, val);
    } else {
      check(s, a, group_sum, idx + 1, max_group + 1, val);
    }
    val ^= group_sum[g];
    group_sum[g] -= a[idx];
    val ^= group_sum[g];
  }
}

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N), group_sum(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];

  unordered_set<s64> s;
  check(s, A, group_sum, 0, 0, 0);
  cout << s.size() << endl;
}