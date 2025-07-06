#include "util/common.h"

/*
文字列の先頭をiとしたときの操作3の回数の最小値を列挙する
iからJ,O,Iをそれぞれ位置の近い順にKこずつ選択したときが最大
*/

s64 toidx(char c) {
  switch (c) {
    case 'J':
      return 0;
    case 'O':
      return 1;
    case 'I':
      return 2;
    default:
      return -1;
  }
}

int main() {
  s64 n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  array<vector<s64>, 3> cntss;
  cntss.fill(vector<s64>(s.size() + 1));
  for (s64 i = 1; i <= n; ++i) {
    cntss[0][i] += cntss[0][i - 1];
    cntss[1][i] += cntss[1][i - 1];
    cntss[2][i] += cntss[2][i - 1];
    cntss[toidx(s[i - 1])][i]++;
  }

  constexpr auto inf = numeric_limits<s64>::max();
  s64 ans = inf;
  for (s64 i = 1; i <= n; ++i) {
    const auto itj =
        lower_bound(cntss[0].begin(), cntss[0].end(), cntss[0][i - 1] + k);
    if (itj == cntss[0].end()) continue;
    const auto idxj = distance(cntss[0].begin(), itj);

    auto ito =
        lower_bound(cntss[1].begin(), cntss[1].end(), cntss[1][idxj] + k);
    if (ito == cntss[1].end()) continue;
    const auto idxo = distance(cntss[1].begin(), ito);

    auto iti =
        lower_bound(cntss[2].begin(), cntss[2].end(), cntss[2][idxo] + k);
    if (iti == cntss[2].end()) continue;
    const auto idxi = distance(cntss[2].begin(), iti);

    s64 cnt = 0;
    cnt += idxj - i + 1 - k;
    cnt += idxo - idxj - k;
    cnt += idxi - idxo - k;
    ans = min(ans, cnt);
  }
  cout << (ans == inf ? -1 : ans) << endl;
}