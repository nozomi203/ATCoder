#include <atcoder/math>
#include <atcoder/modint>

#include "util/common.h"
#include "util/math.h"

int main() {
  using mint = atcoder::modint998244353;
  s64 n, k;
  cin >> n >> k;
  vector<mint> s(n + 1);
  for (s64 i{1}; i <= n; ++i) {
    s64 a;
    cin >> a;
    s[i] = s[i - 1] + a;
  }

  mint ans = 0;
  for (s64 i{0}; i <= k; ++i) {
    const s64 coef = util::fact(k) / (util::fact(i) * util::fact(k - i));
    mint ss = 0;
    for (s64 r{0}; r <= n; ++r) {
      ans += s[r].pow(i) * ss * coef;
      ss += (-s[r]).pow(k - i);
    }
  }

  cout << ans.val() << endl;
}