#line 1 "main.cpp"
#include <atcoder/math>
#include <atcoder/modint>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\math.h"
#include <concepts>
#line 4 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\math.h"

namespace util {
template <std::integral Int>
Int powi(Int value, uint64_t pow) {
  if (pow == 0) return 1;
  return value * powi(value, pow - 1);
}

uint64_t fact(uint64_t val) {
  if (val == 0) return 1;
  return val * fact(val - 1);
}
}  // namespace util
#line 6 "main.cpp"

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
