#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string s, t;
  cin >> s >> t;
  const auto get = [&]() -> size_t {
    for (size_t i{0}; i < max(s.size(), t.size()); ++i) {
      if (i >= s.size() || i >= t.size()) return i + 1;
      if (s[i] != t[i]) return i + 1;
    }
    return 0;
  };

  cout << get() << endl;
}
