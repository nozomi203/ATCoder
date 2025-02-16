#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  string S;
  cin >> S;

  s64 one_cnt{0};
  vector<s64> one_indices;
  for (s64 i = 0; i < N; ++i) {
    if (S[i] == '1') {
      one_indices.push_back(i);
      ++one_cnt;
    }
  }
  s64 ans{0};
  const s64 center_idx{one_indices[one_cnt / 2]};
  for (s64 i = 0; i < one_cnt; ++i) {
    ans += abs(center_idx - one_indices[i]) - abs(one_cnt / 2 - i);
  }
  cout << ans << endl;
}