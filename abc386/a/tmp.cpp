#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 A, B, C, D;
  cin >> A >> B >> C >> D;
  map<s64, s64> m;
  m[A]++;
  m[B]++;
  m[C]++;
  m[D]++;
  cout << (m.size() == 2 ? "Yes" : "No") << endl;
}
