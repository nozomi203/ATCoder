#include "util/common.h"

int main() {
  s64 N, X;
  cin >> N >> X;
  struct food {
    s64 v;
    s64 a;
    s64 c;
  };
  vector<food> foods(N + 1);
  for (s64 i{1}; i <= N; ++i) cin >> foods[i].v >> foods[i].a >> foods[i].c;

  vector<vector<vector<s64>>> dp(
      4, vector<vector<s64>>(N + 1, vector<s64>(X + 1)));
  for (s64 i{1}; i <= 3; ++i) {
    for (s64 j{1}; j <= N; ++j) {
      for (s64 k{1}; k <= X; ++k) {
        if (foods[j].v != i || k < foods[j].c) {
          dp[i][j][k] = dp[i][j - 1][k];
        } else {
          dp[i][j][k] = max<s64>(dp[i][j - 1][k],
                                 dp[i][j - 1][k - foods[j].c] + foods[j].a);
        }
      }
    }
  }
  vector<vector<s64>> dp2(4, vector<s64>(X + 1));
  for (s64 i{1}; i <= 3; ++i) {
    s64 a_max{0};
    for (s64 k{1}; k <= X; ++k) {
      a_max = max(a_max, dp[i][N][k]);
      dp2[i][k] = a_max;
    }
  }

  vector<s64> c(4), a(4);
  while (c[1] + c[2] + c[3] < X) {
    if (a[1] <= a[2] && a[1] <= a[3]) {
      ++c[1];
      a[1] = dp2[1][c[1]];
    } else if (a[2] <= a[1] && a[2] <= a[3]) {
      ++c[2];
      a[2] = dp2[2][c[2]];
    } else {
      ++c[3];
      a[3] = dp2[3][c[3]];
    }
  }
  cout << min({a[1], a[2], a[3]}) << endl;
}