#include <bits/stdc++.h>

#include <atcoder/modint>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  using mint = atcoder::modint1000000007;
  s64 w, h;
  cin >> w >> h;
  mint a(1), b(1), c(1);
  for (s64 i{2}; i <= w + h - 2; ++i) a *= i;
  for (s64 i{2}; i <= w - 1; ++i) b *= i;
  for (s64 i{2}; i <= h - 1; ++i) c *= i;

  cout << (a / (b * c)).val() << endl;
}