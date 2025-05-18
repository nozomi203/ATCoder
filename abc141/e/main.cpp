#include "util/common.h"
#include "util/rolling_hash.h"

int main() {
  size_t n;
  string s;
  cin >> n >> s;
  util::rolling_hash rh(s);
  const auto get = [&]() -> size_t {
    {
      bool b{false};
      for (size_t i{0}; i < n - 1; ++i) {
        for (size_t j{i + 1}; j < n; ++j) {
          if (s[i] == s[j]) {
            b = true;
            break;
          }
        }
        if (b) break;
      }
      if (!b) return 0;
    }
    size_t l{1}, r{n};
    while (r - l > 1) {
      size_t mid{(r + l) / 2};
      bool b{false};
      for (size_t i{0}; i + mid <= n; ++i) {
        for (size_t j{i + mid}; j + mid <= n; ++j) {
          const auto hi{rh.get_hash(i, i + mid)};
          const auto hj{rh.get_hash(j, j + mid)};
          if (hi == hj) {
            b = true;
            break;
          }
        }
        if (b) break;
      }
      if (b) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  };
  cout << get() << endl;
}