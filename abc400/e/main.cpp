#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 q;
  cin >> q;

  vector<pair<s64, s64>> aip(q);
  for (s64 i{0}; i < q; ++i) {
    cin >> aip[i].first;
    aip[i].second = i;
  }
  sort(aip.begin(), aip.end());

  vector<s64> ps;
  constexpr auto p_max = 1000001;
  ps.reserve(p_max);
  vector<s64> is_p(p_max, true);
  for (s64 i{2}; i < p_max; ++i) {
    if (!is_p[i]) continue;
    ps.push_back(i);
    s64 val{i + i};
    while (val < p_max) {
      is_p[val] = false;
      val += i;
    }
  }

  vector<bool> valid(p_max, false);
  for (s64 i{0}; i < ps.size() - 1; ++i) {
    auto a{ps[i]};
    while (a < p_max) {
      for (s64 k{i + 1}; k < ps.size() && a * ps[k] < p_max; ++k) {
        auto b{ps[k]};
        while (a * b < p_max) {
          valid[a * b] = true;
          b *= ps[k];
        }
      }
      a *= ps[i];
    }
  }

  vector<s64> answers(q);

  s64 val{0};
  s64 val_max{0};
  for (const auto [a, idx] : aip) {
    while (val * val <= a) {
      if (valid[val]) val_max = val;
      ++val;
    }
    answers[idx] = val_max * val_max;
  }
  for (auto ans : answers) cout << ans << endl;
}