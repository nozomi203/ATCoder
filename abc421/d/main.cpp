#include "util/common.h"

pair<s64, s64> get_drc(char c, s64 s) {
  if (c == 'R') return {0, s};
  if (c == 'L') return {0, -s};
  if (c == 'U') return {-s, 0};
  if (c == 'D') return {s, 0};
  assert(false);
  return {0, 0};
}

int main() {
  s64 rt, ct, ra, ca;
  cin >> rt >> ct >> ra >> ca;
  s64 n, m, l;
  cin >> n >> m >> l;
  vector<pair<char, s64>> sas(m), tbs(l);
  util::cin(sas);
  util::cin(tbs);

  s64 ans = 0;

  s64 it = 0, ia = 0;
  while (it < m && ia < l) {
    auto [s, a] = sas[it];
    auto [t, b] = tbs[ia];
    auto [drt, dct] = get_drc(s, 1);
    auto [dra, dca] = get_drc(t, 1);

    if (drt == dra && dct == dca) {
      if (rt == ra && ct == ca) {
        ans += min(a, b);
      }
    } else if (drt == dra) {
      if (rt == ra && (ct - ca) % (dct - dca) == 0) {
        const s64 x = -(ct - ca) / (dct - dca);
        if (x <= min(a, b) && x >= 1) {
          ans++;
        }
      }
    } else if (dct == dca) {
      if (ct == ca && (rt - ra) % (drt - dra) == 0) {
        const s64 x = -(rt - ra) / (drt - dra);
        if (x <= min(a, b) && x >= 1) {
          ans++;
        }
      }
    } else {
      if ((rt - ra) % (drt - dra) == 0 && (ct - ca) % (dct - dca) == 0) {
        const s64 x0 = -(rt - ra) / (drt - dra);
        const s64 x1 = -(ct - ca) / (dct - dca);
        if (x0 == x1 && x0 <= min(a, b) && x0 >= 1) {
          ans++;
        }
      }
    }
    rt += drt * min(a, b);
    ct += dct * min(a, b);
    ra += dra * min(a, b);
    ca += dca * min(a, b);

    if (a < b) {
      ++it;
      tbs[ia].second -= a;
    } else {
      ++ia;
      sas[it].second -= b;
    }
  }

  cout << ans << endl;
}