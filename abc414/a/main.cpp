#include "util/common.h"

int main() {
  s64 n, l, r;
  cin >> n >> l >> r;
  vector<pair<s64, s64>> xys(n);
  util::cin(xys);
  s64 cnt = 0;
  for (auto [x, y] : xys) {
    if (x <= l && r <= y) ++cnt;
  }
  cout << cnt << endl;
}