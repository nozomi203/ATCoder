#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

s64 powi(s64 n, s64 i) {
  if (i == 0) return 1;
  return n * pow(n, i - 1);
}

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> c(n);
  for (s64 i{0}; i < n; ++i) cin >> c[i];
  vector<vector<s64>> animals(n);
  for (s64 i{0}; i < m; ++i) {
    s64 k;
    cin >> k;
    for (s64 j{0}; j < k; ++j) {
      s64 a;
      cin >> a;
      animals[a - 1].push_back(i);
    }
  }

  s64 ans{numeric_limits<s64>::max()};
  const s64 tm = powi(3, n);
  for (s64 t{0}; t < tm; ++t) {
    vector<s64> watch(m);
    s64 cost{0};
    s64 tmp{t};
    for (s64 i{0}; i < n; ++i) {
      const s64 cnt{tmp % 3};
      tmp = (tmp - cnt) / 3;
      for (auto a : animals[i]) {
        watch[a] += cnt;
      }
      cost += c[i] * cnt;
    }
    s64 min_w{numeric_limits<s64>::max()};
    for (auto w : watch) {
      min_w = min(min_w, w);
    }
    if (min_w < 2) continue;
    ans = min(ans, cost);
  }

  cout << ans << endl;
}