#include "util/common.h"

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<size_t> as(n), bs(n);
  util::cin(as);
  util::cin(bs);
  for (size_t i = 0; i < n; ++i)
    if (as[i] < bs[i]) as[i] = bs[i]; /*自習したほうがまだましな授業*/

  /* すべての教科の理解度をv以上にできるか */
  const auto check = [&](size_t v) -> bool {
    size_t cap = 0;
    size_t nd = 0;
    for (size_t i = 0; i < n; ++i) {
      const auto a = as[i];
      const auto b = bs[i];
      size_t val = (v + a - 1) / a;
      if (val <= m) {
        cap += m - val;
      } else {
        size_t rem = v - a * m;
        nd += (rem + b - 1) / b;
      }
    }
    return nd <= cap;
  };

  /* すべての教科の理解度をv以上にできるかを2分探索でチェック */
  s64 vl = 0, vr = 1000000000000000001;
  while (vr - vl > 1) {
    s64 v = (vr + vl) / 2;
    if (check(v)) {
      vl = v;
    } else {
      vr = v;
    }
  }

  cout << vl << endl;
}