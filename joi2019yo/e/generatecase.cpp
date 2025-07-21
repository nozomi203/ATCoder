#include "util/common.h"

int main() {
  constexpr auto num_case = 10;
  for (size_t i = 0; i < num_case; ++i) {
    const string fname_in = format("tests/sample_random_{}.in", i);
    const string fname_out = format("tests/sample_random_{}.out", i);

    ofstream fin(fname_in), fout(fname_out);

    constexpr size_t n = 5;
    constexpr size_t m = 5;

    random_device dev;
    mt19937 mt(dev());

    uniform_int_distribution<size_t> dista(1, 10), distlr(1, n);

    vector<size_t> as(n);
    for (size_t i = 0; i < n; ++i) {
      as[i] = dista(mt);
    }
    vector<pair<s64, s64>> lrs(m);
    for (size_t i = 0; i < m; ++i) {
      lrs[i].first = distlr(mt);
      lrs[i].second = distlr(mt);
      if (lrs[i].first > lrs[i].second) swap(lrs[i].first, lrs[i].second);
    }
    fin << n << " " << m << endl;
    for (size_t i = 0; i < n; ++i) {
      fin << as[i];
      if (i < n - 1) fin << " ";
    }
    fin << endl;
    for (size_t i = 0; i < m; ++i) {
      fin << lrs[i].first << " " << lrs[i].second << endl;
    }

    {
      size_t ans = 0;
      for (size_t mask = 0; mask < 1 << n; ++mask) {
        bool invalid = false;
        for (auto [l, r] : lrs) {
          size_t cnt = 0;
          for (size_t i = l - 1; i <= r - 1; ++i) {
            if (mask & (1 << i)) ++cnt;
          }
          if (cnt > 1) {
            invalid = true;
            break;
          }
        }
        if (invalid) continue;

        size_t val = 0;
        for (size_t i = 0; i < n; ++i) {
          if (!(mask & (1 << i))) continue;
          val += as[i];
        }
        ans = max(ans, val);
      }

      fout << ans << endl;
    }
  }
}