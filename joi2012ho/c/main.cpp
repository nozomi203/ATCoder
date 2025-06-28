#include "util/common.h"

/*

*/

int main() {
  size_t n, t, s;
  cin >> n >> t >> s;
  vector<pair<size_t, size_t>> abs(n + 1);
  util::cin(abs.begin() + 1, abs.end());

  /*
  dp[i][j] = 夜店iまでの中で時刻jまで遊んだ時の楽しさの最大値
  */
  vector<vector<size_t>> dp(n + 1, vector<size_t>(t + 1));
  for (size_t i = 1; i <= n; ++i) {
    for (size_t j = 1; j <= t; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= abs[i].second && (j <= s || s <= j - abs[i].second)) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - abs[i].second] + abs[i].first);
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}