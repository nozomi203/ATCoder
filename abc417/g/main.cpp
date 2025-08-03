#include "util/common.h"

int main() {
  size_t q;
  cin >> q;
  vector<tuple<size_t, size_t, size_t>> lrxs(q);
  util::cin(lrxs);

  constexpr size_t xmax = 1e+18;
  constexpr size_t logxmax = countr_zero(bit_ceil(xmax));

  vector<pair<s64, s64>> lgts(q + 2, make_pair(-1, -1));
  vector<vector<pair<s64, s64>>> hvys(
      q + 2, vector<pair<s64, s64>>(logxmax + 1, make_pair(-1, -1)));

  vector<size_t> lens(q + 2);
  lens[0] = 1;
  lens[1] = 1;

  for (size_t i = 0; i < q; ++i) {
    const auto [l, r, x] = lrxs[i];

    const size_t len = min(lens[l] + lens[r], xmax);
    lens[i + 2] = len;

    if (lens[l] < lens[r]) {
      lgts[i + 2] = make_pair(l, 0);
      hvys[i + 2][0] = make_pair(r, lens[l]);
    } else {
      lgts[i + 2] = make_pair(r, lens[l]);
      hvys[i + 2][0] = make_pair(l, 0);
    }
    for (s64 j = 1; j <= logxmax; ++j) {
      const auto [a0, b0] = hvys[i + 2][j - 1];
      if (a0 == -1) break;
      const auto [a1, b1] = hvys[a0][j - 1];
      if (a1 == -1) break;
      if (b0 + b1 > xmax) break;
      hvys[i + 2][j] = make_pair(a1, b0 + b1);
    }

    s64 a = i + 2;
    s64 b = x - 1;
    while (a > 1) {
      for (s64 j = logxmax; j >= 0; --j) {
        const auto [tmpa, tmpb] = hvys[a][j];
        if (tmpa == -1) continue;
        if (tmpb > b || b > tmpb + lens[tmpa] - 1) continue;
        a = tmpa;
        b -= tmpb;
        break;
      }
      while (a > 1) {
        const auto [tmpa, tmpb] = lgts[a];
        if (tmpa == -1) break;
        if (tmpb > b || b > tmpb + lens[tmpa] - 1) break;
        a = tmpa;
        b -= tmpb;
      }
    }
    cout << a << endl;
  }
}