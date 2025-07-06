#include "util/common.h"
/*

1 2 3 4 5 6 7 8 9
10 11 12
13
0 1 2 3 4 5 6 7 8 depth 2
9 10 11 depth 1
12 depth 0

総数: 3^(n+1)-1 / (3-1) = 26 / 2 = 13
*/

s64 pow(s64 i, s64 j) {
  if (j == 0) return 1;
  return i * pow(i, j - 1);
}

int main() {
  s64 n, q;
  cin >> n >> q;
  string t;
  cin >> t;
  vector<s64> ps(q);
  util::cin(ps);

  vector<s64> cnts(n + 1);
  {
    cnts[0] = 1;
    for (s64 i = 1; i <= n; ++i) {
      cnts[i] = cnts[i - 1] * 3;
    }
  }
  vector<s64> sum_cnts(n + 1);
  sum_cnts[0] = cnts[0];
  for (s64 i = 1; i <= n; ++i) {
    sum_cnts[i] = sum_cnts[i - 1] + cnts[i];
  }

  const size_t nc = (pow(3, n + 1) - 1) / 2;
  vector<char> ds(nc);
  vector<s64> idxs(nc);
  {
    s64 offset = 0;
    for (s64 d = 0; d <= n; ++d) {
      for (s64 i = 0; i < cnts[d]; ++i) {
        ds[i + offset] = d;
        idxs[i + offset] = i;
      }
      offset += cnts[d];
    }
  }

  const auto get_parent = [&](s64 i) -> s64 {
    if (i == 0) return -1;
    if (ds[i] == 1) return 0;
    s64 d = ds[i] - 1;
    s64 idx = idxs[i] / 3;
    return sum_cnts[d - 1] + idx;
  };

  const auto get_child = [&](s64 i) -> s64 {
    if (ds[i] == n) return -1;
    s64 d = ds[i] + 1;
    s64 idx = idxs[i] * 3;
    return sum_cnts[d - 1] + idx;
  };

  vector<char> cs(nc);
  for (s64 i = 0; i < pow(3, n); ++i) cs[sum_cnts[n - 1] + i] = t[i];
  for (s64 i = nc - pow(3, n) - 1; i >= 0; --i) {
    s64 cnta = 0;
    if (cs[get_child(i) + 0] == 'A') ++cnta;
    if (cs[get_child(i) + 1] == 'A') ++cnta;
    if (cs[get_child(i) + 2] == 'A') ++cnta;
    cs[i] = cnta > 1 ? 'A' : 'B';
  }

  for (auto p : ps) {
    s64 i = sum_cnts[n - 1] + p - 1;
    cs[i] = cs[i] == 'A' ? 'B' : 'A';
    s64 par = get_parent(i);
    while (par >= 0) {
      s64 cnta = 0;
      if (cs[get_child(par) + 0] == 'A') ++cnta;
      if (cs[get_child(par) + 1] == 'A') ++cnta;
      if (cs[get_child(par) + 2] == 'A') ++cnta;
      cs[par] = cnta > 1 ? 'A' : 'B';
      par = get_parent(par);
    }
    cout << cs[0] << endl;
  }
}