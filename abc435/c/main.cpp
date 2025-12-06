#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);
  vector<s64> dp(n);
  dp[0] = as[0] - 1;
  for (s64 i = 1; i < n; ++i) {
    dp[i] = max(dp[i - 1], i + as[i] - 1);
  }

  s64 i = 0;
  while (i < n) {
    const s64 nxt = dp[i];
    if (nxt <= i) break;
    i = nxt;
  }
  cout << (i < n ? i + 1 : n) << endl;
}