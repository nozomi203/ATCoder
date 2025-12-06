#include "util/common.h"

int main() {
  s64 n, r;
  cin >> n >> r;
  vector<s64> ls(n + 1);
  util::cin(ls.begin() + 1, ls.end());
  s64 ans = 0;
  bool has_open = false;
  for (s64 i = 1; i <= r; ++i) {
    if (ls[i] == 0) {
      has_open = true;
      ans += 1;
    } else {
      if (has_open) {
        ans += 2;
      }
    }
  }
  has_open = false;
  for (s64 i = n; i > r; --i) {
    if (ls[i] == 0) {
      has_open = true;
      ans += 1;
    } else {
      if (has_open) ans += 2;
    }
  }

  cout << ans << endl;
}