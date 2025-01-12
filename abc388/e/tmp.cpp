#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  vector<bool> used(N, false);
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
  }

  s64 ans{0};
  s64 idx_r{1};
  for (s64 idx_l = 0; idx_l < N - 1; ++idx_l) {
    if (used[idx_l]) continue;
    if (idx_l == idx_r) ++idx_r;
    while (idx_r < N && (A[idx_l] * 2 > A[idx_r] || used[idx_r])) ++idx_r;
    if (idx_r == N) break;

    ++ans;
    used[idx_r] = true;
  }

  cout << ans << endl;
}
