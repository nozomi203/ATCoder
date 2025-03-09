#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
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
  vector<s64> A(N), B(N - 1);
  for (s64 i{0}; i < N; ++i) cin >> A[i];
  for (s64 i{0}; i < N - 1; ++i) cin >> B[i];
  sort(A.begin(), A.end(), greater());
  sort(B.begin(), B.end(), greater());

  const auto get = [&]() -> s64 {
    optional<s64> bsize;
    auto ita = A.begin();
    auto itb = B.begin();
    while (itb != B.end()) {
      if (*ita <= *itb) {
        ++ita;
        ++itb;
      } else {
        if (bsize) return -1;
        bsize = *ita;
        ++ita;
      }
    }
    if (!bsize) bsize = *ita;
    return bsize.value();
  };

  cout << get() << endl;
}
