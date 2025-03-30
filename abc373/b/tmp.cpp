#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string s;
  cin >> s;
  map<char, s64> m;
  for (s64 i{0}; i < 26; ++i) {
    m[s[i]] = i;
  }
  s64 dist{0};
  s64 l{m['A']};
  for (char c{'B'}; c <= 'Z'; ++c) {
    dist += abs(m[c] - l);
    l = m[c];
  }
  cout << dist << endl;
}
