#include <string>

#include "util/common.h"
#include "util/rolling_hash.h"

int main() {
  string s, t;
  cin >> s >> t;
  const auto get = [&]() -> s64 {
    const uint64_t base{10007};
    util::rolling_hash srh(s, base), trh(t, base);

    const auto get_period = [](const string& s,
                               const util::rolling_hash& rh) -> size_t {
      const char c0{s.front()};
      if (all_of(s.begin(), s.end(), [c0](char c) { return c == c0; })) {
        return 1;
      }

      size_t pl{1};
      size_t pr{s.size()};
      while (pr - pl > 1) {
        size_t mid{(pl + pr) / 2};
      }
    };
  };

  cout << get() << endl;
}