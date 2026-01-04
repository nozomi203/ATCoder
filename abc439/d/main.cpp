#include "util/common.h"

/*
jを固定して考える。

*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  s64 ans = 0;

  {
    map<s64, s64> m;
    for (s64 j = 0; j < n; ++j) {
      const s64 aj = as[j];
      ++m[aj];
      if (aj % 5) continue;
      const s64 ai = 7 * (aj / 5);
      const s64 ak = 3 * (aj / 5);
      const s64 ni = m[ai];
      const s64 nk = m[ak];
      ans += ni * nk;
    }
  }

  {
    map<s64, s64> m;
    for (s64 j = n - 1; j >= 0; --j) {
      const s64 aj = as[j];
      ++m[aj];
      if (aj % 5) continue;
      const s64 ai = 7 * (aj / 5);
      const s64 ak = 3 * (aj / 5);
      const s64 ni = m[ai];
      const s64 nk = m[ak];
      ans += ni * nk;
    }
  }

  cout << ans << endl;
}