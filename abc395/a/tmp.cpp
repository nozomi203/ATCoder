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
  s64 A{0};
  for (s64 i = 0; i < N; ++i) {
    s64 tmp;
    cin >> tmp;
    if (tmp <= A) {
      cout << "No" << endl;
      return 0;
    }
    A = tmp;
  }
  cout << "Yes" << endl;
}
