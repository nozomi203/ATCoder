#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<char, u64>> cls(n);
  util::cin(cls);

  u64 len = 0;
  for (auto [c, l] : cls) {
    if (l > 100 || len + l > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
    len += l;
  }

  for (auto [c, l] : cls) {
    cout << string(l, c);
  }
  cout << endl;
}