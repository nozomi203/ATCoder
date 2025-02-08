#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, M;
  cin >> N >> M;
  set<s64> s;
  for (s64 i = 0; i < M; ++i) {
    s64 A;
    cin >> A;
    s.emplace(A);
  }
  cout << N - s.size() << endl;
  s64 cnt{0};
  for (s64 i = 1; i <= N; ++i) {
    if (s.contains(i)) continue;
    cout << i;
    cnt++;
    if (cnt < N - s.size()) {
      cout << " ";
    }
  }
  cout << endl;
}
