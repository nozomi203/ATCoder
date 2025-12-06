#include "util/common.h"

/*

S[3,6]を考える

登場回数に傾向が見られそう
要素数n=4に対して、
N[0] = 4
N[1] = 6
N[2] = 6
N[3] = 4

N[0]について
N[0] = n
N[1] = (n-1) * 2
N[2] = (n-2) * 3
N[3] = (n-3) * 4

求めたい答えをS(l,r)とすると

l<=i<=rを満たすiについて
i * (r - l + 1 - i + l) * (i - l + 1)を合計すればいい。

= (-i + r + 1) * (i - l + 1) * i
= -A[i]^3 + A[i]^2(l - 1 + r + 1) + (-lr - l + r + 1)A[i]

A[3]+A[4]+A[5]+A[6]+
A[3]+A[4]+A[5]+
A[3]+A[4]+
A[3]+
     A[4]+A[5]+A[6]+
     A[4]+A[5]+
     A[4]+
          A[5]+A[6]+
          A[5]+
               A[6]

*/

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n + 1);
  vector<pair<s64, s64>> lrs(q);
  util::cin(as.begin() + 1, as.end());
  util::cin(lrs);

  vector<s64> sumas(n + 1), sumais(n + 1), sumaiis(n + 1);
  for (s64 i = 1; i <= n; ++i) {
    sumas[i] = sumas[i - 1] + as[i];
    sumais[i] = sumais[i - 1] + as[i] * i;
    sumaiis[i] = sumaiis[i - 1] + as[i] * i * i;
  }

  for (auto [l, r] : lrs) {
    const s64 val = -(sumaiis[r] - sumaiis[l - 1]) +
                    (r + l) * (sumais[r] - sumais[l - 1]) +
                    (sumas[r] - sumas[l - 1]) * (-r * l + r - l + 1);
    cout << val << endl;
  }
}