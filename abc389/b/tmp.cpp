#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 X;
  cin >> X;
  s64 fact{1};
  s64 n{1};
  while (fact != X) {
    ++n;
    fact *= n;
  }
  cout << n << endl;
}
