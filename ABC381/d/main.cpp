#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i{0}; i < N; ++i) cin >> A[i];

  s64 ans{0};
  for (s64 offset{0}; offset <= 1; ++offset) {
    s64 idx_r{};
    set<s64> s;
    for (s64 idx_l{offset}; idx_l < N; idx_l += 2) {
      idx_r = max(idx_r, idx_l);
      while (idx_r < N - 1 && A[idx_r] == A[idx_r + 1] &&
             s.count(A[idx_r]) == 0) {
        s.emplace(A[idx_r]);
        idx_r += 2;
      }

      const auto len = idx_r - idx_l;
      if (len) {
        ans = max(ans, idx_r - idx_l);
        s.erase(A[idx_l]);
      }
    }
  }

  cout << ans << endl;
}