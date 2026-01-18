#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 n;
  cin >> n;
  vector<s64> ts(n);
  util::cin(ts);
  vector<pair<s64, s64>> tis(n);
  for (s64 i = 0; i < n; ++i) {
    tis[i].first = ts[i];
    tis[i].second = i + 1;
  }
  sort(tis.begin(), tis.end());
  cout << tis[0].second << " " << tis[1].second << " " << tis[2].second << endl;
}