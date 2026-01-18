#include <atcoder/modint>

#include "util/common.h"
/*
len[i] =
数列Aの部分列のうち、先頭i個までの要素のみを含むもので、隣接した要素を含まないようなものの数
len[0] = 1
len[1] = 2
先頭i個までの要素を含む部分列は、A[i]を含むかどうかで場合分けできる。
(1)A[i]を含む場合
A[i]を含む場合、制約よりA[i-1]を含むことはできない。
このような部分列は、先頭i-2個までの要素のみを含む部分列の末尾にA[i]を足すことで作成できる。
その数はlen[i-2]
(2)A[i]を含まない場合
A[i]を含まないとき、先頭i-1個までの要素のみを含む部分列の集合がそのまま一致する。
その数はlen[i-1]
よって
len[i] = len[i-1] + len[i-2]
len[30] = 10^6程度なので、半分全列挙する。
隣り合う要素を含まない数列を効率的に全列挙したい
*/
// int fib(int n) {
//   if (n == 0) return 1;
//   if (n == 1) return 2;
//   return fib(n - 1) + fib(n - 2);
// }
using mint = atcoder::modint;

int main() {
  u64 n;
  s64 m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);
  const u64 nr = n / 2;
  const u64 nl = n - n / 2;
  mint::set_mod(m);
  vector<vector<mint>> dp(n);
  for (u64 i = 0; i < nl; ++i) {
    dp[i].push_back(as[i]);
    for (u64 j = 0; j + 1 < i; ++j) {
      for (mint v : dp[j]) dp[i].push_back(v + as[i]);
    }
  }
  for (u64 i = n - 1ULL; i >= nl; --i) {
    dp[i].push_back(as[i]);
    for (u64 j = i + 2; j < n; ++j) {
      for (mint v : dp[j]) dp[i].push_back(v + as[i]);
    }
    if (i == 0) break;
  }

  unordered_map<u64, u64> mll, mlr, mrl, mrr;
  for (u64 i = 0; i < nl - 1; ++i) {
    for (mint v : dp[i]) ++mll[v.val()];
  }
  for (mint v : dp[nl - 1]) ++mlr[v.val()];
  for (mint v : dp[nl]) ++mrl[v.val()];
  for (u64 i = nl + 1; i < n; ++i) {
    for (mint v : dp[i]) ++mrr[v.val()];
  }

  u64 ans = 1;  // ()
  ans += mll[0];
  ans += mlr[0];
  ans += mrl[0];
  ans += mrr[0];
  for (auto [v, cnt] : mll) {
    const u64 rem = (m - v) % m;
    if (auto it = mrl.find(rem); it != mrl.end()) ans += cnt * it->second;
    if (auto it = mrr.find(rem); it != mrr.end()) ans += cnt * it->second;
  }
  for (auto [v, cnt] : mlr) {
    const u64 rem = (m - v) % m;
    if (auto it = mrr.find(rem); it != mrr.end()) ans += cnt * it->second;
  }
  cout << ans << endl;
}