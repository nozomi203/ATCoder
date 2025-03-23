#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  float x;
  cin >> x;
  cout << (x >= 38.0f ? 1 : (x >= 37.5f ? 2 : 3)) << endl;
}
