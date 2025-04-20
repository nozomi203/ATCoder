#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  string s;
  cin >> s;
  for (char c : s) {
    if (isupper(c)) {
      cout << c;
    }
  }
  cout << endl;
}