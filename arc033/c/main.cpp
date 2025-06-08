#include <atcoder/fenwicktree>

#include "util/common.h"

int main() {
  size_t q;
  cin >> q;
  vector<pair<size_t, size_t>> txs(q);
  for (size_t i{0}; i < q; ++i) cin_pair(txs[i]);

  atcoder::fenwick_tree<int64_t> ft(200001);
  for (auto [t, x] : txs) {
    if (t == 1) {
      ft.add(x, 1);
    } else {
      size_t l{0}, r{200000};
      while (r - l > 1) {
        size_t mid{(r + l) / 2};
        if (ft.sum(0, mid + 1) < x) {
          l = mid;
        } else {
          r = mid;
        }
      }
      ft.add(r, -1);
      cout << r << endl;
    }
  }
}