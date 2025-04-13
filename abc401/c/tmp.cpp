#line 1 "main.cpp"
#include <atcoder/modint>

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 4 "main.cpp"

int main() {
  s64 n, k;
  cin >> n >> k;
  using mint = atcoder::static_modint<1000000000>;
  vector<mint> a(n + 1, 0);

  if (k > n) {
    cout << 1 << endl;
    return 0;
  }
  fill(a.begin(), a.begin() + k, 1);
  a[k] = k;
  for (s64 i{k + 1}; i <= n; ++i) {
    a[i] = 2 * a[i - 1] - a[i - k - 1];
  }
  cout << a[n].val() << endl;
}
