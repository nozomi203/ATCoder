#include "util/common.h"

int main() {
  size_t m, n;
  cin >> m >> n;
  vector<string> flag(m);
  util::cin(flag);
  vector<string> emb(2);
  util::cin(emb);

  const auto check = [&](size_t i, size_t j) -> bool {
    return flag[i][j] == emb[0][0] && flag[i + 1][j] == emb[1][0] &&
           flag[i][j + 1] == emb[0][1] && flag[i + 1][j + 1] == emb[1][1];
  };
  vector<vector<bool>> b(m, vector<bool>(n));
  int64_t cnt = 0;
  for (size_t i = 0; i < m - 1; ++i) {
    for (size_t j = 0; j < n - 1; ++j) {
      b[i][j] = check(i, j);
      if (b[i][j]) ++cnt;
    }
  }

  int64_t ans = 0;
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      char c = flag[i][j];

      int64_t tmp = 0;
      if (i > 0 && j > 0 && b[i - 1][j - 1]) --tmp;
      if (i > 0 && b[i - 1][j]) --tmp;
      if (j > 0 && b[i][j - 1]) --tmp;
      if (b[i][j]) --tmp;

      const auto cands = to_array({'J', 'O', 'I'});
      for (auto cand : cands) {
        int64_t tmp2 = 0;
        flag[i][j] = cand;
        if (i > 0 && j > 0 && check(i - 1, j - 1)) ++tmp2;
        if (i > 0 && j < n - 1 && check(i - 1, j)) ++tmp2;
        if (i < m - 1 && j > 0 && check(i, j - 1)) ++tmp2;
        if (i < m - 1 && j < n - 1 & check(i, j)) ++tmp2;
        ans = max(ans, cnt + tmp + tmp2);
      }
      flag[i][j] = c;
    }
  }
  cout << ans << endl;
}