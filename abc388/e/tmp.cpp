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
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (s64 i{0}, j{0}, d{0}; i < N; ++i) {
    while (j < N && A[i] * 2 > A[j]) ++j;

    d = std::max(d, j - i);

    if (i + max(d, i + 1) >= N) {
      cout << i << endl;
      return 0;
    }
  }
}
