#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<vector<s64>> table(n, vector<s64>(n));
  s64 r = 0;
  s64 c = (n - 1) / 2;
  s64 k = 1;
  table[r][c] = k;
  for (s64 i = 0; i < n * n - 1; ++i) {
    if (table[(r - 1 + n) % n][(c + 1) % n] == 0) {
      r = (r - 1 + n) % n;
      c = (c + 1) % n;
    } else {
      r = (r + 1) % n;
      c = c;
    }
    ++k;
    table[r][c] = k;
  }

  for (s64 i = 0; i < n; ++i) {
    for (s64 j = 0; j < n; ++j) {
      cout << table[i][j];
      if (j < n - 1) cout << " ";
    }
    cout << endl;
  }
}