#include "util/common.h"
#include "util/sparse_table.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n + 2);
  vector<s64> bs(n + 1);
  util::cin(as.begin() + 1, as.end());
  util::cin(bs.begin() + 1, bs.end());
  vector<pair<s64, s64>> ais(n + 2);
  for (s64 i = 0; i <= n + 1; ++i) {
    ais[i].first = as[i];
    ais[i].second = i;
  }
  sort(ais.begin() + 1, ais.end());
  sort(bs.begin() + 1, bs.end());
  vector<s64> o0(n + 2), o1(n + 2);
  for (s64 i = 1; i <= n; ++i) {
    o0[i] = max<s64>(ais[i].first - bs[i], 0);
    o1[i] = max<s64>(ais[i + 1].first - bs[i], 0);
  }
  util::sparse_table<s64, [](s64 a, s64 b) { return max(a, b); }> st0(o0),
      st1(o1);

  vector<s64> anss(n + 2);
  for (s64 i = 1; i <= n + 1; ++i) {
    anss[ais[i].second] = max(st0.query(0, i - 1), st1.query(i, n + 1));
  }

  for (s64 i = 1; i <= n + 1; ++i) {
    cout << anss[i];
    if (i <= n) cout << " ";
  }
  cout << endl;
}