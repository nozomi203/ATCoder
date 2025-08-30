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
    auto [drt, dct] = get_drc(s, min(a, b));
    auto [dra, dca] = get_drc(t, min(a, b));

    if (drt == dra && dct == dca) {
      if () } else {
    }

    rt += drt;
    ct += dct;
    ra += dra;
    ca += dca;

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