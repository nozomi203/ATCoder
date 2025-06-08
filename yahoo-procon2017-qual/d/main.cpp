#include <atcoder/lazysegtree>

#include "util/common.h"
/*


*/

int main() {
  size_t q, k;
  cin >> q >> k;
  vector<tuple<size_t, size_t, size_t>> informations(q);
  for (size_t i{0}; i < q; ++i) {
    auto& [a, b, c] = informations[i];
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
    } else {
      cin >> b;
    }
  }

  vector<pair<size_t, size_t>> ccs;
  {
    for (auto [idx, d, a] : informations) {
      ccs.push_back(make_pair(d, 0));
    }
    sort(ccs.begin(), ccs.end());
    ccs.erase(unique(ccs.begin(), ccs.end()), ccs.end());
    for (size_t i{0}; i < ccs.size(); ++i) ccs[i].second = i;
    for (auto& [idx, d, a] : informations) {
      d = lower_bound(ccs.begin(), ccs.end(), d, [](const auto& cc, size_t v) {
            cc.first < v;
          })->second;
    }
  }

  struct work {
    size_t order;
    size_t cap;
  };

  vector<work> works(ccs.size());
  for (size_t i{0}; i < ccs.size(); ++i) {
    works[i].cap = 2 * ccs[i].first;
  }
}