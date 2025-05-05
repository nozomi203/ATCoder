#include <atcoder/modint>

#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<s64> cnts(n);
  s64 cnt0{3};

  using mint = atcoder::modint1000000007;
  mint ans = 1;
  for (s64 i{0}; i < n; ++i) {
    if (a[i] == 0) {
      ans *= cnt0;
      --cnt0;
      ++cnts[0];
    } else {
      ans *= cnts[a[i] - 1];
      --cnts[a[i] - 1];
      ++cnts[a[i]];
    }
  }

  cout << ans.val() << endl;
}