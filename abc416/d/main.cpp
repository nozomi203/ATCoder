#include "util/common.h"

int main() {
  s64 t;
  cin >> t;
  for (size_t i = 0; i < t; ++i) {
    s64 n, m;
    cin >> n >> m;
    vector<size_t> as(n), bs(n);
    util::cin(as);
    util::cin(bs);
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    vector<s64> idxs(n, -1);
    s64 j = n - 1;
    for (s64 i = 0; i < n; ++i) {
      if (as[i] + bs[j] < m) continue;
      while (j - 1 >= 0 && as[i] + bs[j - 1] >= m) --j;
      idxs[i] = j;
    }

    vector<s64> cnts(n, 0);
    for (auto idx : idxs) {
      if (idx < 0) continue;
      ++cnts[idx];
    }

    s64 sum = 0;
    s64 rem = 0;
    for (s64 idx = n - 1; idx >= 0; --idx) {
      ++rem;
      sum += min(cnts[idx], rem);
      rem = max<s64>(0, rem - cnts[idx]);
    }

    s64 ans = 0;
    for (auto a : as) ans += a;
    for (auto b : bs) ans += b;
    ans -= sum * m;
    cout << ans << endl;
  }
}