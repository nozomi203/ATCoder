#include <atcoder/string>

#include "util/common.h"
#include "util/rolling_hash.h"

int main() {
  s64 t;
  cin >> t;
  vector<pair<string, string>> abs(t);
  util::cin(abs);

  for (auto [a, b] : abs) {
    const auto get = [&]() -> s64 {
#if 0
      const string s = a + a + b;
      util::rolling_hash rh(s);
      for (s64 i = 0; i < b.size(); ++i) {
        const auto ha = rh.get_hash(i, i + b.size());
        const auto hb = rh.get_hash(2 * b.size(), 3 * b.size());
        if (ha == hb) return i;
      }
      return -1;
#endif
      const string s = b + a + a;
      const auto lcps = atcoder::z_algorithm(s);

      for (s64 i = b.size(); i < 2 * b.size(); ++i) {
        if (lcps[i] >= b.size()) return i - b.size();
      }
      return -1;
    };

    cout << get() << endl;
  }
}