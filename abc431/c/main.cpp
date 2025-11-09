#include "util/common.h"

int main() {
  s64 n, m, k;
  cin >> n >> m >> k;
  vector<s64> hs(n), bs(m);
  util::cin(hs);
  util::cin(bs);

  sort(hs.begin(), hs.end());
  sort(bs.begin(), bs.end());

  const auto check = [&]() -> bool {
    s64 j = 0;
    for (s64 i = 0; i < k; ++i) {
      const s64 h = hs[i];
      while (j < m && hs[i] > bs[j]) ++j;
      if (j >= m) return false;
      ++j;
    }
    return true;
  };

  cout << (check() ? "Yes" : "No") << endl;
}