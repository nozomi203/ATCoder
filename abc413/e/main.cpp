#include <atcoder/math>

#include "util/common.h"
#include "util/sparse_table.h"

int main() {
  s64 t;
  cin >> t;
  vector<vector<s64>> pss(t);
  for (s64 i = 0; i < t; ++i) {
    s64 n;
    cin >> n;
    pss[i].resize(atcoder::pow_mod(2, n, 100000000));
    util::cin(pss[i]);
  }

  for (auto& ps : pss) {
    util::sparse_table<s64, [](s64 l, s64 r) { return min(l, r); }> st(ps);
    const auto print = [&](auto self, size_t l, size_t r) -> void {
      assert(r - l == bit_floor(r - l));
      if (r == l + 1) {
        cout << ps[l] << " ";
        return;
      }
      const size_t mid = (l + r) / 2;
      const s64 minl = st.query(l, mid - 1);
      const s64 minr = st.query(mid, r - 1);
      if (minl < minr) {
        self(self, l, mid);
        self(self, mid, r);
      } else {
        self(self, mid, r);
        self(self, l, mid);
      }
    };

    print(print, 0, ps.size());
    cout << endl;
  }
}