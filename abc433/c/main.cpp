#include "util/common.h"

int main() {
  string s;
  cin >> s;
  s64 n = s.size();

  // lenls[i] = s[k...i]がすべて同じ文字となる最長の長さ
  // lenrs[i] = s[i...k]がすべて同じ文字となる最長の長さ
  vector<s64> lenls(n), lenrs(n);

  lenls[0] = 1;
  for (s64 i = 1; i < n; ++i) {
    lenls[i] = s[i] == s[i - 1] ? lenls[i - 1] + 1 : 1;
  }
  lenrs[n - 1] = 1;
  for (s64 i = n - 2; i >= 0; --i) {
    lenrs[i] = s[i] == s[i + 1] ? lenrs[i + 1] + 1 : 1;
  }

  s64 ans = 0;
  for (s64 i = 0; i < n - 1; ++i) {
    s64 lenl = lenls[i];
    s64 lenr = lenrs[i + 1];
    if (s[i] == s[i + 1]) continue;
    if (s[i] + 1 != s[i + 1]) continue;
    s64 len = min(lenl, lenr);
    ans += len;
  }
  cout << ans << endl;
}