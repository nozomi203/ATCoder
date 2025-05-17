#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> p(n);
  for (s64 i{0}; i < n; ++i) cin >> p[i];

  vector<array<s64, 4>> cnts(n);
  for (s64 i{1}; i < n; ++i) {
    cnts[i][0] = p[i] < p[i - 1] ? cnts[i - 1][0] + 1 : 0;
    cnts[i][1] = p[i] > p[i - 1] ? cnts[i - 1][1] + 1 : 0;
  }
  for (s64 i{n - 2}; i >= 0; --i) {
    cnts[i][2] = p[i] < p[i + 1] ? cnts[i + 1][2] + 1 : 0;
    cnts[i][3] = p[i] > p[i + 1] ? cnts[i + 1][3] + 1 : 0;
  }

  s64 ans{0};
  for (s64 i{0}; i < n; ++i) {
    if (cnts[i][1] == 0) continue;
    if (cnts[i][3] == 0) continue;
    if (cnts[i + cnts[i][3]][2] == 0) continue;
    s64 inc{cnts[i][1] * cnts[i + cnts[i][3]][2]};
    ans += inc;
  }
  cout << ans << endl;
}