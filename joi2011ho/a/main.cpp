#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 m, n;
  cin >> m >> n;
  s64 k;
  cin >> k;
  using joi = array<s64, 3>;
  vector<vector<joi>> cum(m + 1, vector<joi>(n + 1));
  for (s64 i{1}; i <= m; ++i) {
    string s;
    cin >> s;
    for (s64 j{1}; j <= n; ++j) {
      if (s[j - 1] == 'J') {
        ++cum[i][j][0];
      } else if (s[j - 1] == 'O') {
        ++cum[i][j][1];
      } else {
        ++cum[i][j][2];
      }
      for (s64 l{0}; l < 3; ++l)
        cum[i][j][l] +=
            cum[i - 1][j][l] + cum[i][j - 1][l] - cum[i - 1][j - 1][l];
    }
  }
  vector<tuple<s64, s64, s64, s64>> q(k);
  for (s64 i{0}; i < k; ++i)
    cin >> get<0>(q[i]) >> get<1>(q[i]) >> get<2>(q[i]) >> get<3>(q[i]);

  for (auto [a, b, c, d] : q) {
    for (s64 i{0}; i < 3; ++i) {
      cout << cum[c][d][i] - cum[a - 1][d][i] - cum[c][b - 1][i] +
                  cum[a - 1][b - 1][i];
      if (i < 2) cout << " ";
    }
    cout << endl;
  }
}