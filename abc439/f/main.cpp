#include <atcoder/fenwicktree>
#include <atcoder/modint>

#include "util/common.h"
using mint = atcoder::modint998244353;

/*
Pの部分列P[l,r]に対し、P[l+1]およびP[r-1]を固定する。
P[l+1]より左にある要素のうち、P[l+1]より小さいものの数をx
P[r-1]より右にある要素のうち、P[r-1]より小さいものの数をyとする。
このとき、P[l]の選び方はx通り,P[r]の選び方はy通りある。
また、P[l+2] ~ P[r-2]は選んでも選ばなくてもよいので、その選び方は2^(r - l -
1)通りある。 したがって、この時の条件を満たす部分列の数はx * y * 2^(r - l -
1)通り。 lを固定したとき、xは確定する。 この時条件を満たす部分列の数はx * sum(y
* 2^(r-l-1))
rは[l,n-1]の範囲で選択可能なので、この範囲のy*2^(r-l-1)の値の総和をとればよい。
*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> ps(n);
  util::cin(ps);

  vector<s64> numminls(n), numminrs(n);
  {
    atcoder::fenwick_tree<s64> ft(300001);
    for (s64 i = 0; i < n; ++i) {
      numminls[i] = ft.sum(0, ps[i]);
      ft.add(ps[i], 1);
    }
  }
  {
    atcoder::fenwick_tree<s64> ft(300001);
    for (s64 i = n - 1; i >= 0; --i) {
      numminrs[i] = ft.sum(0, ps[i]);
      ft.add(ps[i], 1);
    }
  }

  vector<mint> sums(n);
  {
    sums[0] = numminrs[0];
    mint pow2 = 1;
    for (s64 i = 1; i < n; ++i) {
      pow2 *= 2;
      sums[i] = numminrs[i] * pow2 + sums[i - 1];
    }
  }

  mint ans = 0;
  mint pow2 = 2;
  for (s64 i = 1; i < n - 1; ++i) {
    pow2 *= 2;
    mint add = numminls[i] * (sums[n - 1] - sums[i]) / pow2;
    ans += add;
    mint add2 = numminls[i] * numminrs[i];
    ans += add2;
  }
  cout << ans.val() << endl;
}