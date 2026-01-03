#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  s64 nummin = numeric_limits<s64>::max();
  for (s64 i = 0; i <= n - m; ++i) {
    s64 num = 0;
    for (s64 j = 0; j < m; ++j) {
      s64 dst = s[j + i] - '0';
      s64 src = t[j] - '0';

      if (src <= dst) {
        num += (dst - src);
      } else {
        num += (10 - src) + dst;
      }
    }
    nummin = min(nummin, num);
  }
  cout << nummin << endl;
}