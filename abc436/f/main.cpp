#include <atcoder/fenwicktree>

#include "util/common.h"

/*
星iを含む集合Sで、iがその中で最も暗いような組み合わせの数N(i)
Sに含まれるのは明るさがi番目以内の星。
iより左にある、iより明るい星の数をNL(i),
iより右にある、iより明るい星の数をNR(i)とすると、
N(i) = (NL(i) + 1) * (NR(i) +1)
すべてのiに対するN(i)の総和が答え
*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> bs(n);
  util::cin(bs);

  vector<s64> nls(n), nrs(n);
  atcoder::fenwick_tree<s64> ftl(n + 1), ftr(n + 1);
  for (s64 i = 0; i < n; ++i) {
    const s64 b = bs[i];
    nls[i] = ftl.sum(0, b);
    ftl.add(b, 1);
  }
  for (s64 i = n - 1; i >= 0; --i) {
    const s64 b = bs[i];
    nrs[i] = ftr.sum(0, b);
    ftr.add(b, 1);
  }

  s64 ans = 0;
  for (s64 i = 0; i < n; ++i) {
    ans += (nls[i] + 1) * (nrs[i] + 1);
  }
  cout << ans << endl;
}