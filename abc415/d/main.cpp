#include "util/common.h"

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<size_t, size_t>> abs(m);
  util::cin(abs);
  sort(abs.begin(), abs.end(), [](const auto& l, const auto& r) {
    return l.first - l.second < r.first - r.second;
  });

  size_t ans = 0;
  for (auto [a, b] : abs) {
    if (n >= a) {
      const size_t cnt = (n - a) / (a - b) + 1;
      ans += cnt;
      n -= cnt * (a - b);
    }
  }

  cout << ans << endl;
}