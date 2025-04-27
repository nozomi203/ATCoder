#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  string t, u;
  cin >> t >> u;
  const auto get = [&]() -> bool {
    for (s64 i{0}; i <= t.size() - u.size(); ++i) {
      bool b{true};
      for (s64 j{0}; j < u.size(); ++j) {
        if (t[j + i] != '?' && t[j + i] != u[j]) {
          b = false;
          break;
        }
      }
      if (b) {
        return true;
      }
    }
    return false;
  };
  cout << (get() ? "Yes" : "No") << endl;
}