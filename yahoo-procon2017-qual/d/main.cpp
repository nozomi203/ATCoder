#include <atcoder/lazysegtree>

#include "util/common.h"
/*
より期日の早い注文に対してgreedyに商品を販売する
今までの注文のうち一番早い期日がDiだったとき、それよりも早い期日Djが来た時の再計算がネック
Djを優先的に考えつつ、今までの注文が条件を満たしているかを考える必要がある
逆順で考えてみる。最初にすべての注文が分かっていて、そこからキャンセルが出ることを考える
(Di
Ai)の注文がキャンセルされた場合それ以降の期日でAiの余裕が出る。この余裕を分配する。

例
注文 03 00 05
生産 02 04 06
販売 02 00 04
余り 00 02 00
追加 01 00 01

1日目の注文03がキャンセルされたら
注文 00 00 05
生産 02 04 06
販売 00 00 05
余り 02 04 01
追加 00 00 00

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