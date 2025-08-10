#include "util/common.h"

int main() {
  string s;
  cin >> s;
  const auto get = [&](size_t l, size_t r) -> pair<size_t, size_t> {
    if (s[l] != 't' || s[r] != 't') return make_pair(0, 1);
    size_t cnt = 0;
    for (size_t i = l; i <= r; ++i)
      if (s[i] == 't') ++cnt;
    if (cnt < 3) return make_pair(0, 1);
    return make_pair(cnt - 2, r - l - 1);
  };

  size_t maxnumer{0}, maxdenom{1};
  for (size_t i = 0; i < s.size() - 1; ++i) {
    for (size_t j = i; j <= s.size(); ++j) {
      auto [numer, denom] = get(i, j);

      if (maxnumer * denom < numer * maxdenom) {
        maxnumer = numer;
        maxdenom = denom;
      }
    }
  }
  cout << fixed << setprecision(15) << maxnumer / (double)maxdenom << endl;
}