#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  string s;
  cin >> s;
  vector<bool> exists(26);
  for (char c : s) exists[c - 'a'] = true;
  for (s64 i{0}; i < 26; ++i) {
    if (!exists[i]) {
      cout << (char)(i + 'a') << endl;
      return 0;
    }
  }
}