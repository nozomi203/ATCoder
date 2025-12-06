#include <atcoder/math>
#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

/*
1122文字列の中央がiだった場合を全探索する
s[i]から左方向に延びる数字s[i]の長さの最大と、s[i+1]以降から右方向に延びる数字s[i]+1の長さの最大が分かればいい
*/

s64 ctoi(char c) { return c - '0'; }

int main() {
  string s;
  cin >> s;
  const s64 n = s.size();

  // cntls[i][j] = s[0...i]に存在するjの数
  vector<vector<s64>> cntls(n, vector<s64>(10));
  cntls[0][ctoi(s[0])] = 1;
  for (s64 i = 1; i < n; ++i) {
    for (s64 j = 0; j < 10; ++j) {
      cntls[i][j] = cntls[i - 1][j];
    }
    cntls[i][ctoi(s[i])]++;
  }
  // cntlrs[i][j] = s[i...n-1]までに存在するjの数
  vector<vector<s64>> cntrs(n, vector<s64>(10));
  cntrs[n - 1][ctoi(s[n - 1])] = 1;
  for (s64 i = n - 2; i >= 0; --i) {
    for (s64 j = 0; j < 10; ++j) {
      cntrs[i][j] = cntrs[i + 1][j];
    }
    cntrs[i][ctoi(s[i])]++;
  }

  vector<mint> facts(3000001);
  facts[0] = 1;
  for (s64 i = 1; i < 3000001; ++i) facts[i] = facts[i - 1] * i;

  mint ans = 0;
  for (s64 i = 0; i < n - 1; ++i) {
    const char cl = s[i];
    if (cl == '9') continue;
    const char cr = s[i] + 1;
    const s64 cntl = cntls[i][ctoi(cl)];
    const s64 cntr = cntrs[i + 1][ctoi(cr)];
    const s64 mincnt = min(cntl, cntr);
    if (mincnt == 0) continue;
    ans += facts[cntl + cntr - 1] / (facts[cntr - 1] * facts[cntl]);
  }

  cout << ans.val() << endl;
}