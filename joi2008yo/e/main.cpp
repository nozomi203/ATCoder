#include "util/common.h"

int main() {
  s64 r, c;
  cin >> r >> c;
  vector<vector<bool>> table(r, vector<bool>(c));
  for (s64 i{0}; i < r; ++i) {
    for (s64 j{0}; j < c; ++j) {
      s64 a;
      cin >> a;
      table[i][j] = a;
    }
  }

  s64 ans{0};
  for (s64 b{0}; b < (1 << r); ++b) {
    s64 val{0};
    for (s64 i{0}; i < c; ++i) {
      s64 cnt{0};
      for (s64 j{0}; j < r; ++j) {
        if (b & (1 << j)) {
          if (table[j][i]) ++cnt;
        } else {
          if (!table[j][i]) ++cnt;
        }
      }
      val += max(cnt, r - cnt);
    }
    ans = max(ans, val);
  }
  cout << ans << endl;
}