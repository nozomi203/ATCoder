#include "util/common.h"

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n), bs(n);
  util::cin(as);
  util::cin(bs);
  vector<tuple<char, s64, s64>> cxvs(q);
  util::cin(cxvs);

  s64 sum = 0;
  for (s64 i = 0; i < n; ++i) sum += min(as[i], bs[i]);

  for (auto [c, x, v] : cxvs) {
    sum -= min(as[x - 1], bs[x - 1]);
    if (c == 'A') {
      as[x - 1] = v;
    } else {
      bs[x - 1] = v;
    }
    sum += min(as[x - 1], bs[x - 1]);

    cout << sum << endl;
  }
}