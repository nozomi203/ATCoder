#include "util/common.h"

int main() {
  s64 n, q, s, t;
  cin >> n >> q >> s >> t;
  vector<s64> as(n + 1);
  util::cin(as);
  vector<tuple<s64, s64, s64>> lrxs(q);
  util::cin(lrxs);

  vector<s64> das(n + 1);
  for (s64 i = 1; i <= n; ++i) das[i] = as[i] - as[i - 1];

  int64_t temp = 0;
  for (auto da : das) temp -= da * (da > 0 ? s : t);

  for (auto [l, r, x] : lrxs) {
    temp += das[l] * (das[l] > 0 ? s : t);
    das[l] += x;
    temp -= das[l] * (das[l] > 0 ? s : t);
    if (r < n) {
      temp += das[r + 1] * (das[r + 1] > 0 ? s : t);
      das[r + 1] -= x;
      temp -= das[r + 1] * (das[r + 1] > 0 ? s : t);
    }
    cout << temp << endl;
  }
}