#include "util/common.h"

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