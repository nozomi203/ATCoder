#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n), bs(n);
  util::cin(as);
  util::cin(bs);

  map<s64, s64> cnts;
  for (s64 i = 0; i < n; ++i) ++cnts[as[i]];
  for (s64 i = 1; i < n; ++i) ++cnts[bs[i]];
  for (s64 i = 2; i < n; ++i) {
    as[i] = max(as[i], as[i - 1]);
    bs[i] = max(bs[i], bs[i - 1]);
  }

  {
    s64 j = 1;
    for (s64 i = 1; i < n; ++i) {
      while (j < n && as[i] >= bs[j]) ++j;
      cnts[as[i]] += j - 1;
    }
  }
  {
    s64 j = 1;
    for (s64 i = 1; i < n; ++i) {
      while (j < n && bs[i] > as[j]) ++j;
      cnts[bs[i]] += j - 1;
    }
  }
  s64 nmax = 0;
  s64 vmax = 0;
  for (auto [v, n] : cnts) {
    if (n >= nmax) {
      nmax = n;
      vmax = v;
    }
  }
  cout << vmax << " " << nmax << endl;
}