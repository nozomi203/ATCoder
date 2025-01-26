#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];

  const auto check = [](const auto& A) {
    const s64 div = gcd(A[0], A[1]);
    const s64 l = A[0] / div;
    const s64 r = A[1] / div;
    for (s64 i = 1; i < A.size() - 1; ++i) {
      const s64 i_div = gcd(A[i], A[i + 1]);
      if (l != A[i] / i_div || r != A[i + 1] / i_div) return false;
    }
    return true;
  };
  cout << (check(A) ? "Yes" : "No") << endl;
}