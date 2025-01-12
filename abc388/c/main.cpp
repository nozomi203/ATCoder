#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
  }

  s64 ans{0};
  s64 idx_r{1};
  for (s64 idx_l = 0; idx_l < N - 1; ++idx_l) {
    while (idx_r < N && A[idx_l] * 2 > A[idx_r]) ++idx_r;
    ans += N - idx_r;
  }

  cout << ans << endl;
}