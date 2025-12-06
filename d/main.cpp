#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64, s64>> udlrs(n);
  util::cin(udlrs);

  vector<vector<pair<s64, s64>>> imoss(2002, vector<pair<s64, s64>>(2002));

  for (s64 i = 0; i < n; ++i) {
    auto [u, d, l, r] = udlrs[i];
    imoss[u][l].first += (i + 1);
    imoss[u][l].second++;
    imoss[d + 1][r + 1].first += (i + 1);
    imoss[d + 1][r + 1].second++;
    imoss[u][r + 1].first -= (i + 1);
    imoss[u][r + 1].second--;
    imoss[d + 1][l].first -= (i + 1);
    imoss[d + 1][l].second--;
  }

  for (s64 i = 0; i < 2002; ++i) {
    for (s64 j = 1; j < 2002; ++j) {
      imoss[i][j].first += imoss[i][j - 1].first;
      imoss[i][j].second += imoss[i][j - 1].second;
    }
  }
  for (s64 j = 0; j < 2002; ++j) {
    for (s64 i = 1; i < 2002; ++i) {
      imoss[i][j].first += imoss[i - 1][j].first;
      imoss[i][j].second += imoss[i - 1][j].second;
    }
  }

  vector<s64> cnts(n + 1);

  for (s64 i = 1; i <= 2000; ++i) {
    for (s64 j = 1; j <= 2000; ++j) {
      if (imoss[i][j].second == 0) {
        cnts[0]++;
      }
      if (imoss[i][j].second == 1) {
        cnts[imoss[i][j].first]++;
      }
    }
  }

  for (s64 i = 1; i <= n; ++i) {
    cout << cnts[0] + cnts[i] << endl;
  }
}