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
  vector<s64> P(N + 1), Q(N + 1), R(N + 1);
  for (s64 i = 1; i <= N; ++i) cin >> P[i];
  for (s64 i = 1; i <= N; ++i) {
    cin >> Q[i];
    R[Q[i]] = i;
  }
  for (s64 i = 1; i <= N; ++i) {
    cout << Q[P[R[i]]];
    if (i < N) cout << " ";
  }
  cout << endl;
}
