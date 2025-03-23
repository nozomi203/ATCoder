#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  cin >> n;
  map<s64, vector<s64>> m;
  for (s64 i{1}; i <= n; ++i) {
    s64 a;
    cin >> a;
    m[a].push_back(i);
  }

  for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
    if (rit->second.size() == 1) {
      cout << rit->second.front() << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
