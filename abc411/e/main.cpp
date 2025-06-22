#include <atcoder/modint>

#include "util/common.h"

using mint = atcoder::modint998244353;

/*
最大値がxになる場合の数＝x以下の数のみ出る場合の数　-
x-1未満が最大になる場合の数
最小の数をxminとしたとき、xminが最大となる場合の数は、xminのみ出る場合の数
 */

int main() {
  size_t n;
  cin >> n;
  using array = array<size_t, 6>;
  vector<array> ass(n);
  for (auto& as : ass) {
    for (auto& a : as) cin >> a;
  }
  map<size_t, map<size_t, size_t>> mm;
  for (size_t i = 0; i < n; ++i) {
    const auto& as = ass[i];
    map<size_t, size_t> tmp;
    for (auto a : as) {
      tmp[a]++;
    }
    for (auto [k, v] : tmp) mm[k][i] = v;
  }

  mint ans = 0;
  mint sum = 0;
  mint mul = 1;
  size_t zerocnt{n};
  vector<mint> muls(n, 0);
  for (const auto& [v, m] : mm) {
    for (auto [idx, cnt] : m) {
      if (muls[idx] == 0) {
        muls[idx] = cnt;
        mul *= cnt;
        --zerocnt;
      } else {
        mul /= muls[idx];
        muls[idx] += cnt;
        mul *= muls[idx];
      }
    }
    if (zerocnt == 0) {
      ans += v * (mul - sum);
      sum += (mul - sum);
    }
  }

  for (size_t i{0}; i < n; ++i) ans /= 6;
  cout << ans.val() << endl;
}