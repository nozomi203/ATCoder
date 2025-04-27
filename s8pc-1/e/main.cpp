#include <bits/stdc++.h>

#include <atcoder/fenwicktree>
#include <atcoder/math>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n, q;
  cin >> n >> q;
  constexpr s64 m = 1000000007;
  vector<s64> a(n + 1);
  for (s64 i{1}; i <= n; ++i) cin >> a[i];
  vector<s64> c(q + 2, 1);
  for (s64 i{1}; i <= q; ++i) cin >> c[i];
  atcoder::fenwick_tree<s64> ft(n + 1);
  for (s64 i{2}; i <= n; ++i) ft.add(i, atcoder::pow_mod(a[i - 1], a[i], m));

  s64 ans{0};
  for (s64 i{0}; i <= q; ++i) {
    auto f{c[i]}, t{c[i + 1]};
    if (f < t) {
      ans += ft.sum(f + 1, t + 1);
    } else {
      ans += ft.sum(t + 1, f + 1);
    }
    ans = ans % m;
  }
  cout << ans << endl;
}