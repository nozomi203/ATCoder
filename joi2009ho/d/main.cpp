#include "util/common.h"

/*
dp[i][j] = 太郎君が交差点(i,j)をn-1回目までのさんぽで訪れる回数
dp[0][0] = n-1
(i-1,j)の初期値が0
奇数回のとき(i,j)を訪れる
(i-1,j)の初期値が1
偶数回のとき(i,j)を訪れる
dp[i][j] +=
*/

int main() {
  s64 h, w, n;
  cin >> h >> w >> n;
  vector<vector<s64>> as(h, vector<s64>(w));
  util::cin(as);

  vector<vector<s64>> dp(h, vector<s64>(w));
  dp[0][0] = n - 1;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (i > 0) {
        if (as[i - 1][j] == 0) {
          dp[i][j] += (dp[i - 1][j] + 1) / 2;
        } else {
          dp[i][j] += dp[i - 1][j] / 2;
        }
      }
      if (j > 0) {
        if (as[i][j - 1] == 0) {
          dp[i][j] += dp[i][j - 1] / 2;
        } else {
          dp[i][j] += (dp[i][j - 1] + 1) / 2;
        }
      }
    }
  }
  s64 i = 0, j = 0;
  while (i < h && j < w) {
    const s64 a = (as[i][j] + dp[i][j]) % 2;
    if (a == 0) {
      ++i;
    } else {
      ++j;
    }
  }

  cout << i + 1 << " " << j + 1 << endl;
}