#include "util/common.h"

int main() {
  size_t k;
  cin >> k;
  string s;
  cin >> s;
  const size_t n = 1 << (2 * k);
  s = s + s;
  array<vector<size_t>, 3> cnts{
      vector<size_t>(n * 2, 0),
      vector<size_t>(n * 2, 0),
      vector<size_t>(n * 2, 0),
  };
  for (size_t i = 0; i < n * 2; ++i) {
    if (s[i] == 'J') {
      ++cnts[0][i];
    } else if (s[i] == 'O') {
      ++cnts[1][i];
    } else if (s[i] == 'I') {
      ++cnts[2][i];
    }
    if (i > 0) {
      cnts[0][i] += cnts[0][i - 1];
      cnts[1][i] += cnts[1][i - 1];
      cnts[2][i] += cnts[2][i - 1];
    }
  }

  const auto get_cnt = [&](const auto& self, size_t idx, size_t l) -> size_t {
    if (l == 0) return 0;
    const size_t sz = 1 << (2 * (l - 1));
    const size_t cntj =
        sz - (cnts[0][idx + sz * 1 - 1] - cnts[0][idx + sz * 0] +
              (s[idx + sz * 0] == 'J' ? 1 : 0));
    const size_t cnto =
        sz - (cnts[1][idx + sz * 2 - 1] - cnts[1][idx + sz * 1] +
              (s[idx + sz * 1] == 'O' ? 1 : 0));
    const size_t cnti =
        sz - (cnts[2][idx + sz * 3 - 1] - cnts[2][idx + sz * 2] +
              (s[idx + sz * 2] == 'I' ? 1 : 0));
    const size_t cnt = self(self, idx + sz * 3, l - 1);
    return cntj + cnto + cnti + cnt;
  };

  size_t ans = numeric_limits<size_t>::max();
  for (size_t i = 0; i < n; ++i) {
    ans = min(ans, get_cnt(get_cnt, i, k));
  }
  cout << ans << endl;
}