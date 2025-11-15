#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

/*
nこの区別できる箱にkこの区別できない要素を入れる場合の数
=nCk = n!/(k!(n - k)!))
*/

int main() {
  s64 n, d;
  cin >> n >> d;
  vector<s64> as(n);
  util::cin(as);

  constexpr s64 amax = 1000001;
  vector<s64> sumcnts(amax);
  for (auto a : as) ++sumcnts[a];
  for (s64 i = 1; i < amax; ++i) sumcnts[i] += sumcnts[i - 1];

  vector<mint> facts(n + 1);
  facts[0] = 1;
  for (s64 i = 1; i <= n; ++i) facts[i] = facts[i - 1] * i;

  mint ans = 1;
  s64 cnt_total = 0;
  for (s64 i = 1; i < amax; ++i) {
    const s64 a = i - d - 1 >= 0 ? sumcnts[i] - sumcnts[i - d - 1] : sumcnts[i];
    const s64 b = sumcnts[i] - sumcnts[i - 1];
    const s64 c = a - b;
    ans *= facts[a];
    ans /= facts[b];
    ans /= facts[c];
  }

  cout << ans.val() << endl;
}