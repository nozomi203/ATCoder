#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  s64 ans{0};
  for (s64 i{0}; i < n; ++i)
    if (s[i] != t[i]) ++ans;
  cout << ans << endl;
}