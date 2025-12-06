#include "util/common.h"

/*
f(A[i], A[j])に対し、A[j]の桁数をD[j]とすると
f(A[i], A[j]) = A[i] * (D[j] + 1) + A[j];

A[i] * 10^(D[j]) + A[j] = 0(mod M)

iが決まったらA[j]の候補も決まる
*/

int get_digit(s64 v) {
  s64 ret = 0;
  while (v) {
    ++ret;
    v /= 10;
  }
  return ret;
}

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);

  map<s64, map<s64, s64>> mm;
  for (s64 i = 0; i < n; ++i) mm[get_digit(as[i])][as[i] % m]++;

  vector<s64> pow10s(12);
  pow10s[0] = 1;
  for (s64 i = 1; i < 12; ++i) pow10s[i] = pow10s[i - 1] * 10;

  s64 ans = 0;
  for (s64 i = 0; i < n; ++i) {
    const s64 ai = as[i];
    for (const auto& [d, mp] : mm) {
      const s64 pow10 = pow10s[d];
      const s64 v = ((ai % m) * (pow10 % m)) % m;
      auto it = mp.find((m - v) % m);
      if (it != mp.end()) {
        ans += it->second;
      }
    }
  }
  cout << ans << endl;
}