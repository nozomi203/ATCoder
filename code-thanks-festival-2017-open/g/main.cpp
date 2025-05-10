#include "util/bit.h"
#include "util/common.h"
int main() {
  u64 n, m;
  cin >> n >> m;
  vector<vector<s64>> g(n);
  for (u64 i{0}; i < m; ++i) {
    u64 a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  const u64 n1{n / 2}, n2{n - n / 2};

  vector<bool> ok1(1 << n1, true);
  for (u64 i{0}; i < n1; ++i) {
    for (u64 j : g[i]) {
      if (j >= n1) continue;
      ok1[(1 << i) | (1 << j)] = false;
    }
  }
  for (u64 b{0}; b < (1 << n1); ++b) {
    if (ok1[b]) continue;
    for (u64 i{0}; i < n1; ++i) {
      ok1[b | (1 << i)] = false;
    }
  }

  vector<u64> c(1 << n1);
  for (u64 i{0}; i < n1; ++i) {
    for (u64 j : g[i]) {
      if (j < n1) continue;
      c[(1 << i)] |= (1 << (j - n1));
    }
  }
  for (u64 b{0}; b < (1 << n1); ++b) {
    for (u64 i{0}; i < n1; ++i) {
      c[b | (1 << i)] |= c[b];
    }
  }

  vector<bool> ok2(1 << n2, true);
  for (u64 i{0}; i < n2; ++i) {
    for (u64 j : g[n1 + i]) {
      if (j < n1) continue;
      ok2[(1 << i) | (1 << (j - n1))] = false;
    }
  }
  for (u64 b{0}; b < (1 << n2); ++b) {
    if (ok2[b]) continue;
    for (u64 i{0}; i < n2; ++i) {
      ok2[b | (1 << i)] = false;
    }
  }
  vector<s64> ms(1 << n2);
  for (u64 b{0}; b < (1 << n2); ++b) ms[b] = ok2[b] ? util::bit_count(b) : 0;
  for (u64 b{0}; b < (1 << n2); ++b) {
    for (u64 i{0}; i < n2; ++i) {
      ms[b | (1 << i)] = max(ms[b | (1 << i)], ms[b]);
    }
  }

  u64 ans{0};
  for (u64 b{0}; b < (1 << n1); ++b) {
    if (!ok1[b]) continue;
    ans = max(ans, util::bit_count(b) + (ms[((1 << n2) - 1) & ~c[b]]));
  }
  cout << ans << endl;
}