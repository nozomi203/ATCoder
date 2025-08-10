#include "util/common.h"

/*
xを最大限大きくすればゲームには勝てる
ただし、b>=aiとなるフレーバーiが1つも存在しなければ必ず負ける
難易度bのゲームにかつxの最小値＝
 */

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n);
  util::cin(as);
  vector<s64> bs(q);
  util::cin(bs);

  sort(as.begin(), as.end());
  vector<s64> sumas(n);
  sumas[0] = as[0];
  for (s64 i = 1; i < n; ++i) sumas[i] += sumas[i - 1] + as[i];

  const auto get = [&](s64 b) -> s64 {
    auto it = lower_bound(as.begin(), as.end(), b);
    if (it == as.end()) return -1;
    size_t ans = 0;
    const size_t idx = distance(as.begin(), it);
    if (idx > 0) ans += sumas[idx - 1];
    ans += (b - 1) * (n - idx) + 1;
    return ans;
  };

  for (auto b : bs) {
    cout << get(b) << endl;
  }
}