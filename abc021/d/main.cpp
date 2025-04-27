#include <bits/stdc++.h>

#include <atcoder/math>
#include <atcoder/modint>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, k;
  cin >> n >> k;
  using mint = atcoder::modint1000000007;
  mint a{1}, b{1}, c{1}, ans{0}, mul{1};
  for (s64 i{2}; i <= n; ++i) a *= i;
  for (s64 i{2}; i <= n - k; ++i) b *= i;
  for (s64 i{2}; i <= k; ++i) c *= i;
  mint v = a / (b * c);
  for (s64 i{k}; i >= 1; --i) {
    ans += v * mul;
    v *= i;
    v /= (n - i + 1);
    mul *= (i - 1);
    mul /= (k - i + 1);
  }

  cout << ans.val() << endl;
}