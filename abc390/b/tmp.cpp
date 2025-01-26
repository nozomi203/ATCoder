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
