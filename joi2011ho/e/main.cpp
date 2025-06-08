#include <atcoder/fenwicktree>

#include "util/common.h"
int main() {
  size_t n;
  cin >> n;
  vector<pair<s64, s64>> ai(n), bi(n);
  for (size_t i{0}; i < n; ++i) {
    cin >> ai[i].first;
    cin >> bi[i].first;
    ai[i].second = i;
  }
  sort(ai.begin(), ai.end());
  for (size_t i{0}; i < n; ++i) bi[ai[i].second].second = i;
  sort(bi.begin(), bi.end());

  atcoder::fenwick_tree<s64> ft_suma(n), ft_counta(n);
  for (size_t i{0}; i < n; ++i) {
    ft_suma.add(i, ai[i].first);
    ft_counta.add(i, 1);
  }
  s64 ans{0};
  for (const auto [b, i] : bi) {
    const auto a{ai[i].first};
    ft_suma.add(i, -a);
    ft_counta.add(i, -1);

    const auto check = [&](size_t r) -> pair<bool, s64> {
      const s64 counta{ft_counta.sum(0, r) + 1};
      const s64 suma{ft_suma.sum(0, r) + a};
      return {suma <= counta * b, counta};
    };
    const auto get_value = [&](size_t r) -> s64 {
      const s64 counta{ft_counta.sum(0, r) + 1};
      const s64 suma{ft_suma.sum(0, r) + a};
      return suma - counta * b;
    };

    size_t nl{0}, nr{n - 1};

    {
      size_t nll{0}, nlr{n - 1};
      while (true) {
        const size_t nlmidl{(nll * 2 + nlr) / 3}, nlmidr{(nll + 2 * nlr) / 3};
        const s64 v0{get_value(nlmidl + 1)}, v1{get_value(nlmidr + 1)};
        if (v0 < v1) {
          if (nlr == nlmidr) break;
          nlr = nlmidr;
        } else {
          if (nll == nlmidl) break;
          nll = nlmidl;
        }
      }
      nl = get_value(nll + 1) < get_value(nlr + 1) ? nll : nlr;
    }

    if (const auto [possible, counta] = check(nl + 1); !possible) {
      continue;
    }

    if (const auto [possible, counta] = check(n); possible) {
      ans = max(ans, counta);
      continue;
    }

    while (nr - nl > 1) {
      const size_t nmid{(nr + nl) / 2};
      if (const auto [possible, counta] = check(nmid + 1); possible) {
        nl = nmid;
      } else {
        nr = nmid;
      }
    }
    ans = max(ans, ft_counta.sum(0, nl + 1) + 1);
  }
  cout << ans << endl;
}