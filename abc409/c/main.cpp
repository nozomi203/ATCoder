#include "util/common.h"

/*
abcはl/3ずつ離れている必要がある
*/

int main() {
  size_t n, l;
  cin >> n >> l;
  vector<size_t> ds(n - 1);
  for (size_t i{0}; i < n - 1; ++i) cin >> ds[i];

  const auto get = [&]() -> size_t {
    vector<size_t> cnts(l);
    cnts[0] = 1;
    size_t pos{0};
    for (size_t i{0}; i < n - 1; ++i) {
      pos = (pos + ds[i]) % l;
      ++cnts[pos];
    }

    if (l % 3) return 0;

    size_t ret{0};
    for (size_t i{0}; i < l / 3; ++i)
      ret += cnts[i] * cnts[i + l / 3] * cnts[i + 2 * l / 3];

    return ret;
  };

  cout << get() << endl;
}