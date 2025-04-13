#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  for (s64 i{0}; i < n; ++i) {
    if (s[i] == 'o') {
      --k;
      if (i - 1 >= 0 && s[i - 1] == '?') s[i - 1] = '.';
      if (i + 1 < n && s[i + 1] == '?') s[i + 1] = '.';
    }
  }

  s64 capa_o{0};
  vector<pair<s64, s64>> pbe;
  {
    s64 i{0};
    while (i < n) {
      while (i < n && s[i] != '?') {
        ++i;
      }
      s64 j{i};
      while (j < n && s[j] == '?') {
        ++j;
      }
      if (j > i) {
        capa_o += ((j - i) + 1) / 2;
        pbe.push_back(make_pair(i, j));
      }
      i = j;
    }
  }
  if (capa_o == k) {
    for (auto [b, e] : pbe) {
      if ((e - b) % 2) {
        for (s64 i{0}; i < e - b; ++i) {
          s[b + i] = (i % 2) ? '.' : 'o';
        }
      }
    }
  } else if (k == 0) {
    for (auto [b, e] : pbe) {
      for (s64 i{0}; i < e - b; ++i) s[b + i] = '.';
    }
  }
  cout << s << endl;
}
