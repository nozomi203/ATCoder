#include "util/common.h"

/*
dp[i] = i文字目を末尾とする文字列で、条件を満たすものの総数
dp[i] = sum(dp[i-1])
*/

constexpr size_t mod = 10000000;

size_t toidx(char c) { return c - 'A'; }

int main() {
  size_t l;
  cin >> l;
  string s;
  cin >> s;
  size_t m;
  cin >> m;
  vector<pair<char, char>> abs(m);
  util::cin(abs);

  vector<vector<bool>> map(26, vector<bool>(26, true));
  for (auto [a, b] : abs) {
    map[toidx(a)][toidx(b)] = false;
  }

  vector<size_t> prevs(l + 1, 0);
  {
    vector<size_t> prevs_tmp(26, 0);
    for (size_t i = 1; i <= l; ++i) {
      prevs[i] = prevs_tmp[toidx(s[i - 1])];
      prevs_tmp[toidx(s[i - 1])] = i;
    }
  }

  vector<u32> dp(l + 1);
  dp[0] = 1;
  for (size_t i = 1; i <= l; ++i) {
    for (size_t j = prevs[i]; j < i; ++j) {
      if (j == 0) {
        dp[i] += 1;
      } else {
        if (!map[toidx(s[j - 1])][toidx(s[i - 1])]) continue;
        dp[i] += dp[j];
        dp[i] %= mod;
      }
    }
  }
  u32 ans = 0;
  for (size_t i = 1; i <= l; ++i) {
    ans += dp[i];
    ans %= mod;
  }
  cout << ans << endl;
}