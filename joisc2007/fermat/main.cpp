#include <atcoder/convolution>
#include <atcoder/math>

#include "util/common.h"

/*
x^n + y^n = z^n

a+b=c

cnts[i] = x mod p == iとなるxの個数


*/

int main() {
  s64 p;
  cin >> p;
  s64 n;
  cin >> n;

  vector<long long> cnts(p);
  for (u64 i = 0; i < p; ++i) cnts[atcoder::pow_mod(i, n, p)]++;
  const auto conv = atcoder::convolution_ll(cnts, cnts);

  s64 ans = 0;
  for (s64 z = 0; z < p; ++z) {
    ans += cnts[z] * conv[z];
    if (z + p < 2 * p - 1) {
      ans += cnts[z] * conv[z + p];
    }
  }
  cout << ans << endl;
}