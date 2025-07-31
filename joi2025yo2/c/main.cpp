#include "util/common.h"

/*
aを固定する。
bも固定したとき、
cはcmin cmaxのうちスコアが高くなる方
*/

int main() {
  s64 x, y, z, p;
  cin >> x >> y >> z >> p;
  vector<s64> as(x), bs(y), cs(z);
  util::cin(as);
  util::cin(bs);
  util::cin(cs);
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  sort(cs.begin(), cs.end());
  const s64 bmin = bs.front();
  const s64 bmax = bs.back();
  const s64 cmin = cs.front();
  const s64 cmax = cs.back();

  s64 ans = 0;
  for (auto a : as) {
    const float t = p - a - (cmin + cmax) / 2;
    if (bs[0] >= t) {
      ans = max(ans, cmax + a - p + bs[0]);
    } else if (bs[y - 1] < t) {
      ans = max(ans, -cmin - a + p - bs[y - 1]);
    } else {
      s64 ibl = 0;
      s64 ibr = y - 1;
      while (ibr - ibl > 1) {
        const s64 ib = (ibl + ibr) / 2;
        if (bs[ib] >= t) {
          ibr = ib;
        } else {
          ibl = ib;
        }
      }
      const s64 vl = -cmin - a + p - bs[ibl];
      const s64 vr = cmax + a - p + bs[ibr];
      ans = max(ans, min(vl, vr));
    }
  }
  cout << ans << endl;
}