#include <atcoder/lazysegtree>

#include "util/common.h"
struct elem_t {
  s64 num_w{0};
  s64 num_b{0};
};

using lazysegtree =
    atcoder::lazy_segtree<elem_t,
                          [](elem_t s0, elem_t s1) -> elem_t {
                            return elem_t{s0.num_w + s1.num_w,
                                          s0.num_b + s1.num_b};
                          },
                          []() -> elem_t { return elem_t{}; }, optional<bool>,
                          [](optional<bool> f, elem_t s) -> elem_t {
                            return f ? elem_t{0, s.num_w + s.num_b} : s;
                          },
                          [](optional<bool> f0, optional<bool> f1)
                              -> optional<bool> { return f0 ? f0 : f1; },
                          []() -> optional<bool> { return nullopt; }>;

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> lrs(q);
  util::cin(lrs);

  map<s64, s64> idxs;
  idxs[n] = 0;
  idxs[n + 1] = 0;
  for (auto [l, r] : lrs) {
    idxs[l - 1] = 0;
    idxs[r] = 0;
  }

  {
    s64 idx = 0;
    for (auto& [k, v] : idxs) v = idx++;
  }
  vector<s64> nums(idxs.size());
  {
    s64 prev = 0;
    for (auto [k, v] : idxs) {
      nums[v] = k - prev;
      prev = k;
    }
  }

  vector<elem_t> elems(nums.size());
  for (s64 i = 0; i < nums.size(); ++i) {
    elems[i].num_w = nums[i];
    elems[i].num_b = 0;
  }
  lazysegtree lst(elems);
  for (auto [l, r] : lrs) {
    auto idxl = idxs[l - 1] + 1;
    auto idxr = idxs[r] + 1;
    lst.apply(idxl, idxr, true);
    elem_t e = lst.all_prod();
    cout << e.num_w - 1 << endl;
  }
}