#include "util/common.h"

u64 find_max(const vector<u64>& a, u64 idx, u64 k, u64 val) {
  if (k == 0) return val;
  if (idx == a.size()) return 0;

  return max(find_max(a, idx + 1, k - 1, val ^ a[idx]),
             find_max(a, idx + 1, k, val));
}

int main() {
  u64 N, K;
  cin >> N >> K;
  vector<u64> A(N);
  for (u64 i = 0; i < N; ++i) cin >> A[i];

  const auto get_ans = [&]() {
    if (K < N - K) {
      return find_max(A, 0, K, 0);
    } else {
      u64 xor_all{0};
      for (auto a : A) xor_all ^= a;
      return find_max(A, 0, N - K, xor_all);
    }
  };

  cout << get_ans() << endl;
}