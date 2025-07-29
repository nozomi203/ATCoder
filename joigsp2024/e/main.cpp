#include "util/common.h"

/*
カードi,jを選んでいくときに、
最大の得点を持つカードxと、カードxと異なる色の中で最大の得点を持つカードyを残して、
それ以外のカードをカードiとする。カードjはxyのうちカードiと異なる色のものを選ぶ。
Ai+Ajが正の場合は答えに足し、負の場合は足さない。
その後カードiの方を捨てる。
最後に、Ax+Ayを足して終わり。
 */

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> acs(n);
  util::cin(acs);

  const auto get = [&]() -> s64 {
    if (all_of(acs.begin(), acs.end(), [&](pair<s64, s64>& e) {
          return e.second == acs.front().second;
        })) {
      return 0;
    }
    sort(acs.begin(), acs.end());
    const size_t i1st = n - 1;
    size_t i2nd = n - 2;
    while (acs[i1st].second == acs[i2nd].second) --i2nd;

    s64 ans = acs[i1st].first + acs[i2nd].first;
    if (ans < 0) return 0;
    for (size_t i = 0; i < n; ++i) {
      if (i == i1st || i == i2nd) continue;
      s64 val =
          acs[i].first + (acs[i].second != acs[i1st].second ? acs[i1st].first
                                                            : acs[i2nd].first);

      if (val > 0) ans += val;
    }
    return ans;
  };

  cout << get() << endl;
}