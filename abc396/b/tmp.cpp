#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 q;
  cin >> q;
  stack<s64> s;
  for (s64 i{0}; i < q; ++i) {
    s64 query;
    cin >> query;

    if (query == 1) {
      s64 x;
      cin >> x;
      s.push(x);
    } else {
      if (s.empty()) {
        cout << 0 << endl;
      } else {
        cout << s.top() << endl;
        s.pop();
      }
    }
  }
}
