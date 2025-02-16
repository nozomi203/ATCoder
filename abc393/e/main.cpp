#include "util/common.h"

int main() {
  s64 N, K;
  cin >> N >> K;
  vector<s64> A(N);
  s64 a_max{0};
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
    a_max = max(a_max, A[i]);
  }

  vector<s64> cnt_n(a_max + 1);
  for (s64 i = 0; i < N; ++i) {
    ++cnt_n[A[i]];
  }
  vector<s64> cnt_nx(a_max + 1);
  for (s64 i = 1; i <= a_max; ++i) {
    for (s64 j = i; j <= a_max; j += i) {
      cnt_nx[i] += cnt_n[j];
    }
  }
  vector<s64> ans(a_max + 1);
  for (s64 i = 1; i <= a_max; ++i) {
    if (cnt_nx[i] < K) continue;
    for (s64 j = i; j <= a_max; j += i) {
      ans[j] = max(ans[j], i);
    }
  }
  for (auto a : A) {
    cout << ans[a] << endl;
  }
}