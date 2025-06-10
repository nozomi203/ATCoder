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
  vector<tuple<int64_t, int64_t, int64_t>> informations(q);
  for (size_t i{0}; i < q; ++i) {
    auto& [a, b, c] = informations[i];
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
    } else {
      cin >> b;
    }
  }

  vector<pair<int64_t, size_t>> ccs;
  {
    for (auto [idx, d, a] : informations) {
      ccs.push_back(make_pair(d, 0));
    }
    sort(ccs.begin(), ccs.end());
    ccs.erase(unique(ccs.begin(), ccs.end()), ccs.end());
    for (size_t i{0}; i < ccs.size(); ++i) ccs[i].second = i;
    for (auto& [idx, d, a] : informations) {
      d = lower_bound(ccs.begin(), ccs.end(), d,
                      [](const pair<int64_t, size_t>& cc, int64_t v) {
                        return cc.first < v;
                      })
              ->second;
    }
  }

  struct work {
    int64_t order;
    int64_t capacity;
  };

  vector<work> works(ccs.size());
  for (size_t i{0}; i < q; ++i) {
    const auto& [idx, d, a] = informations[i];
    if (idx == 1) {
      works[d].order += a;
      works[d].capacity += a;
    }
  }

  struct op {
    int64_t diff_order;
    int64_t diff_capacity;
  };

  {
    /*
    全部の注文がそろった状態でcapacityを計算する。
    capacity = max(0, order - {その時点で残っている商品数})
    */
    size_t prod{0};
    for (size_t i{0}; i < ccs.size(); ++i) {
      prod += k * ((i > 0) ? ccs[i].first - ccs[i - 1].first : ccs[i].first);
      if (works[i].order >= prod) {
        works[i].capacity = works[i].order - prod;
        prod = 0;
      } else {
        works[i].capacity = 0;
        prod -= works[i].order;
      }
    }
  }

  atcoder::lazy_segtree<work,
                        [](const work& s0, const work& s1) -> work {
                          return work{s0.order + s1.order,
                                      s0.capacity + s1.capacity};
                        },
                        []() -> work { return work{0, 0}; }, op,
                        [](const op& f, const work& s) -> work {
                          work ret{s};
                          return work{
                              s.order + f.diff_order,
                              max<int64_t>(0, s.capacity + f.diff_capacity)};
                        },
                        [](const op& f0, const op& f1) -> op {
                          return op{f0.diff_order + f1.diff_order,
                                    f0.diff_capacity + f1.diff_capacity};
                        },
                        []() -> op { return op{0, 0}; }>
      lst(works);

  vector<size_t> answers;
  for (auto rit{informations.rbegin()}; rit != informations.rend(); ++rit) {
    const auto& [idx, d, a] = *rit;
    if (idx == 1) {
      // cancel order
      work w = lst.get(d);
      const int64_t rem = w.order - w.capacity;
      w.order = w.capacity = w.order - a;
      if (rem <= w.capacity) {
        w.capacity -= rem;
        lst.set(d, w);
      } else {
        lst.set(d, w);
        const size_t r = lst.max_right(
            d, [rem](const work& w) { return w.capacity <= rem; });
        const work w2 = lst.prod(d, r);
        lst.apply(d, r, op{0, -10000000000});
        if (r < works.size()) {
          work w3 = lst.get(r);
          w3.capacity -= rem - w2.capacity;
          lst.set(r, w3);
        }
      }
    } else {
      work w = lst.prod(0, d + 1);
      answers.push_back(w.order - w.capacity);
    }
  }

  for (auto rit{answers.rbegin()}; rit != answers.rend(); ++rit)
    cout << *rit << endl;
}