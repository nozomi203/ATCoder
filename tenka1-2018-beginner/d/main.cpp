#include "util/common.h"

int main() {
  s64 n;
  cin >> n;

  if (n == 1) {
    cout << "Yes" << endl;
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  s64 m{-1};
  for (s64 i{1}; i <= n; ++i) {
    if (i * (i - 1) == 2 * n) {
      m = i;
      break;
    }
  }

  if (m < 0) {
    cout << "No" << endl;
    return 0;
  }
  vector<vector<s64>> ans(m, vector<s64>(m - 1));
  s64 not_used{1};
  for (s64 i{0}; i < m; ++i) {
    for (s64 j{0}; j < i; ++j) {
      ans[i][j] = ans[j][i - 1];
    }
    for (s64 j{i}; j < m - 1; ++j) {
      ans[i][j] = not_used++;
    }
  }

  cout << "Yes" << endl;
  cout << m << endl;
  for (s64 i{0}; i < m; ++i) {
    cout << m - 1 << " ";
    for (s64 j{0}; j < m - 1; ++j) {
      cout << ans[i][j];
      if (j < m - 2) cout << " ";
    }
    cout << endl;
  }
}