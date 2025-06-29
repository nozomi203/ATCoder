#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n);
  util::cin(abs);
  s64 cnt = 0;
  for (auto [a, b] : abs)
    if (a < b) ++cnt;
  cout << cnt << endl;
}