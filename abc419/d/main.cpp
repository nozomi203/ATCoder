#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<pair<s64, s64>> lrs(m);
  util::cin(lrs);

  vector<s64> imos(n);
  for (auto [l, r] : lrs) {
    ++imos[l - 1];
    if (r < n) --imos[r];
  }
  for (s64 i = 0; i < n; ++i) {
    cout << (imos[i] % 2 ? t[i] : s[i]);
    if (i < n - 1) imos[i + 1] += imos[i];
  }
  cout << endl;
}