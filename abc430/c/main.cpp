#include "util/common.h"

int main() {
  s64 n, a, b;
  string s;
  util::cin(n, a, b, s);
  vector<s64> numas(n + 1), numbs(n + 1);
  for (s64 i = 0; i < n; ++i) {
    if (s[i] == 'a') ++numas[i + 1];
    if (s[i] == 'b') ++numbs[i + 1];
    numas[i + 1] += numas[i];
    numbs[i + 1] += numbs[i];
  }

  s64 ans = 0;
  s64 ia = 1;
  s64 ib = 1;
  for (s64 l = 1; l <= n; ++l) {
    // ia ... l以降のaの個数がa以上になる最初のインデクス
    // ib ... l以降のbの個数がb以上になる最初のインデクス
    while (ia <= n && numas[ia] - numas[l - 1] < a) ++ia;
    if (ia > n) break;
    while (ib <= n && numbs[ib] - numbs[l - 1] < b) ++ib;

    // ia以上ib未満のインデクスの数を加算
    if (ib > ia) ans += ib - ia;
  }

  cout << ans << endl;
}