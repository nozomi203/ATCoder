#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, R;
  cin >> N >> R;
  for (s64 n = 0; n < N; ++n) {
    s64 D, A;
    cin >> D >> A;
    const s64 minRate = D == 1 ? 1600 : 1200;
    const s64 maxRate = D == 1 ? 2799 : 2399;
    if (minRate <= R && R <= maxRate) {
      R += A;
    }
  }
  cout << R << endl;
}
