#include <atcoder/segtree>

#include "util/common.h"

/*

*/

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n);
  util::cin(as);
  vector<tuple<s64, s64, s64>> queries(q);
  util::cin(queries);

  map<s64, s64> val_to_idx;
  for (auto a : as) val_to_idx.emplace(a, 0);

  for (auto [q0, q1, q2] : queries) {
    if (q0 == 1) val_to_idx.emplace(q2, 0);
  }

  {
    s64 i = 0;
    for (auto& [val, idx] : val_to_idx) idx = i++;
  }
  using segtree =
      atcoder::segtree<s64, [](s64 s0, s64 s1) -> s64 { return s0 + s1; },
                       []() -> s64 { return 0; }>;

  segtree lst_val(val_to_idx.size()), lst_num(val_to_idx.size());
  for (auto a : as) {
    const s64 idx = val_to_idx[a];
    lst_val.set(idx, lst_val.get(idx) + a);
    lst_num.set(idx, lst_num.get(idx) + 1);
  }

  for (auto [q0, q1, q2] : queries) {
    if (q0 == 1) {
      auto val0 = as[q1 - 1];
      auto idx0 = val_to_idx[val0];
      auto idx1 = val_to_idx[q2];
      lst_val.set(idx0, lst_val.get(idx0) - val0);
      lst_val.set(idx1, lst_val.get(idx1) + q2);
      lst_num.set(idx0, lst_num.get(idx0) - 1);
      lst_num.set(idx1, lst_num.get(idx1) + 1);
      as[q1 - 1] = q2;
    } else {
      const auto get = [&]() -> s64 {
        if (q1 >= q2) return q1 * n;

        auto itl = val_to_idx.lower_bound(q1);
        auto itr = val_to_idx.lower_bound(q2);
        auto idxl = itl == val_to_idx.end() ? val_to_idx.size() : itl->second;
        auto idxr = itr == val_to_idx.end() ? val_to_idx.size() : itr->second;

        s64 ret = lst_val.prod(idxl, idxr);
        if (idxl > 0) {
          s64 num = lst_num.prod(0, idxl);
          ret += q1 * num;
        }
        if (idxr < val_to_idx.size()) {
          s64 num = lst_num.prod(idxr, val_to_idx.size());
          ret += q2 * num;
        }
        return ret;
      };
      cout << get() << endl;
    }
  }
}
