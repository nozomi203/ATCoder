#include <atcoder/lazysegtree>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  vector<s64> last_idxs(1000000, 0);
  last_idxs[a[0]] = 0;

  map<s64, s64> cnt;
  for (s64 i{1}; i < n; ++i) cnt[a[i]]++;

  s64 ans{0};

  constexpr auto e = []() { return 0; };
  constexpr auto op = [](s64 l, s64 r) { return max(l, r); };
  constexpr auto mapping = [](s64 f, s64 s) { return s + f; };
  constexpr auto composition = [](s64 f0, s64 f1) { return f0 + f1; };
  constexpr auto id = []() { return 0; };
  atcoder::lazy_segtree<s64, op, e, s64, mapping, composition, id> lst(n);
  lst.apply(0, n, 1);
  for (s64 i{1}; i < n - 1; ++i) {
    const auto val = a[i];

    cnt[val]--;
    if (!cnt[val]) cnt.erase(val);

    const auto last_idx = last_idxs[val];
    lst.apply(last_idx, i, 1);
    last_idxs[val] = i;

    ans = max<s64>(ans, lst.prod(0, i) + cnt.size());
  }

  cout << ans << endl;
}