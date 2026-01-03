#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n);
  util::cin(as);
  vector<pair<s64, s64>> tbs(q);
  util::cin(tbs);

  // dp1[i][j] =
  // i番目の人がバケツを持った状態で2^j回の操作を行った直後にバケツを持っている人
  vector<vector<s64>> dp1(n + 1, vector<s64>(31));
  for (s64 i = 1; i <= n; ++i) {
    dp1[i][0] = as[i - 1];
  }
  for (s64 j = 1; j <= 30; ++j) {
    for (s64 i = 1; i <= n; ++i) {
      dp1[i][j] = dp1[dp1[i][j - 1]][j - 1];
    }
  }

  // dp2[i][j] =
  // i番目の人がバケツを持った状態で2^j回の操作を行った直後に注がれている水の量
  vector<vector<s64>> dp2(n + 1, vector<s64>(31));
  for (s64 i = 1; i <= n; ++i) {
    dp2[i][0] = i;
  }
  for (s64 j = 1; j <= 30; ++j) {
    for (s64 i = 1; i <= n; ++i) {
      dp2[i][j] = dp2[i][j - 1] + dp2[dp1[i][j - 1]][j - 1];
    }
  }

  for (auto [t, b] : tbs) {
    u32 pow = 31;
    s64 i = b;
    s64 sum = 0;
    while (true) {
      const u32 num = 1 << (--pow);
      if (t >= num) {
        t -= num;
        sum += dp2[i][pow];
        i = dp1[i][pow];
      }
      if (pow == 0) break;
    }

    cout << sum << endl;
  }
}